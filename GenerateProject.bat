call premake5.exe vs2022
mkdir "Nebulark\vendor/SDL\SDL3\build"
cd /d "Nebulark\vendor/SDL\SDL3\build"
cmake -S .. -B . -A x64
cmake --build . --config Release

PAUSE