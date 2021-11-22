set WORKING_DIRECTORY=%cd%

cd \mame
mame svi328 -cass %WORKING_DIRECTORY%\Burger.cas -debug

cd %WORKING_DIRECTORY%