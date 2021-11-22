set WORKING_DIRECTORY=%cd%

cd Tools\Emulators
Hbc56Emu --resizable --renderer software --rom %WORKING_DIRECTORY%\Burger.o
REM Hbc56Emu --resizable --renderer software --rom E:\9918-Adventures\HBC-56\invaders.o

cd %WORKING_DIRECTORY%