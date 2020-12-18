# Installation

The project uses make to build and install the application.

In order to build application you should install the following depenedencies.

    - libusb-1.0.0 development files
    - gcc 
    - cmake, make to build and install

The tool to install dependencies varies depending on the used Linux 
distribution.

On Debian based system the installation goes like this:

    sudo apt-get install build_essential cmake libusb-1.0.0-dev


Outside of  the project directory create a folder where the build will take 
place:

    mkdir ~/out
    cd ~/out

Execute cmake to generate the makefiles:

    cmake <path_to_source>

Start the build process using make:

    make

Install the application:

    make install

