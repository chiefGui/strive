SET currentLocation=%~dp0
SET dependenciesLocation=%currentLocation%Dependencies
SET logsLocation=%currentLocation%Logs

SET vcredistFileName=vcredist_x64.exe
SET directxFileName=dxwebsetup.exe

"%dependenciesLocation%\%vcredistFileName%" /q
"%dependenciesLocation%\%directxFileName%" /q