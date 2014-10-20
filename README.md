me-versus-it
============

A game were player will get angry against computer, offers very intense gameplay for a short period of time.
[ ![Codeship Status for PuKoren/me-versus-it](https://www.codeship.io/projects/452d9840-3a93-0132-083a-261a2707f8ca/status)](https://www.codeship.io/projects/42405)

#how to build
###Windows with Visual Studio
[Download SDL2](https://www.libsdl.org/download-2.0.php) VC developpement library and [SDL2-ttf](https://www.libsdl.org/projects/SDL_ttf/) VC developpement library from the official websites. Then you have to extract the content of the archives is the project folder named "libs".  
Latest versions used in project are SDL2 2.0.3 and SDL2_ttf 2.0.12  
  
Copy the extracted folder's content into the corresponding folders in the project (we don't bundle the dll and lib files because there is not point in versionning it)

###Linux with CMake (Debian)  

    apt-get install g++ cmake libsdl2-dev libsdl2-ttf-dev 

**On Debian < sid, you have to manually compile and install libsdl2-ttf.**
***
**ONLY ON DEBIAN < SID:**  
You have a dependency with libfreetype6-dev to build libsdl2-ttf from sources

    apt-get install libfreetype6-dev  
Download the sources of [SDL2-ttf](https://www.libsdl.org/projects/SDL_ttf/)

    ./configure
    make
    sudo make install
**Warning**: It will install in /usr/local/include/SDL2 while FindSDL2.cmake is using default install in /usr/include/SDL2. So you may want to make a symbolic link

    ln -s /usr/local/include/SDL2/SDL_ttf.h /usr/include/SDL2/SDL_ttf.h
***

Then build me-versus-it in a folder named "build", and create a symlink to the resources folder

    mkdir build  
    cd build  
    cmake ../.  
    make  
    ln -s ../resources .  

You're done !
