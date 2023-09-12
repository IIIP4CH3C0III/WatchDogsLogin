CC		= gcc
OP		= -Wall
LIB		= -lncurses -lpam

F1		= src/main
F2		= src/display
F3		= src/resources
F4		= src/printing
F5		= src/writting
F6		= src/login
F7		= src/logo

N 		= LoginWD

compile:	${F1}.o ${F2}.o ${F3}.o ${F4}.o ${F5}.o ${F6}.o ${F7}.o  moveF
			${CC} -o ${N} ${F1}.o ${F2}.o ${F3}.o ${F4}.o ${F5}.o ${F6}.o ${F7}.o ${LIB} ${OP};
			rm src/*.o 

${F1}.o:	${F1}.c
			${CC} -c ${F1}.c ${OP}

${F2}.o:	${F2}.c
			${CC} -c ${F2}.c ${OP}

${F3}.o:	${F3}.c
			${CC} -c ${F3}.c ${OP}

${F4}.o:	${F4}.c
			${CC} -c ${F4}.c ${OP}

${F5}.o:	${F5}.c
			${CC} -c ${F5}.c ${OP}

${F6}.o:	${F6}.c
			${CC} -c ${F6}.c ${OP}

${F7}.o:	${F7}.c
			${CC} -c ${F7}.c ${OP}

moveF:
			mv *.o src/

			
remove:
			rm src/*.o
