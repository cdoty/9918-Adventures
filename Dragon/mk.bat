..\Tools\vasm\vasm6809_oldstyle_win32 -L Burger.map -pad=255 -Fbin DragonDisk.s -o Burger.bin
IF ERRORLEVEL 1 goto errorOut

if exist Burger.dsk del Burger.dsk

Tools\imgtool\imgtool create coco_vdk_dgndos Burger.vdk
IF ERRORLEVEL 1 goto errorOut

Tools\imgtool\imgtool put coco_vdk_dgndos Burger.vdk DragonBoot.bas BOOT.BAS --filter=dragonbas
IF ERRORLEVEL 1 goto errorOut

Tools\imgtool\imgtool put coco_vdk_dgndos Burger.vdk Burger.bin BURGER.BIN
IF ERRORLEVEL 1 goto errorOut

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
