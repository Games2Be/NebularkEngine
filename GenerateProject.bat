call premake5.exe vs2022
mkdir "Nebulark\vendor\glfw\build"
cd /d "Nebulark\vendor\glfw\build"
cmake -S .. -B . -A x64
cmake --build . --config Release

PAUSE