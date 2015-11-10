valgrind -v --track-origins=yes --leak-check=full --show-leak-kinds=all --read-var-info=yes --workaround-gcc296-bugs=yes ./easyCUnit 2> valgrind_test_00$1.log
