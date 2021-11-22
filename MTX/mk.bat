..\tools\tniASM\tniasm.exe Mtx.s
IF ERRORLEVEL 1 goto errorOut

copy /b Loader.bin+Burger.bin BURGER.mtx
IF ERRORLEVEL 1 goto errorOut

..\tools\appmake.exe +mtx --dumb --audio --fast -b BURGER.mtx
IF ERRORLEVEL 1 goto errorOut

del BurgerMTX.wav

rename BURGER.wav BurgerMTX.wav

..\tools\tniASM\tniasm.exe Cart.s
IF ERRORLEVEL 1 goto errorOut

exit /B 0

:errorOut
echo Build Error
