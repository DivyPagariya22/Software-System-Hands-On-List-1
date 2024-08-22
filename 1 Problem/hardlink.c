#include<unistd.h>

int main() {
    link("sample.txt", "hardlink2");
    return 0;
}
