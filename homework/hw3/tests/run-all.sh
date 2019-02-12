#!/bin/bash
for i in {1..6}; do echo -n "test$i: "; ./test$i.sh; echo $?; done
