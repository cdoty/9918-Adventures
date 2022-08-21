set WORKING_DIRECTORY=%cd%

cd \mame
mame cx5m -cass %WORKING_DIRECTORY%\BurgerMSX.wav -debug -autoboot_delay 5 -autoboot_command "BLOAD  """CAS:""" , R\n"

cd %WORKING_DIRECTORY%