#!/bin/bash

exists()
{
    command -v "$1" > /dev/null 2 >& 1
}

if exists tar; then
    echo 'tar is already installed'
    exit 0
fi

if exists apt-get; then
    # Debian
    sudo apt-get update
    sudo apt-get install -y tar

elif exists yum; then
    # Redhat
    sudo yum install -y tar

elif exists pacman; then
    # Archlinux
    sudo pacman -Sy --noconfirm tar

elif exists apk; then
    # Alpine
    sudo apk add --update tar

elif exists dnf; then
    # Fedora
    sudo dnf install -y tar

elif exists zypper; then
    # Opensussy
    sudo zypper install -y tar

elif exists brew; then
    # MacOS
    brew install tar

elif exists port; then
    # MacOS
    sudo port install gtar

elif exists pkg; then
    # FreeBSD
    sudo pkg install -y libarchive

elif exists emerge; then
    # Gentoo
    sudo emerge --ask --noreplace app-arch/tar

elif exists eopkg; then
    # Solus
    sudo eopkg install -y tar

elif exists guix; then
    # Guix
    sudo guix package -i tar

else
    echo 'Unsupported package manager, install tar manually'
    exit 1
fi

if exists tar; then
    echo 'tar was successfully installed'
    exit 0
else
    echo 'There was an error, please install tar manually'
    exit 1
fi

