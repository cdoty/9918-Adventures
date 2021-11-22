set WORKING_DIRECTORY=%cd%

cd \mame
mame sg1000 -cart %WORKING_DIRECTORY%\Burger.sg -debug

cd %WORKING_DIRECTORY%