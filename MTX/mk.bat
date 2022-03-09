..\tools\sjasmplus-1.18.3.win\sjasmplus.exe --lst=Burger.map Mtx.s
IF ERRORLEVEL 1 goto errorOut

copy /b Loader.bin+Burger.bin BURGER.mtx
IF ERRORLEVEL 1 goto errorOut

..\tools\appmake.exe +mtx --dumb --audio --fast -b BURGER.mtx
IF ERRORLEVEL 1 goto errorOut

if exist BurgerMTX.wav del BurgerMTX.wav

rename BURGER.wav BurgerMTX.wav

..\tools\sjasmplus-1.18.3.win\sjasmplus.exe --lst=Burger.map Cart.s
IF ERRORLEVEL 1 goto errorOut

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
