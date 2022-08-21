set WORKING_DIRECTORY=%cd%

cd \mame
mame mtx500 -cass %WORKING_DIRECTORY%\BurgerMTX.wav -debug -autoboot_delay 1 -autoboot_command "LOAD """"""\n"

cd %WORKING_DIRECTORY%