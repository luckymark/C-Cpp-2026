#include <stdio.h>

void hanoi(int n,char A,char B,char C)
{
    //一个盘子直接移动
    if (n==1) {
        printf("%c-->%c\n",A,C);
        return;
    }
    hanoi(n-1,A,C,B);
    printf("%c-->%c\n",A,C);
    hanoi(n-1,B,A,C);
}

int main() {
    int n;
    printf("请输入盘子数量：");
    scanf("%d",&n);
    hanoi(n,'A','B','C');
    return 0;
}


