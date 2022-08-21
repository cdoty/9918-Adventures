del	*.zx0

copy ..\*.col
copy ..\*.pat
copy ..\*.mgb

FOR %%i IN (*.*) DO ..\..\Tools\zx0 -c %%i

del mk.bat.zx0
del *.col
del *.pat
del *.mgb
