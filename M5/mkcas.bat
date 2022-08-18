..\tools\sjasmplus-1.18.3.win\sjasmplus.exe --lst=Burger.map Cassette.s
IF ERRORLEVEL 1 goto errorOut

Tools\BinToCas Burger.bin  Burger.cas
IF ERRORLEVEL 1 goto errorOut

\mame\castool convert sordm5 Burger.cas BurgerM5.wav
IF ERRORLEVEL 1 goto errorOut

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
