set WORKING_DIRECTORY=%cd%

cd \mame
mame bruc100 -cartridge1 %WORKING_DIRECTORY%\Burger.rom -debug

cd %WORKING_DIRECTORY%