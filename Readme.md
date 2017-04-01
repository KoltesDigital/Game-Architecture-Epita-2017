# Game Architecture - EPITA 2017

> Course materials. Contains voluntary errors and design flaws which are addressed during the courses :)

## Requirements

The external dependencies support multiple OSes, however in this repository they are only precompiled for Windows. The code also requires a small tweak to make it work under other OSes.

1. [Visual Studio 2015](https://www.visualstudio.com/downloads/)
2. [Premake 5](https://premake.github.io/download.html)

To generate the solution files, execute:

	premake5.exe vs2015

## External dependencies

1. [cli.cpp](https://github.com/KoltesDigital/cli.cpp), a CLI argument parser (header-only)
2. [ODE](http://www.ode.org/), a physics engine
3. [pugixml](http://pugixml.org/), an XML parser (header-only)
4. [SFML](https://www.sfml-dev.org/), a small multimedia framework
