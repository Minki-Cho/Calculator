# Raylib CMake Calculator Project

This provides a base project template which builds with [CMake](https://cmake.org).

## Usage

To compile the example, use one of the following dependending on your build target...

### Desktop

Use the following to build for desktop:


For the linux, I recommend execute on linux ubuntu os or window 11.
Window 10 bash does not support.

### Working on GNU Linux

#### Install required tools

First upgrade

    sudo apt-get update 

You need a **GCC**, **make** and **git** (to download raylib repo).

    sudo apt install build-essential git

Optionally, you could use **CMake** building system.

    sudo apt install cmake

#### Install required libraries
You need to install some required libraries; **Mesa** for OpenGL accelerated graphics and **X11** for windowing system.

##### Ubuntu
    sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev

##### Fedora
    sudo dnf install alsa-lib-devel mesa-libGL-devel libX11-devel libXrandr-devel libXi-devel libXcursor-devel libXinerama-devel libatomic    


If you finish download than you can run it.
While compiling there will be warnings for "raylib" library.

bash(linux) || linux (ubuntu)
``` bash(linux) || linux (ubuntu)

cmake -B build
cmake --build build

or

cmake -DCMAKE_BUILD_TYPE=Release -B build -S .
cmake --build build --config Release

```

cmd(vs)
``` cmd(vs)
cmake -B build
cmake --build build
After build, open *.sin
Set start project as calcultor
build and run

or

cmake -DCMAKE_BUILD_TYPE=Release -B build -S .
After build, open *.sin
Set start project as calcultor
build and run

```

clang [InClang](../../ScreenShot/howtoclang.png)
``` clang
Open visual studio code.
Under taskbar can choose compiler type - choose Clang.
Under taskbar there will be build button.
Under taskbar it can click run button.
```