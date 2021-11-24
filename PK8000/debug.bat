set WORKING_DIRECTORY=%cd%

cd \mame
mame vesta -cass %WORKING_DIRECTORY%/BurgerPK8000.wav -debug

cd %WORKING_DIRECTORY%