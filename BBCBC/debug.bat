set WORKING_DIRECTORY=%cd%

cd \mame
mame bbcbc -cart %WORKING_DIRECTORY%\Burger.bin -debug

cd %WORKING_DIRECTORY%