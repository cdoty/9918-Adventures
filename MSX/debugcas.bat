set WORKING_DIRECTORY=%cd%

cd \mame
mame cx5m -cass %WORKING_DIRECTORY%\BurgerMSX.wav -debug

cd %WORKING_DIRECTORY%