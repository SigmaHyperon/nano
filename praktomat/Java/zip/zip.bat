@echo off
del src.zip
7z a -tzip -x!zip.bat src.zip *
pause