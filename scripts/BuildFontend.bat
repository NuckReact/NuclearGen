@echo off
pyinstaller --noconsole --name Frontend --distpath ../bin/Debug-windows-x86_64/ --workpath ../Frontend/build --specpath ../Frontend/ ../Frontend/src/Main.py
pause