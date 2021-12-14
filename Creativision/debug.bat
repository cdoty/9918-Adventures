set WORKING_DIRECTORY=%cd%

cd \mame
mame lasr2001 -cart %WORKING_DIRECTORY%\Burger.bin -debug
REM mame lasr2001 -cass %WORKING_DIRECTORY%\BurgerCreativision.wav -debug

cd %WORKING_DIRECTORY%