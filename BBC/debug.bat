set WORKING_DIRECTORY=%cd%

cd \mame
mame bbcb -1mhzbus sprite -flop1 %WORKING_DIRECTORY%\Burger.ssd -debug

cd %WORKING_DIRECTORY%