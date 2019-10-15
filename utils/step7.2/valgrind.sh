#!/bin/bash

valgrind --leak-check=full ./hashtest
valgrind --leak-check=full ./hashtest1
valgrind --leak-check=full ./hashtest2
valgrind --leak-check=full ./hashtest3
valgrind --leak-check=full ./hashtest4
valgrind --leak-check=full ./hashtest5
valgrind --leak-check=full ./hashtest6
