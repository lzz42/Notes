@echo off
REM set baseDir=%~dp0
REM set mkdocsDir=%baseDir%mkdocs
REM set mkdocsIndexDir=%baseDir%mkdocs_index
REM set binDir=%baseDir%bin
REM set docsDir=%binDir%\docs
REM set mdDir=%baseDir%..\Notes
REM echo Start build mkdocs dir -----------------------  
REM if exist %binDir% (
REM     REM rmdir /s/q %binDir%
REM ) else (
REM     md %binDir%
REM     cd %binDir%
REM     md docs
REM     cd ..)
REM echo BIN::%binDir%
REM echo DOC::%docsDir%
REM echo MDS::%mdDir%
REM echo IDX::%mkdocsIndexDir%

REM REM ----- copy mkdocs files -----
REM xcopy %mkdocsDir% %binDir% /s/y
REM REM ----- copy Notes markdown files -----
REM xcopy %mdDir%\*.md %docsDir% /s/y/f
REM REM ----- copy Notes markdwon index files -----
REM xcopy %mkdocsIndexDir%\*.md %docsDir% /s/y/f
echo ----- build mkdocs dir done-----------------------  

