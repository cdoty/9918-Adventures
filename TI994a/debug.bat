set WORKING_DIRECTORY=%cd%

cd \mame
mame ti99_4a -cart %WORKING_DIRECTORY%\RPK\Burger.rpk -debug
cd \9918-Adventures\ti994a

cd %WORKING_DIRECTORY%