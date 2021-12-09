..\tools\tniASM\tniasm.exe ddp.s
IF ERRORLEVEL 1 goto errorOut

tools\ddp Boot.rom Burger.rom Burger.ddp
IF ERRORLEVEL 1 goto errorOut

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
