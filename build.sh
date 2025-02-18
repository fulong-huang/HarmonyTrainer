#!/bin/sh
rm compile_commands.json;

cd out/build; make;

cd ../..; ln -s out/build/compile_commands.json .


