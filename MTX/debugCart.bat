set WORKING_DIRECTORY=%cd%

cd \mame
mame mtx500 -cart %WORKING_DIRECTORY%\Burger.rom -debug

cd %WORKING_DIRECTORY%