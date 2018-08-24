# README

## Build

Ubuntu 16.04


    sudo apt-get install libprotobuf-dev
    sudo apt-get install protobuf-compiler

    /usr/bin/protoc -I=src --cpp_out=src src/addressbook.proto
