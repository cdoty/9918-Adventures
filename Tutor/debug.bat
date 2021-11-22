set WORKING_DIRECTORY=%cd%

cd \mame
mame tutor -cart %WORKING_DIRECTORY%\Burger.bin -debug
cd \9918-Adventures\Tutor

cd %WORKING_DIRECTORY%