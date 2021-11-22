..\tools\acme\acme Cart.s
IF ERRORLEVEL 1 goto errorOut

copy /b Burger.bin+FirstBank.raw Burger.rom
IF ERRORLEVEL 1 goto errorOut

Tools\SwapBanks Burger.bin
IF ERRORLEVEL 1 goto errorOut

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
