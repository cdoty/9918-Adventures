..\tools\acme\acme Cassette.s
IF ERRORLEVEL 1 goto errorOut

tools\smbloader -i Cassette.bin -l 0x8000 -a 60 -e
IF ERRORLEVEL 1 goto errorOut

REM -p 48 does not work with MAME.
REM tools\smbloader -i Burger.bin -l 0x8000 -a 60 -p 48
IF ERRORLEVEL 1 goto errorOut

tools\smbloader -i Cassette.bin -l 0x8000 -a 60
IF ERRORLEVEL 1 goto errorOut

if exist BurgerCreativision.wav del BurgerCreativision.wav

rename Cassette.wav BurgerCreativision.wav
