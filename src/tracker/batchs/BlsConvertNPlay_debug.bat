cd "%~d0%~p0"
%~d0
Blsconvert_debug.exe "%1" > ~temp.txt
Blsplay_debug.exe "%~d1%~p1%~n1.BLS"
