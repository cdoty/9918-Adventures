..\tools\naken\naken_asm -l Cart.s -bin -o Burger.bin
IF ERRORLEVEL 1 goto errorOut

..\tools\PadFile 255 32768 Burger.bin
IF ERRORLEVEL 1 goto errorOut

if exist Burger.rom delete Burger.rom

copy Burger.bin Burger.rom

..\tools\PadFile 255 262144 Burger.rom
IF ERRORLEVEL 1 goto errorOut

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
