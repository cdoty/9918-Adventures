copy ..\*.col

FOR %%i IN (*.col) DO Tools\SwapNibbles %%i
