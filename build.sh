#!/bin/sh
cd out/build; make;

cd ../..; rm compile_commands.json;

ln -s out/build/compile_commands.json .


