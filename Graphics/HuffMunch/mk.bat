del	*.hfm

copy ..\Font.*
copy ..\Game.*
copy ..\Title*.*

FOR %%i IN (*.*) DO ..\..\Tools\huffmunch -B %%i %%i.hfm

del mk.bat.hfm
del *.col
del *.pal
del *.pat
del *.mgb
