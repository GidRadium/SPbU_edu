rem Файл для тестирования структур на си из ветки Development

@echo off
set buildType=Release
set TargetName=test
cd %0\..\
echo %CD%
for /d %%B in (.\*) do echo %%B & cmake -S %%B -B %%B\build & cmake --build %%B\build --config %buildType% --target %TargetName% & "%CD%\%%B\build\%buildType%\%TargetName%.exe"
