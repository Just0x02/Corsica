#!/usr/bin/env bash

set -e
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

if [ ! -x "$(command -v apt)" ] || [ ! -x "$(command -v apt-get)" ]; then
  echo 'Error: neither apt nor apt-get are installed.' >&2
  exit 1
fi


RED='\033[0;31m'
GREEN='\033[3;92m'
BGREEN='\033[1;92m'
YELLOW='\033[1;33m'

NC='\033[0m'

clear;

printf "${YELLOW}Installing required C/C++ headers and dependencies...${NC}\n"

printf "${YELLOW}Installing misc. libraries for C++ ${NC}"
start=`date +%s%N`
apt-get -y -qq install cmake build-essential g++ autotools-dev libicu-dev libbz2-dev libnoise-dev
end=`date +%s%N`
printf "${GREEN} => Finished in $(expr $end / 1000000 - $start / 1000000)MS!${NC}\n"

printf "${YELLOW}Installing headers for C++ Boost ${NC}"
start=`date +%s%N`
apt-get -y -qq install libboost-all-dev
end=`date +%s%N`
printf "${GREEN} => Finished in $(expr $end / 1000000 - $start / 1000000)MS!${NC}\n"

printf "${YELLOW}Installing headers for OpenGL & GLFW ${NC}"
start=`date +%s%N`
apt-get -y -qq install libglu1-mesa-dev freeglut3-dev mesa-common-dev libglfw3
end=`date +%s%N`
printf "${GREEN} => Finished in $(expr $end / 1000000 - $start / 1000000)MS!${NC}\n"

printf "${YELLOW}Attempting to perform test build...${NC}\n"
cd $SCRIPT_DIR;
cd ../../;
printf "${YELLOW}Building at $PWD...${NC}\n"

make silent-fast

if [ $? -eq 0 ]; then
    printf "${GREEN}Build succeeded!${NC}\n"
else
    printf "${RED}Build failed!${NC}\n"
    exit 1
fi

printf "${GREEN}Cleaning build binaries...${NC}\n"
make clean
printf "${BGREEN}Installation complete!${NC}\n"