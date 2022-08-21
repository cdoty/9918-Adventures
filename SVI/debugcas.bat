set WORKING_DIRECTORY=%cd%

cd \mame
mame svi328 -cass %WORKING_DIRECTORY%\Burger.cas -debug -autoboot_delay 6 -autoboot_command "BLOAD  """CAS:""" , R\n"

cd %WORKING_DIRECTORY%