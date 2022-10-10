..\tools\sjasmplus-1.18.3.win\sjasmplus.exe --lst=Burger.map Cart.s
IF ERRORLEVEL 1 goto errorOut

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
