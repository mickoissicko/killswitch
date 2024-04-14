#!/bin/bash

exists()
{
    command -v "$1" > /dev/null 2 >& 1
}

if exists wget; then
    echo 'wget is already installed'
    exit 0
fi

if exists apt-get; then
    # Debian
    sudo apt-get update
    sudo apt-get install -y wget

elif exists yum; then
    # Redhat
    sudo yum install -y wget

elif exists pacman; then
    # Archlinux
    sudo pacman -Sy --noconfirm wget

elif exists apk; then
    # Alpine
    sudo apk add --update wget

elif exists dnf; then
    # Fedora
    sudo dnf install -y wget

elif exists zypper; then
    # Opensussy
    sudo zypper install -y wget

elif exists brew; then
    # MacOS
    brew install wget

elif exists port; then
    # MacOS
    sudo port install wget

elif exists pkg; then
    # FreeBSD
    sudo pkg install -y wget

elif exists emerge; then
    # Gentoo
    sudo emerge --ask --noreplace wget

elif exists eopkg; then
    # Solus
    sudo eopkg install -y wget

elif exists guix; then
    # Guix
    sudo guix package -i wget

else
    echo 'Unsupported package manager, install wget manually'
    exit 1
fi

if exists wget; then
    echo 'wget was sucessfully installed'
    exit 0

else
    echo 'There was an error, please install wget manually'
    exit 1
fi

