#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <string.h>
#define ROWS 6
#define COLS 7
char maze[ROWS][COLS];
/*char maze[ROWS][COLS]={
    {'#', '#', '#', '#', '#', '#', '#', },
    {'#', 'P', ' ', ' ', ' ', ' ', '#', },
    {'#', ' ', ' ', '@', ' ', ' ', '#', },
    {'#', ' ', ' ', ' ', ' ', 'E', '#', },
    {'#', ' ', ' ', ' ', ' ', ' ', '#', },
    {'#', '#', '#', '#', '#', '#', '#', }
};*/
//p+E=*  @+E=^
int playerx=1;
int playery=1;
int steps=0;

void draw(){
    system("cls");

    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
    printf("\n当前步数:%d\n",steps);
    printf("\n操作提示:请使用【上下左右】方向键移动玩家 P。\n");
}

char get_direction_key(){
    int ch =_getch();
    if (ch == 'q' || ch == 'Q' || ch == 27) return 'q';
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


int check(){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if (maze[i][j] == '@' || maze[i][j] == 'E'){
                return 0; 
            }
        }
    }
    return 1; 
}

void load_map(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("无法打开地图文件 %s\n", filename);
        exit(1); 
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            char c = fgetc(file);
            while(c == '\n' || c == '\r') c = fgetc(file); 
            maze[i][j] = c;
            if (c == 'P') { 
                playery = i;
                playerx = j;
            }
        }
    }
    fclose(file);
}

void save_score(int level, int steps) {
    FILE* file = fopen("scores.txt", "a");
    if (file != NULL) {
        fprintf(file, "关卡: %d | 步数: %d\n", level, steps);
        fclose(file);
    }
}

int main(){
    char dir;
    int current_level = 1;
    load_map("level1.txt");

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
            case 'q':
                system("cls");
                printf("游戏已退出。\n");
                exit(0);
            default:continue;
        }
        if (newx < 0 || newx >= COLS || newy < 0 || newy >= ROWS) {
            continue;
        }
        if (maze[newy][newx]=='#'){
            continue;
        }else if (maze[newy][newx]==' '||maze[newy][newx]=='E'){
            maze[playery][playerx]=(maze[playery][playerx]=='*')?'E':' ';
            playery = newy;
            playerx = newx;
            maze[playery][playerx]=(maze[playery][playerx]=='E')?'*':'P';
            steps++;
        }else{
            int boxnexty=newy+(newy-playery);
            int boxnextx=newx+(newx-playerx);
            if (boxnexty < 0 || boxnexty >= ROWS || boxnextx < 0 || boxnextx >= COLS) {
                continue;
            }
            if(maze[boxnexty][boxnextx]=='#'||maze[boxnexty][boxnextx]=='@'||maze[boxnexty][boxnextx]=='^'){
                continue;
            }
            char preplayer=maze[playery][playerx];
            char prebox=maze[newy][newx];
            maze[boxnexty][boxnextx]=(maze[boxnexty][boxnextx]=='E')?'^':'@';
            maze[playery][playerx]=(preplayer=='*')?'E':' ';
            playery = newy;
            playerx = newx;
            maze[playery][playerx]=(prebox=='^')?'*':'P';
            steps++;
        }
        if(check()){
            printf("\n恭喜通关!\n");
            save_score(current_level, steps); 
            steps = 0; 
            current_level++; 
            
            
            char next_file[20];
            sprintf(next_file, "level%d.txt", current_level);
            FILE* f = fopen(next_file, "r");
            if (f == NULL) {
                printf("所有关卡通关！游戏结束。\n");
                break;
            }
            fclose(f);
            
            load_map(next_file); 
            system("pause");
            continue; 
        }
        
    }
    return 0;
}
