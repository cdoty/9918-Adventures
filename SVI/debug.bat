set WORKING_DIRECTORY=%cd%

cd \mame
mame svi328 -cart %WORKING_DIRECTORY%\Burger.bin -debug

cd %WORKING_DIRECTORY%