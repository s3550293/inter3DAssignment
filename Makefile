LIBS = -lglut -lGLU -lGL
prim: prim.c
    gcc -o prim prim.c $(LIBS)