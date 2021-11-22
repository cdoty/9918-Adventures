set WORKING_DIRECTORY=%cd%

cd \mame
mame svi738 -flop %WORKING_DIRECTORY%\Burger.dsk -debug

cd %WORKING_DIRECTORY%