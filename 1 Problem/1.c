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
