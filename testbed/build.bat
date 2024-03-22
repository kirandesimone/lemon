rem Build script for Testbed
@echo OFF
SetLocal EnableDelayedExpansion

rem Get list of all the .c files
set cFilenames=
for /R %%f in (*.c) do (
    set cFilenames=!cFilenames! %%f 
)

set assembly=Testbed
set compilerFlags=-g -std=c17 
rem -Wall -Werror
set includeFlags=-Isrc -I../engine/src/
set linkerFlags=-L../bin/ -lengine.lib
set defines=-D_DEBUG -DLIMPORT

echo "Building %assembly%%..."
clang %cFilenames% %compilerFlags% -o ../bin/%assembly%.exe %defines% %includeFlags% %linkerFlags%