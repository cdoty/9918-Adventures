set WORKING_DIRECTORY=%cd%

cd Tools\Emulators
Hbc56Emu --resizable --renderer software --rom %WORKING_DIRECTORY%\Burger.o

cd %WORKING_DIRECTORY%