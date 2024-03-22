rem Build script for both the engine and Testbed
@echo OFF

echo "Building the Engine and Testbed"

rem This will move to the engine dir, execute the build script and pop out of the engine dir
rem If any errors occur then it will not finish the script

pushd engine
call build.bat
popd
if %ERRORLEVEL% neq 0 (echo Error:%ERRORLEVEL% && exit)

rem This will move to the testbed dir and execute the build script, then it will pop out of the testbed dir
rem If this fails then the scipt will exit

pushd testbed
call build.bat
popd
if %ERRORLEVEL% neq 0 (echo Error:%ERRORLEVEL% && exit)

echo "Build Successful"