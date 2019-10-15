#!/bin/bash

valgrind --leak-check=full ./listtest
valgrind --leak-check=full ./listtest2
valgrind --leak-check=full ./listtest3
valgrind --leak-check=full ./listtest4
