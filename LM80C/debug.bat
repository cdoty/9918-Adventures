set WORKING_DIRECTORY=%cd%

cd \mame
mame pv2000 -cart %WORKING_DIRECTORY%\Burger.bin -debug

cd %WORKING_DIRECTORY%