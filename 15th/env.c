/*
============================================================================
Name : 15.c
Author : Divy Pagariya
Description : Write a program to display the environmental variable of the user (use environ).
Date: 23th Aug, 2024.
============================================================================
*/

#include <stdio.h>

extern char **environ;

int main() {
	char **env = environ;

	while(*env) {
		printf("%s\n", *env);
		env++;
	}

	return 0;
}