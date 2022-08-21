set WORKING_DIRECTORY=%cd%

cd \mame
mame dragon32 -ext multi -ext:multi:slot1 sprites -flop1 %WORKING_DIRECTORY%/Burger.vdk -debug -autoboot_delay 3 -autoboot_command "RUN """BOOT"""\n"

cd %WORKING_DIRECTORY%