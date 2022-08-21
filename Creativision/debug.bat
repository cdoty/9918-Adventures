set WORKING_DIRECTORY=%cd%

cd \mame
mame crvision -cart %WORKING_DIRECTORY%\Burger.bin -debug

cd %WORKING_DIRECTORY%