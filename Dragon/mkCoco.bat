..\Tools\vasm\vasm6809_oldstyle_win32 -L Burger.map -pad=255 -Fbin CoCoDisk.s -o Burger.bin
IF ERRORLEVEL 1 goto errorOut

if exist Burger.dsk del Burger.dsk

Tools\imgtool\imgtool create coco_jvc_rsdos Burger.dsk
IF ERRORLEVEL 1 goto errorOut

Tools\imgtool\imgtool put coco_jvc_rsdos Burger.dsk CoCoBoot.bas BOOT.BAS --filter=cocobas --ftype=basic
IF ERRORLEVEL 1 goto errorOut

Tools\imgtool\imgtool put coco_jvc_rsdos Burger.dsk Burger.bin BURGER.BIN --ftype=binary
IF ERRORLEVEL 1 goto errorOut

exit /B 0

:errorOut
echo Build Error
