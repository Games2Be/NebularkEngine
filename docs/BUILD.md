1. Clone the project:
   ```bash
   git clone https://github.com/Games2Be/NebularkEngine.git
   ```
2. ```bash
   cd NebularkEngine
   git submodule update --init --recursive
   ```
3. Add premake5.exe to the root of your solution (eg. NebularkEngine/premake5.exe
4. ```bash
   GenerateProject.bat
   ```
5. Go to Nebulark/vendor/SDL/SDL3/build in file explorer and open the "SDL3.sln"
6. Right click and build the INSTALL (Don't worry about any errors)
8. Open the main solution "Nebulark.sln"
9. Right click Sandbox and "Set as startup project"
10. And run the project on Debug and x64
11. After getting SDL3 error:
    - In Nebulark/vendor/SDL/SDL3/build/Release copy the SDL3.dll to bin/Debug-windows-x86_64/Sandbox
