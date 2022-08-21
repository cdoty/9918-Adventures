..\Tools\vasm\vasmz80_oldstyle_win32 -L Burger.map -pad=0 -Fbin -o Burger.bin -8080 -intel-syntax Cassette.s
IF ERRORLEVEL 1 goto errorOut

tools\encrypt Burger.bin Burger.cas
IF ERRORLEVEL 1 goto errorOut

tools\mcp -e Burger.cas BurgerPK8002.wav
IF ERRORLEVEL 1 goto errorOut

copy /Y Burger.cas C:\Users\Charles\Desktop\emu\Cassettes\PK8002
IF ERRORLEVEL 1 goto errorOut

copy /Y Burger.map C:\Users\Charles\Desktop\emu\Cassettes\PK8002\Burger.lst
IF ERRORLEVEL 1 goto errorOut

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
