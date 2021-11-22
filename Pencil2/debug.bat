set WORKING_DIRECTORY=%cd%

cd \mame
mame pencil2 -cart %WORKING_DIRECTORY%\Burger.bin -debug

cd %WORKING_DIRECTORY%