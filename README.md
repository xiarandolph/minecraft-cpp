# minecraft-cpp

Learning cpp and OpenGL while watching the following video series:
[How to Make Minecraft in C++/ OpenGL](https://www.youtube.com/playlist?list=PLMZ_9w2XRxiZq1vfw1lrpCMRDufe2MKV_)

## Dependencies
Using SFML, glew, and glm submodules

On linux:
cmake make g++ libx11-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxrandr-dev libxext-dev libxcursor-dev libxinerama-dev libxi-dev
libfreetype6-dev libudev-dev libopenal-dev libvorbis-dev libflac-dev

## Instructions (Tested on Ubuntu 16.04)
```bash
git clone --recurse-submodules https://github.com/xiarandolph/minecraft-cpp
cd minecraft-cpp/
mkdir build
cd build
cmake ..
make
./minecraft-cpp
```

If you cloned without `--recurse-submodules`:
```bash
cd minecraft-cpp/extlibs/
git submodule init
git submodule update
```
