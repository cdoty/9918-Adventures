..\tools\acme\acme -f plain Cart.s
IF ERRORLEVEL 1 goto errorOut

tools\smbloader -i Burger.bin -l 0x8000 -a 60 -e
IF ERRORLEVEL 1 goto errorOut

tools\smbloader -i Burger.bin -l 0x8000 -a 60 -p 48
IF ERRORLEVEL 1 goto errorOut

del BurgerCreativision.wav

rename Burger.wav BurgerCreativision.wav

..\Tools\LAME\lame -h --preset insane BurgerCreativision.wav BurgerCreativision.mp3
IF ERRORLEVEL 1 goto errorOut
