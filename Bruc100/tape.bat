..\..\Tools\LAME\lame -h --preset insane BurgerMSX.wav BurgerMSX.mp3
IF ERRORLEVEL 1 goto errorOut

copy BurgerMSX.mp3 h:\Voice\MSX
..\..\Tools\RemoveDrive h: -L