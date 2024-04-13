#!/bin/bash

# Wow I love Bash scripting
# So elegant
# Unlike Batch
# Python-like syntax, easy readablity
# Curly braces...
# Ruby-looking statements
# What more would you want?

CheckPy()
{
    command -v "$1" >/dev/null 2>&1
}

GetPyDeb()
{
    sudo apt update
    sudo apt install -y python3
}

GetPyRedHat()
{
    sudo yum update
    sudo yum install -y python3
}

GetPyArchLinux()
{
    sudo pacman -Syu --noconfirm python
}

GetPyExpensivePC()
{
    brew update
    brew install python
}

Oh_Shit()
{
    echo "Install it yourself, your system is stupid."
    exit 1
}

if CheckPy python3; then
    echo "Python is already installed."
    exit 0
fi

if CheckPy apt; then
    GetPyDeb
elif CheckPy yum; then
    GetPyRedHat

elif CheckPy pacman; then
    GetPyArchLinux

elif CheckPy brew; then
    GetPyExpensivePC
else
    Oh_Shit
fi

