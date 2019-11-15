@echo on
set cdir = %~dp0
set c = HacksDelight.c
set o = 1.exe
echo %cdir%%o%
echo %cdir%%c%
gcc -o %cdir%%o% %cdir%%c%