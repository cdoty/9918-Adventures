set WORKING_DIRECTORY=%cd%

cd \mame
mame bit90 -cart %WORKING_DIRECTORY%\Burger.bin -debug

cd %WORKING_DIRECTORY%
