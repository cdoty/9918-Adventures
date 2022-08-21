set WORKING_DIRECTORY=%cd%

cd \mame
mame bruc100 -cass %WORKING_DIRECTORY%\BurgerBruc.wav -debug -autoboot_delay 5 -autoboot_command "BLOAD  """CAS:""" ,R\n"

cd %WORKING_DIRECTORY%