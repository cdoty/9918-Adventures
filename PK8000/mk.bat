..\Tools\vasm\vasmz80_oldstyle_win32 -L Burger.map -pad=255 -Fbin -o Burger.bin -8080 -intel-syntax Cassette.s
IF ERRORLEVEL 1 goto errorOut

if exist Burger.cas del Burger.cas

tools\mcp -a Burger.cas BURGER.bin
IF ERRORLEVEL 1 goto errorOut

tools\mcp -e Burger.cas BurgerPK8000.wav
IF ERRORLEVEL 1 goto errorOut

exit /B 0

:errorOut
echo Build Error
