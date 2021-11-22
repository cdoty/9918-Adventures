..\tools\tniASM\tniasm.exe Cart.s
IF ERRORLEVEL 1 goto errorOut

copy /b BIOS.bin+Burger.bin+RomRoutines.bin Rom.bin
IF ERRORLEVEL 1 goto errorOut

Tools\Swap Rom.bin epr2764.15
IF ERRORLEVEL 1 goto errorOut

mkdir e:\mame\roms\pesadelo
copy /Y epr2764.15 e:\mame\roms\pesadelo

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
