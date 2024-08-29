/*
============================================================================
Name : 1a.c
Author : Divy Pagariya
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 22th Aug, 2024.
============================================================================
*/



#include<unistd.h>
#include<stdio.h>


int main() {
    if(symlink("sample.txt", "softlink2") == 0){
        printf("Succesfully Created \n");
    } else {
        perror("Error Creating");
    }
    
    return 0;
}
