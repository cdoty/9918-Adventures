set WORKING_DIRECTORY=%cd%

cd \mame
mame m5p -cart1 %WORKING_DIRECTORY%\Burger.bin -debug

cd %WORKING_DIRECTORY%