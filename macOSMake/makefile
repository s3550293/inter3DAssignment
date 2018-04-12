LIBS = -framework GLUT -framework OpenGL -framework Carbon 
out: prim.c
	gcc -Wno-deprecated-declarations -o prim prim.c boat.c sin.c island.c $(LIBS)
	