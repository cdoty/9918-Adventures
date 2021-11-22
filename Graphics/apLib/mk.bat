del	*.pck

copy ..\Font.*
copy ..\Game.*
copy ..\Title*.*

FOR %%i IN (*.*) DO ..\..\Tools\appack c %%i %%i.pck

del mk.bat.pck
del *.col
del *.pal
del *.pat
del *.mgb
