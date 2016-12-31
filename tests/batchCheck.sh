#!/bin/bash
while true
do
	./shuffle.exe
	./recover.exe
	./checker.exe
	read -rsp $'Press any key to continue...\n' -n 1 key
done
