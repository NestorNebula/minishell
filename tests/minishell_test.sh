#!/bin/bash
MAKE="make"
${MAKE}

TESTS_FILES=$(ls src/*.out)

for test in ${TESTS_FILES} ; do \
	./${test} ; \
done
