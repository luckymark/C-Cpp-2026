#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define ROWS 7
#define COLS 9
char maze[ROWS][COLS]={
    {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'P', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', 'E', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#'}
};
int playerx=1;
int playery=1;

void draw(){
    system("cls");

    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
    printf("\n操作提示:请使用【上下左右】方向键移动玩家 P。\n");
}

char get_direction_key(){
    int ch =_getch();
    if(ch==224||ch==0){
        ch=_getch();
        switch(ch){
            case 72:return'w';
            case 80:return's';
            case 75:return'a';
            case 77:return'd';
        }
    }
    return 0;
        
}
int main(){
    char dir;

    while(1){
        draw();
        dir=get_direction_key();

        int newx=playerx;
        int newy=playery;
        switch (dir){
            case 'w':newy--;break;
            case 's':newy++;break;
            case 'a':newx--;break;
            case 'd':newx++;break;
            default:continue;
        }
    if (maze[newy][newx]=='#'){
        continue;
    }
    if (maze[newy][newx]=='E'){
        maze[playery][playerx]=' ';
        playery = newy;
        playerx = newx;
        maze[playery][playerx]='P';


        draw();
        printf("\n恭喜通关\n");
        break;
    }
    maze[playery][playerx]=' ';
        playery = newy;
        playerx = newx;
        maze[playery][playerx]='P';
    }
    return 0;
}
