set WORKING_DIRECTORY=%cd%

cd \mame
mame apple2gs -sl7 ezcgi -flop1 %WORKING_DIRECTORY%/Burger.dsk -debug

cd %WORKING_DIRECTORY%