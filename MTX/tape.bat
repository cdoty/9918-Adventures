..\..\Tools\LAME\lame -h --preset insane BurgerMTX.wav BurgerMTX.mp3
IF ERRORLEVEL 1 goto errorOut

copy BurgerMTX.mp3 e:\Voice\MTX
..\..\Tools\RemoveDrive e: -L