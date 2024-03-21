rem The build script for the lemon engine
@echo OFF
SetLocal EnableDelayedExpansion

rem list all of the .c files
set cFilenames=
for /R %%f in (*.c) do (
    set cFilenames=!cFilenames! %%f
)

rem echo "Files:" %cFilenames%

set assembly=engine
set compilerFlags=-g -shared -Wvarargs -Wall -Werror
rem -Wall -Werror
set includeFlags=-Isrc -I%VULKAN_SDK%/includeFlags
set linkerFlags=-luser32 -lvulkan-1 -L%VULKAN_SDK%/Lib
set defines=-D_DEBUG -DKEXPORT -D_CRT_SECURE-NO_WARNINGS

echo "Building %assembly%%..."
clang %cFilenames% %compilerFlags% -o ../bin/%assembly%.dll %defines% %includeFlags %linkerFlags%