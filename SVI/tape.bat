..\..\Tools\LAME\lame -h --preset insane BurgerSVI.wav BurgerSVI.mp3
IF ERRORLEVEL 1 goto errorOut

copy BurgerSVI.mp3 h:\Voice\SVI