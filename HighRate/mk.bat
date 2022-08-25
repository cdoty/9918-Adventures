..\tools\VASM\vasmm68k_mot_win32.exe -L Game.lst -pad=255 -spaces -Fbin -x -quiet -o Game.rom Cart.s
IF ERRORLEVEL 1 goto errorOut

if not exist e:/Mame/Roms/hrhmbrew mkdir e:/Mame/Roms/hrhmbrew
IF ERRORLEVEL 1 goto errorOut

copy /Y Game.rom e:\Mame\Roms\hrhmbrew
IF ERRORLEVEL 1 goto errorOut

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
