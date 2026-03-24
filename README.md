# Checklist
Checklist is a simple task management application built with the Qt framework.  
It just lets you add and remove tasks for now, with plans to add things like: 
- Task modifications (WIP currently)
- Dates for each task
- Start on startup
- Cleaner, better UI (especially on light mode)

# REQUIREMENTS
- A C++ compiler supported by Qt (e.g MSVC, GCC - we use MSVC in the section below)
- Qt 6.8.2
- windeployqt.exe (you probably already have this)

# BUILD, RUN & RELEASES 
Start by copying the folder with git to your desired location (we'll use C:\Checklist in this example).   
Afterwards, in Powershell, run :

	PS > cd Checklist
	PS > mkdir build && cd build
	PS > cmake -DCMAKE_BUILD_TYPE=Release ..
	PS > cmake --build . --config Release
	PS > windeploy C:\Checklist\build\Release\Checklist.exe

Your `Release` folder can now be taken outside of `C:\CheckList\`, and you can run the app wherever (from inside the `Release` folder, of course).

# LICENSE 
Licensed under GPL-3.0 license.
