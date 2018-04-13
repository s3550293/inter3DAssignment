LIBS = -lglut -lGLU -lGL -lm
prim: prim.c
	gcc -o prim prim.c boat.c island.c sin.c util.c projectile.c $(LIBS)