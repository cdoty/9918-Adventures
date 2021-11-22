set WORKING_DIRECTORY=%cd%

cd \mame
mame wizzard -cart %WORKING_DIRECTORY%\Burger.bin -debug

cd %WORKING_DIRECTORY%