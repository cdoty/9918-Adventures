set WORKING_DIRECTORY=%cd%

cd \mame
mame coleco -cart %WORKING_DIRECTORY%\Burger.bin -debug

cd %WORKING_DIRECTORY%