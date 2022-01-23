..\tools\tniASM\tniasm.exe Cart.s
IF ERRORLEVEL 1 goto errorOut

if not exist "e:\Mame\Roms\pokerout" mkdir e:\Mame\Roms\pokerout
IF ERRORLEVEL 1 goto errorOut

..\Tools\romwak\romwak_x86.exe /h Burger.bin brk01_tms128a.6f f_tms128a.8f
IF ERRORLEVEL 1 goto errorOut

move /Y *.?f e:\Mame\Roms\pokerout

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
