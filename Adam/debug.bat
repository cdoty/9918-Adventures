set WORKING_DIRECTORY=%cd%

cd \mame
mame adam -cass1 %WORKING_DIRECTORY%/Burger.ddp -debug

cd %WORKING_DIRECTORY%