set WORKING_DIRECTORY=%cd%

cd \mame
mame vesta -cass %WORKING_DIRECTORY%/BurgerPK8000.wav -debug -autoboot_command "bload """BURGER""",R\n"

cd %WORKING_DIRECTORY%