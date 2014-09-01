me-versus-it
============

A game were player will get angry against computer, offers very intense gameplay for a short period of time.


#how to build
###Windows with Visual Studio
Download and extract SDL2 VC developpement library and SDL2_ttf VC developpement library on the official websites:  
SDL2: https://www.libsdl.org/download-2.0.php  
SDL2_ttf: https://www.libsdl.org/projects/SDL_ttf/  
Latest versions used in project are SDL2 2.0.3 and SDL2_ttf 2.0.12  
  
Copy the extracted folder's content into the corresponding folders in the project (we don't bundle the dll and lib files because there is not point in versionning it)

###Linux with CMake (Debian)  

    apt-get install g++ cmake libsdl2-dev libsdl2-ttf-2.0-0  

On Debian < sid, you have to manually install libsdl2-ttf. To install it, you have some dependencies:

    apt-get install libfreetype6-dev  
Get the sources https://www.libsdl.org/projects/SDL_ttf/

    ./configure
    make
    sudo make install
/!\ Warning ! It install in /usr/local/include/SDL2 while FindSDL2.cmake is using default install in /usr/include/SDL2. So you may want to make a symbolic link

    ln -s /usr/local/include/SDL2/SDL2_ttf.h /usr/include/SDL2/SDL2_ttf.h

Then build me-versus-it in a folder named "build", and create a symlink to the resources folder

    mkdir build  
    cd build  
    cmake ../.  
    make  
    ln -s ../resources .  

You're done !
