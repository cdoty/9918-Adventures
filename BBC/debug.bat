set WORKING_DIRECTORY=%cd%

cd \mame
mame bbcb -1mhzbus sprite -flop1 %WORKING_DIRECTORY%\Burger.ssd -debug -autoboot_delay 3 -autoboot_command "*burger\n"

cd %WORKING_DIRECTORY%