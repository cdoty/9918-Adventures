..\tools\sjasmplus-1.18.3.win\sjasmplus.exe --lst=Burger.map Cart.s
IF ERRORLEVEL 1 goto errorOut

copy /b BIOS.raw+Burger.bin+RomRoutines.raw Rom.bin
IF ERRORLEVEL 1 goto errorOut

Tools\Swap Rom.bin epr2764.15
IF ERRORLEVEL 1 goto errorOut

if not exist "e:\mame\roms\pesadelo" mkdir e:\mame\roms\pesadelo

move /Y epr2764.15 e:\mame\roms\pesadelo

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
