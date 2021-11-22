..\tools\tniASM\tniasm.exe Cassette.s
IF ERRORLEVEL 1 goto errorOut

copy /b Header.bin+Cassette.bin Burger.bin
IF ERRORLEVEL 1 goto errorOut

Tools\svitools -b Burger.bin BURGER -o Burger.cas -t 2.0
IF ERRORLEVEL 1 goto errorOut

Tools\svitools -p -i Burger.cas -o BurgerSVI.wav
IF ERRORLEVEL 1 goto errorOut

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
