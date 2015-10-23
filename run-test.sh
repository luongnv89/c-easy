if [ -f easyCunit ]; then
	echo "*** CLEANUP ***"
	rm easyCUnit	
fi

echo "*** START COMPILING ***"

gcc -Wall -g -o easyCunit easyCUnit.c easy.c -lcunit

if [ -f easyCunit ]; then
	echo "*** FINISHED COMPILING. START TESTING ***"
	./easyCUnit
fi
