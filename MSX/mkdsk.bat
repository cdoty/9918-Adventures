..\tools\sjasmplus-1.18.3.win\sjasmplus.exe --lst=Burger.map Disk.s
IF ERRORLEVEL 1 goto errorOut

copy /b DiskHeader.bin+Disk.bin DISK\BURGER.BIN
IF ERRORLEVEL 1 goto errorOut

tools\msxtar -cvf Burger.dsk --size=single Disk/AUTOEXEC.BAS Disk/BURGER.BAS Disk/BURGER.BIN
IF ERRORLEVEL 1 goto errorOut

..\Tools\PadFile 255 368640 Burger.dsk

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error

