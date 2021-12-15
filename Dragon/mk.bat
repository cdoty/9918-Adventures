..\Tools\vasm\vasm6809_oldstyle_win32 -L Burger.map -pad=255 -Fbin DragonDisk.s -o Burger.bin
IF ERRORLEVEL 1 goto errorOut

if exist Burger.dsk del Burger.dsk

Tools\imgtool\imgtool create coco_vdk_dgndos Burger.vdk
Tools\imgtool\imgtool put coco_vdk_dgndos Burger.vdk DragonBoot.bas BOOT.BAS --filter=dragonbas
Tools\imgtool\imgtool put coco_vdk_dgndos Burger.vdk Burger.bin BURGER.BIN

exit /B 0

:errorOut
echo Build Error
