set WORKING_DIRECTORY=%cd%

cd \mame
mame cx5m -cartridge1 %WORKING_DIRECTORY%\Burger.rom -debug

cd %WORKING_DIRECTORY%