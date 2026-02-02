#!/bin/bash
MAKE="make"
${MAKE}

TESTS_FILES=$(ls src/*.out)

VALGRIND="valgrind"
VALGRIND_FLAGS="--leak-check=full"

for test in ${TESTS_FILES} ; do \
	${VALGRIND} ${VALGRIND_FLAGS} ./${test} ; \
done
