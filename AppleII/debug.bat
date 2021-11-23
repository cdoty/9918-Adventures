set WORKING_DIRECTORY=%cd%

cd \mame
REM mame apple2e -sl1 ssprite -flop1 %WORKING_DIRECTORY%/Burger.dsk -debug
mame apple2gs -sl7 ezcgi -flop1 %WORKING_DIRECTORY%/Burger.dsk -debug

cd %WORKING_DIRECTORY%