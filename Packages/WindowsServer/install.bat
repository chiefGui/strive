SET currentLocation=%~dp0
SET dependenciesLocation=%currentLocation%Dependencies
SET logsLocation=%currentLocation%Logs

SET vcredistFileName=vcredist_x64.exe
SET directxFileName=dxsetup.exe

"%dependenciesLocation%\%vcredistFileName%" /install /passive /norestart /quiet
& "%dependenciesLocation%\%directxFileName%" /install /silent