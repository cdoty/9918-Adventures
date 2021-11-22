..\tools\tniASM\tniasm.exe Disk.s
IF ERRORLEVEL 1 goto errorOut

copy /b DiskHeader.bin+Disk.bin DISK\BURGER.BIN
IF ERRORLEVEL 1 goto errorOut

REM Tools\fat12maker\fat12maker -b DISK\BootSector.bin -t 6 -o Burger.dsk -i DISK\BURGER.BAS DISK\BURGER.BIN DISK\AUTOEXEC.BAS 
REM Tools\fat12maker\fat12maker -t 7 -o Burger.dsk -i DISK\BURGER.BAS DISK\BURGER.BIN DISK\AUTOEXEC.BAS 
IF ERRORLEVEL 1 goto errorOut

..\Tools\PadFile 255 368640 Burger.dsk

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error

