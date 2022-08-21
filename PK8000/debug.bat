set WORKING_DIRECTORY=%cd%

cd \mame
mame hobby -cass %WORKING_DIRECTORY%/BurgerPK8000.wav -debug -autoboot_command "bload """BURGER""",R\n"

cd %WORKING_DIRECTORY%