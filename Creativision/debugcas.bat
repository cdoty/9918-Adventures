set WORKING_DIRECTORY=%cd%

cd \mame
mame lasr2001 -cass %WORKING_DIRECTORY%\BurgerCreativision.wav -debug -autoboot_delay 6 -autoboot_command "BLOAD\nCALL -138"

cd %WORKING_DIRECTORY%