..\tools\acme\acme Program.s
IF ERRORLEVEL 1 goto errorOut

Tools\diskm8 -with-disk Burger.dsk -file-put BURGER#0x1000.BIN

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
