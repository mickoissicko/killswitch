#!/bin/bash

exists()
{
    command -v "$1" > /dev/null 2 >& 1
}

if exists python3; then
    echo 'Python is already installed'
    exit 0
fi

if exists apt-get; then
    # Debian
    sudo apt-get update
    sudo apt-get install -y python3

elif exists yum; then
    # Redhat
    sudo yum install -y python3

elif exists pacman; then
    # Archlinux
    sudo pacman -Sy --noconfirm python

elif exists apk; then
    # Alpine
    sudo apk add --update python3

elif exists dnf; then
    # Fedora
    sudo dnf install -y python3

elif exists zypper; then
    # Opensussy
    sudo zypper install -y python3

else
    echo 'Unsupported package manager, install Python manually'
    exit 1
fi

if exists python3; then
    echo 'Python was sucessfully installed'
    exit 0

else
    echo 'There was an error, please install Python manually'
    exit 1
fi

