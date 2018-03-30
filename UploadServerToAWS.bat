SET operatingSystem=WINDOWS_2012
SET buildRoot="./Packages/WindowsServer"
SET name="Something"
SET version="1.0.0"
SET region=sa-east-1

aws gamelift upload-build --operating-system %operatingSystem% --build-root %buildRoot% --name %name% --build-version %version% --region %region%

pause