set WORKING_DIRECTORY=%cd%

cd \mame
mame pk8002 -cass %WORKING_DIRECTORY%/BurgerPK8002.wav -debug -autoboot_command "RBURGER\n"

cd %WORKING_DIRECTORY%