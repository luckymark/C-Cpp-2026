#include <stdio.h>
#include <windows.h>
int main() {

    const int width =40;
    char letter[] = "0";
    int pos =0;
    int direction = 1;
    while(1) {
        system("cls");
        for (int i=0; i < pos; i++) {
            printf("");
        }
        printf("%s\n",letter);


        pos+= direction;
        if (pos>=width-1) {
            pos=width-1;
            direction=-1;
        }else if (pos<=0) {
            pos=0;
            direction=1;
        }

        Sleep(50);
    }
    return 0;
}