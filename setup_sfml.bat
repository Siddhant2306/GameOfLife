@echo off
echo === Setting up SFML ===

set SFML_VERSION=2.6.1
set SFML_URL=https://github.com/SFML/SFML/releases/download/%SFML_VERSION%/SFML-%SFML_VERSION%-windows-vc17-64-bit.zip

if not exist libs mkdir libs
cd libs

echo Downloading SFML %SFML_VERSION%...
curl -L -o sfml.zip %SFML_URL%

echo Extracting...
tar -xf sfml.zip
rename SFML-%SFML_VERSION%-windows-vc17-64-bit sfml

del sfml.zip
cd ..

echo Done! SFML ready in libs/sfml
pause
