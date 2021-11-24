..\tools\tniASM\tniasm.exe Cassette.s
IF ERRORLEVEL 1 goto errorOut

copy /b Header.bin+Cassette.bin BURGER.bin
IF ERRORLEVEL 1 goto errorOut

if exist Burger.cas del Burger.cas

tools\mcp -a Burger.cas BURGER.bin
IF ERRORLEVEL 1 goto errorOut

tools\mcp -e Burger.cas BurgerMSX.wav
IF ERRORLEVEL 1 goto errorOut

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error

