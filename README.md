to install my project please do : 
```bash
git clone https://github.com/Saiisako/Push_Swap.git
```
First of all to install the tester and visualizer please do :
```bash
make tester
```
Once you done that you must :
```bash
make
cd push_swap_tester
./complexity [sized of list] [iterations] [goal] ../checker_linux
```

The visualizer uses C++17, cmake, SFML and ImGui.

Install required packages (if not already installed) For Debian-based systems, you can install the necessary packages using the following commands:
```bash
sudo apt-get update
sudo apt-get install cmake
sudo apt-get install g++
sudo apt-get install clang
sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev
sudo apt-get install libx11-dev libxrandr-dev
sudo apt-get install libudev-dev
sudo apt-get install libfreetype-dev
```
Navigate to the push_swap_visualizer directory, create build directory, and navigate into the build directory:

```bash
cd push_swap_visualizer
mkdir build
cd build
```
Generate the build files using CMake and compile the visualizer:

```bash
cmake ..
make
```
Run the visualizer:

```bash
./bin/visualizer
```
## Disclaimer

I do not own the rights to any visualizers and the tester included or mentioned in this repository.
All rights belong to their respective owners.
This repository is for educational and non-commercial purposes only.
If there are any concerns regarding the content, please contact me to address the issue.
Here is a link of the github page of the owner of the visualizer :
https://github.com/o-reo
and the link of the github page of the owner of the tester :
https://github.com/SimonCROS


