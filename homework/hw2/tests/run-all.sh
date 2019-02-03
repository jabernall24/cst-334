#!/bin/bash
for i in {1..5}; do echo -n "test$i: "; ./test$i.sh; echo $?; done

