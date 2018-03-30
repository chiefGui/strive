SET currentLocation=%~dp0
SET dependenciesLocation=%currentLocation%Dependencies
SET logsLocation=%currentLocation%Logs

SET vcredistFileName="vcredist_x64.exe"
SET directxFileName="dx.exe"

"%dependenciesLocation%\%vcredistFileName%" /install /quiet /norestart /log %logsLocation%/%vcredistFileName%.log
"%dependenciesLocation%\%directxFileName%" /q

