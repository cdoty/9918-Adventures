..\Tools\vasm\vasmz80_oldstyle_win32 -L Burger.map -pad=255 -Fbin -o Burger.bin -8080 -intel-syntax Cart.s
IF ERRORLEVEL 1 goto errorOut

if not exist "e:\Mame\Roms\phklad" mkdir e:\Mame\Roms\phklad
IF ERRORLEVEL 1 goto errorOut

copy Burger.bin e:\Mame\Roms\phklad\klad.bin
IF ERRORLEVEL 1 goto errorOut

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
