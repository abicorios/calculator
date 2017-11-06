# calculator
This console calculator use regular expressions for parsing input for detecting numbers and signs.

It is nice for complicated calculation with many numbers and brackets.

# Platform

Operation system Windows 10

#Programming language
C++

# building
Download and install Visual Studio Comunity Edition https://www.visualstudio.com

Download and install Git https://git-scm.com/

For example, create directory C:\test

Opeh git console, go to empty directory C:\test, input git clone --recursive git://github.com/abicorios/calculator.git

Press Enter

After cloning, you can close git prompt

From Windows start menu open Developer Command Prompt for VS2017

Go to C:\test\calculator\boost

Input bootstrap.bat

Press Enter

Input .\b2 --with-regex

Press Enter

After compiling,  you can close Developer Command Prompt for VS2017

Open folder C:\test\calculator

Double click calculator.sln

In Colution Explorer right click calculator and select Properties

In Configuration Properties > C/C++ > General > Additional Include Directories, input C:\test\calculator\boost

In Configuration Properties > Linker > General > Additional Library Directories, input C:\test\calculator\boost\stage\lib

Press Ok

Press Ctrl+F5

How do you know that it is not format your disk C?

