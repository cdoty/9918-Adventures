set WORKING_DIRECTORY=%cd%

cd \mame
mame einstein -flop1 %WORKING_DIRECTORY%\Burger.dsk -debug

cd %WORKING_DIRECTORY%