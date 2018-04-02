@echo off


mkdir build

pushd build

cl ../prim.c ../sin.c ../boat.c user32.lib gdi32.lib opengl32.lib glu32.lib glut32.lib

popd