set WORKING_DIRECTORY=%cd%

cd \mame
mame mtx500 -cass %WORKING_DIRECTORY%\BurgerMTX.wav -debug

cd %WORKING_DIRECTORY%