# Tiny Graphics Engine
#### This engine was built by Trevor from scratch as a passion project.
I started this project because I wanted to learn want the back-end of game development was like.


## Installation

To Download this you will need CMake and GLFW.

Windows (CMD)
```shell
winget install Kitware.CMake
```

Linux (TERMINAL)
```bash
sudo apt update
sudo apt install cmake libglfw3-dev
```
## Getting started

This is the minimum code needed to start.

```cpp
#include <tinyGE/tinyGE.h>

int main()
{
    tinyGE::init()
    tinyGE::createWindow("Basic Window", 1920, 1080);

    while(!tinyGE::tick)
    {
        // Game code here
    }
    
}
```


## Requirements

- C++ compiler
- CMake
- OpenGL 4.6
- GLFW
- Windows 10+ or Linux
