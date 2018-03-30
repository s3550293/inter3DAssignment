LIBS = -lglut -lGLU -lGL -lm
prim: prim.c
    gcc -o prim prim.c $(LIBS)