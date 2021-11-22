set WORKING_DIRECTORY=%cd%

cd \mame
mame m5p -cart1 basic-i.rom -cass %WORKING_DIRECTORY%\BurgerM5.wav -debug

cd %WORKING_DIRECTORY%