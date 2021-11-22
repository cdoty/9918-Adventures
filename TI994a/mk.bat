..\tools\naken\naken_asm -l Bank1.s -bin -o Bank1.bin
IF ERRORLEVEL 1 goto errorOut

..\tools\PadFile 255 8192 Bank1.bin
IF ERRORLEVEL 1 goto errorOut

..\tools\naken\naken_asm -l Bank2.s -bin -o Bank2.bin
IF ERRORLEVEL 1 goto errorOut

..\tools\PadFile 255 8192 Bank2.bin
IF ERRORLEVEL 1 goto errorOut

copy /b Bank1.bin+Bank2.bin Burger.bin

del Bank*.bin

..\tools\PadFile 255 32768 Burger.bin
IF ERRORLEVEL 1 goto errorOut

copy Burger.bin RPK

cd RPK

..\..\tools\zip Burger.rpk Burger.bin layout.xml
IF ERRORLEVEL 1 goto errorOut

cd ..

echo Build completed successfully

exit /B 0

:errorOut
echo Build Error
