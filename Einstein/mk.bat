..\tools\sjasmplus-1.18.3.win\sjasmplus.exe --lst=Burger.map Disk.s
IF ERRORLEVEL 1 goto errorOut

if exist Burger.dsk del Burger.dsk

copy bootDisk\Boot.dsk Burger.dsk

REM ..\tools\appmake +cpmdisk -f einstein -b Burger.com -o Burger.dsk
Tools\dsktool insert Burger.com Burger.dsk
IF ERRORLEVEL 1 goto errorOut

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
