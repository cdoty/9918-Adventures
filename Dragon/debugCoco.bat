set WORKING_DIRECTORY=%cd%

cd \mame
mame coco2 -ext multi -ext:multi:slot1 wpk2p -flop1 %WORKING_DIRECTORY%/Burger.dsk -debug -autoboot_delay 2 -autoboot_command "LOAD """BOOT""",R\n"

cd %WORKING_DIRECTORY%