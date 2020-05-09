@echo off
set baseDir=%~dp0
set mkdocsDir=%baseDir%mkdocs
set binDir=%baseDir%bin
set docsDir=%binDir%\docs
set mdDir=%baseDir%..\Notes
echo Start Execute-----------------------  
echo %mkdocsDir%
if exist %binDir% (
    rmdir /s/q %binDir%
) else (
    md %binDir%
    cd %binDir%
    md docs
    cd ..)
    REM md %binDir%/docs 
echo BIN::%binDir%
echo DOC::%docsDir%
echo MDS::%mdDir%
xcopy %mkdocsDir% %binDir% /e/s/y
xcopy %mdDir%\*.md %docsDir% /e/s/y/f
REM copy md file to binDir
echo Start Execute-----------------------  

