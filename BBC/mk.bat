..\tools\acme\acme Program.s
IF ERRORLEVEL 1 goto errorOut

Tools\CreateInf burger.inf burger BURGER 6400 6400 0 1

del Burger.ssd

perl tools/beebtools/beeb blank_ssd Burger.ssd
IF ERRORLEVEL 1 goto errorOut

perl tools/beebtools/beeb putfile Burger.ssd burger Disk/!boot
IF ERRORLEVEL 1 goto errorOut

perl tools/beebtools/beeb opt4 Burger.ssd 3
IF ERRORLEVEL 1 goto errorOut

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
