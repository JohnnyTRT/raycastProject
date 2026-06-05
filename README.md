# raycastProject
Small raycasted game in which player is tasked with finding their way out of the maze. Right now just file structure exists.

DISLAIMER: All of the bash code that is below was written by me and is therefore subject to errors. Just let me know of any errors and we can figure it out. 


## Installing CMake & Conan
This project uses CMake + Conan for build system + package management. You must have both CMake and Conan installed on you device prior to running any build instructions along with a c++ compiler installed (I use clang). Simple instructions can be found below that detail how to install cmake and conan on different operating systems through the terminal. Once CMake and Conan have been installed on your device once, you should not need to run these again. (It is also possible to install both CMake and Conan from their websites through Google, just make sure to verify they have been installed and run the Conan profile command if you do it that way).

Also make sure you have a c++ compiler installed on your device. It does not really matter which compiler you choose, and you should already have one installed if you have been running c++ programs on your device already (I personally use clang). 

If you are serious about getting into c++, would highly reccomend getting familiar with CMake (Conan is not as mainstream, but in my opinion it is very helpful). Here is a brief description of what they do if you are curious:

CMake is a build system for c++. This means it is capable of detecting your compiler, enforcing c++ version control, and managing external libraries. It is used to build your projects from c++ code into an executable using a compiler. You can learn more about CMake at [Cmake Webpage](https://cmake.org/)

Conan is a package manager for c++. This is useful if your project has 3rd party libraries (like sdl3 or imgui). Conan allows you to define what libraries you want to use and it uses an open-source server to locate and install precompiled binaries of those libraries for your project based on your compiler, system architecture, and operating system. If a precompiled binary for your machine is not available, Conan will compile the library itself. You can learn more about Conan at [Conan Webpage](https://conan.io/)


### Installing CMake & Conan on MacOS:
Step 1: Install xcode tools (reccomended but not required)
```bash
xcode-select --install
```

Step 2: Install Homebrew (or equivalent package manager)
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Step 3: Install CMake with Homebrew
```bash
brew install cmake
```

Step 4: Verify CMake install (this should print out on terminal something like: cmake version 4.2.0) If it does not print out anything or gives an error, close and reopen terminal. If that does not work, then it has not been installed properly.
```bash
cmake --version
```

Step 5: Install Conan with Homebrew
```bash
brew install conan
```

Step 6: Verify Conan install (this should print out on terminal something like: conan version 2.25.2)
```bash
conan --version
```

Step 7: Setup Conan profile (This command will detect your os, compiler, and sys architecture)
```bash
conan profile detect --force
```

### Installing CMake & Conan on Windows:
Step 1: Install CMake with Winget (Winget should be installed by default with Windows 11, but might have to install it if it is not)
```bash
winget install cmake
```

Step 2: Verify Cmake install (this should print out on terminal something like: cmake version 4.2.0) If it does not print out anything or gives an error, close and reopen terminal. If that does not work, then it has not been installed properly.
```bash
cmake --version
```

Step 3: The easiest way to install Conan is with Python, so download Python 3.8 or higher prior to running below command.
```bash 
pip install conan
```

Step 4: Verify Conan Install (this should print out on terminal something like: conan version 2.25.2)
```bash
conan --version
```

Step 5: Setup Conan profile (This command will detect your os, compiler, and sys architecture)
```bash
conan profile detect --force
```

### Installing CMake & Conan on Linux:
Installing CMake on Linux is very distribution dependent, but it is pretty much just:
```bash
sudo [package manager name (dnf, apt, or pacman] install cmake
```

Installing Conan can be done through Python, so just follow the Windows steps 3-5 after downloading Python 3.8 or later.


## Git Version Control Usage
Git is the mainstream platform for managing versions and track changes of coding projects. I have listed quick install instructions for git and some information on how to use it; however, I highly reccomend watching some tutorials on how to use it (nothing crazy, just the basics). If you are serious about doing software development or any type of computer coding, git is super important to know how to use, as it is an industry standard. 

### Installing Git

Windows:
```bash
winget install git.git
```

MacOS (Assuming you have already installed homebrew from above section):
```bash
brew install git
```

Linux:
```bash
sudo [package manager] install git
```

On All Operating Systems Check if installed with:
```bash
git --version
```

### Downloading the Project

To import the project for the first time:
```bash
git clone https://github.com/JohnnyTRT/raycastProject.git
```

If you have already imported the project, but wanted to import it again because changes have been made:
```bash
git pull origin main 
```

You can also just download the project directly from the github page of the project: [You are already here](https://github.com/JohnnyTRT/raycastProject#)

### Getting your changes into the project repository

Add Changes:
```bash
git add .
```

Commit Changes:
```bash
git commit -m "In this section add a message describing what you did and how you changed the project"
```

Push Changes:
```bash
git push origin main
```

Since we are all working on the same project simultaneosly, there is likely to be siutations where you have pulled a version of the repository from github that is a different version from which you are uploading to. In other words, if I decide to work on the project and you decide to work on the project, then we both pull the current code from the repository. Then if I finish first and upload my code to the repository, you are left with an outdated project. This can be problamatic; however, I have seperated our code among multiple c++ files, so hopefully we can mitigate the headache. 

You do also have to authorize your device to use your git account, but that should not be too hard. 

## Building the Project

For building the actual final executable the instructions below can be run. However, this is only in running the final executable. I expect that as we all work on our own code, we will test them independent of the final executable, but feel free to use main.cpp to test your code since it has access to both sdl3 and imgui (just clean it up afterwards). You can also make tests with cmake and compile your own code seperately, but you do not have to do that if you do not want to. 

### First time Build 
Run these steps in the root of the project directory (should be in the folder racyastProject)

Step 1: Install packages on Device (This may take a bit the first time, but should be quick after that)
```bash
conan install . -s build_type=Release --build=missing
```

Step 2: Give CMake the Conan preset
```bash
cmake --preset conan-release
```

Step 3: Build the project with Cmake using the Conan preset
```bash
cmake --build --preset conan-release
```

Step 4: The Executable (raycastProject) will be sent to the bin/ folder (On windows it sometimes goes to bin/debug). In the folder that the executable is in, run:
```bash
./raycastProject 
```

### Building after the First time
After building the project once, you can build it again after modifying the code just by repeating step 3:
```bash
cmake --build --preset conan-release
```

Then run the executable again with:
```bash
./raycastProject
```

## Summary

Currently, I have made a simple project structure, linked conan + cmake, and added SDL3 and Imgui to the project. The project will be split among quite a few cpp + hpp files to enhance readability, but more importantly to reduce any conflicts when working together on different parts. 

The main thing to notice right now is that main.cpp should be kept extremely simple and should only initialize a game object that will actually run the game.The reasons for this as is follows:

- Reduces Clutter
- Easy to Read 
- MOST IMPORTANT: it allows you to test your code. main.cpp has access to every cpp file in the project on top of sdl3 and imgui. This means you can easily test your code in main.cpp by writing or adding your functions to main.cpp and compiling the project. This means you do not have to download sdl3 or imgui seperate to test things; however, make sure when you are done testing to clean main.cpp back up to either just return 0, or to create game object if we have coded that.
