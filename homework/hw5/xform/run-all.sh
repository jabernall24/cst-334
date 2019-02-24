#!/bin/bash
for i in {1..1}; do echo -n "test$i: "; ./test$i.sh; echo $?; done
