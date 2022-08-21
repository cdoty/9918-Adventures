set WORKING_DIRECTORY=%cd%

cd \mame
mame apple2e -sl7 ssprite -flop1 %WORKING_DIRECTORY%/Burger.dsk -debug

cd %WORKING_DIRECTORY%