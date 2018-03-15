#ifndef GAMESPAKS_CERTIFICATE_STORE_HPP
#define GAMESPAKS_CERTIFICATE_STORE_HPP

#if defined(WIN32)
#	include <Windows.h>
#	if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#		include <Wincrypt.h>
#		pragma comment(lib, "Crypt32.lib")
#	endif
#endif

#if !defined(IW_SDK)
#	include <mutex>
#endif

namespace GameSparks { namespace Util {
	class CertificateStore
	{
		public:

			/// an implementation is expected to call mbedtls_ssl_conf_ca_chain() with CA certs and CRLs
			/// retrieved from the OS. After that it is expected to call mbedtls_ssl_conf_authmode(&conf, MBEDTLS_SSL_VERIFY_REQUIRED);
			/// if the implementation does not do that, the SSL/TLS certificate from the server are not validated.
			/// currently this is only implemented on Windows.
			static int setup(mbedtls_ssl_config& conf)
			{
                (void)conf;

				#if defined(WIN32)
                #if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
					// Wincrypt appears to be not implemented for non-desktop apps
					static bool initialized = false;
					static mbedtls_x509_crt cacert;
					static mbedtls_x509_crl crl;
					static std::mutex mutex;
					std::lock_guard<std::mutex> guard(mutex);

					if (!initialized)
					{
						mbedtls_x509_crt_init(&cacert);
						mbedtls_x509_crl_init(&crl);

						static const char* store_names[] = {
							"ROOT",
							"CA"
						};

						for (int i = 0; i != sizeof(store_names) / sizeof(store_names[0]); ++i)
						{
							//HCERTSTORE cs = CertOpenSystemStore(0, store_names[i]);
							HCERTSTORE cs = CertOpenStore(
								CERT_STORE_PROV_SYSTEM_A,
								X509_ASN_ENCODING,
								NULL,
								CERT_STORE_OPEN_EXISTING_FLAG|
								CERT_STORE_READONLY_FLAG|
								CERT_STORE_SHARE_CONTEXT_FLAG|
								CERT_SYSTEM_STORE_CURRENT_USER,
								store_names[i]
							);
							assert(cs);
							if (!cs)
							{
								return false;
							}

							for (
								PCCERT_CONTEXT ctx = CertEnumCertificatesInStore(cs, NULL);
								ctx != NULL;
								ctx = CertEnumCertificatesInStore(cs, ctx)
								)
							{
								int res = mbedtls_x509_crt_parse(&cacert, ctx->pbCertEncoded, ctx->cbCertEncoded);
								if (res != 0)
								{
									return res;
								}
							}

							for (
								PCCRL_CONTEXT ctx = CertEnumCRLsInStore(cs, NULL);
								ctx != NULL;
								ctx = CertEnumCRLsInStore(cs, ctx)
								)
							{
								int res = mbedtls_x509_crl_parse(&crl, ctx->pbCrlEncoded, ctx->cbCrlEncoded);
								if (res != 0)
								{
									return res;
								}
							}

							CertCloseStore(cs, 0);
						}

						initialized = true;
					}

					mbedtls_ssl_conf_ca_chain(&conf, &cacert, &crl);
					mbedtls_ssl_conf_authmode(&conf, MBEDTLS_SSL_VERIFY_REQUIRED);
                #endif
				#endif

				return 0;
			}
	};

}} /* GameSparks::Util */

#endif /* GAMESPAKS_CERTIFICATE_STORE_HPP */
