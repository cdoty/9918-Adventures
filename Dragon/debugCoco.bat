set WORKING_DIRECTORY=%cd%

cd \mame
mame coco2 -ext multi -ext:multi:slot1 wpk2p -flop1 %WORKING_DIRECTORY%/Burger.dsk -debug

cd %WORKING_DIRECTORY%