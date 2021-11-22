..\tools\tniASM\tniasm.exe Cart.s
IF ERRORLEVEL 1 goto errorOut

exit /B 0

:errorOut
echo Build Error
