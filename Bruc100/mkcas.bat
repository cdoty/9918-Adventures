..\tools\sjasmplus-1.18.3.win\sjasmplus.exe --lst=Cassette.map Cassette.s
IF ERRORLEVEL 1 goto errorOut

copy /b Header.bin+Cassette.bin BURGER.bin
IF ERRORLEVEL 1 goto errorOut

if exist Burger.cas del Burger.cas

tools\mcp -a Burger.cas BURGER.bin
IF ERRORLEVEL 1 goto errorOut

tools\mcp -e Burger.cas BurgerBruc.wav
IF ERRORLEVEL 1 goto errorOut

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error

