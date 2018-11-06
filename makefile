INC_DIRS = -Iinclude

CFLAGS = -c

main: Obj/main.o Obj/auxFunctions.o Obj/fileFunctions.o Obj/functions.o Obj/matrizFunctions.o Obj/permutacion.o
	@ gcc Obj/*.o -o Bin/main.out 
	@ echo "The compilation has been completed successfully!"

Obj/main.o: Src/main.c
	@ echo "Src/main.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) Src/main.c -o Obj/main.o
Obj/auxFunctions.o: Src/auxFunctions.c
	@ echo "Src/auxFunctions.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) Src/auxFunctions.c -o Obj/auxFunctions.o
Obj/fileFunctions.o: Src/fileFunctions.c
	@ echo "Src/fileFunctions.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) Src/fileFunctions.c -o Obj/fileFunctions.o
Obj/functions.o: Src/functions.c
	@ echo "Src/functions.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) Src/functions.c -o Obj/functions.o
Obj/matrizFunctions.o: Src/matrizFunctions.c
	@ echo "Src/matrizFunctions.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) Src/matrizFunctions.c -o Obj/matrizFunctions.o
Obj/permutacion.o: Src/permutacion.c
	@ echo "Src/permutacion.c"
	@ gcc  $(CFLAGS) $(INC_DIRS) Src/permutacion.c -o Obj/permutacion.o

clean:
	@ clear
	@ echo "Cleaning folders.."
	@ rm -rf Obj/*
	@ rm -rf Bin/*
