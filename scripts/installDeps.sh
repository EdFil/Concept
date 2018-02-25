#!/bin/bash

if [ "$(uname)" == "Darwin" ]; then
    # Install brew
    if ! hash brew 2>/dev/null; then
        /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
    fi

    # Install sdl2 libs
    brew install sdl2 sdl2_image sdl2_mixer sdl2_ttf
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    # Ask for sudo
    if [ $EUID != 0 ]; then
        sudo "$0" "$@"
        exit $?
    fi

    # Install sdl2 libs 
    sudo apt-get -y install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
else
    echo "Error. Could not determine OS."
fi