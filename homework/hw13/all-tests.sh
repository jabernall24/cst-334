#!/bin/bash

for i in test*.sh; do echo -n $i": "; ./$i; echo $?; done
