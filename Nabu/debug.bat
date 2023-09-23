set WORKING_DIRECTORY=%cd%

cd \RetroProjects\nabu-mame
mame nabupc -kbd nabu_hle -hcca null_modem -bitb socket.127.0.0.1:5816 -debug

cd %WORKING_DIRECTORY%
