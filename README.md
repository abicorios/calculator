# calculator
This console calculator use the regular expressions for the parsing of the input for the detecting of the numbers and the mathematical signs.

It is nice for the complicated calculations with many numbers and brackets. You can use ^ or ** for the power operation, the brackets (){}[] and operations +-*/

# Platform

Operation system Windows 10

# Programming language
C++

# building
Download and install Visual Studio Comunity Edition https://www.visualstudio.com

Download and install Git https://git-scm.com/

From the Windows start menu open Developer Command Prompt for VS2017 

Do it:

git clone https://github.com/abicorios/calculator

cd calculator

MakeX86WithBoostRegex.bat

The result is the calculator.exe in the Debug folder.

# References
I use the Boost Regex https://github.com/boostorg/regex. 
My MakeX86WithBoostRegex.bat script is inspired by the file appveyor.yml https://github.com/boostorg/regex/blob/develop/appveyor.yml, which help me use only such Boost submolules which need for the compiling of the Regex. It is less than half of all submodules of the full Boost https://github.com/boostorg/boost. Half Boost is faster for download and compiling. It is why I do not do git submodule add git://github.com/boostorg/boost.git boost, but instead I use my own castomised script MakeX86WithBoostRegex.bat.
