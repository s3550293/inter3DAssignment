@echo off


mkdir build

pushd build

cl ../prim.c ../sin.c ../boat.c ../island.c ../projectile.c user32.lib gdi32.lib opengl32.lib glu32.lib glut32.lib
REM cl ../run.c user32.lib gdi32.lib opengl32.lib glu32.lib glut32.lib

popd