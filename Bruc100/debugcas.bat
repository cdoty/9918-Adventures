set WORKING_DIRECTORY=%cd%

cd \mame
mame bruc100 -cass %WORKING_DIRECTORY%\BurgerBruc.wav -debug

cd %WORKING_DIRECTORY%