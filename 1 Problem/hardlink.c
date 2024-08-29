/*
============================================================================
Name : 1b.c
Author : Divy Pagariya
Description : Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call)
Date: 22th Aug, 2024.
============================================================================
*/



#include<unistd.h>

int main() {
    link("sample.txt", "hardlink2");
    return 0;
}
