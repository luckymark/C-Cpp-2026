#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
char maze[20][20];
int playerX=1,playerY=1;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void HideCursor(){
CONSOLE_CURSOR_INFO cursor_info={1,0};
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
inline void dfs(int x,int y){
	maze[x][y]=' ';
	int dirs[4]={0,1,2,3};
	for(int i=4;i>1;i--) swap(dirs[i-1],dirs[rand()%i]);//Fisher-Yates
	for(int i=0;i<4;i++){
		int d=dirs[i];
		int nx=x+dx[d]*2, ny=y+dy[d]*2;
		if(nx>0&&nx<15&&ny>0&&ny<15&&maze[nx][ny]=='#'){
			maze[x+dx[d]][y+dy[d]]=' ';
			dfs(nx,ny);
		}
	}
}
inline void init(){
	memset(maze,'#',sizeof(maze));
	dfs(1,1);//完全随机并判定连通的方法复杂度爆炸 这里采用一些取巧方式
	//即先生成一条合法路径之后再随机打通一些墙来保证可玩性 
	for(int i=1;i<=25;i++) maze[rand()%(13)+2][rand()%(13)+2]=' ';
	maze[13][13]='E';
	playerX=1,playerY=1;
	maze[playerX][playerY]='P';
}
inline void put(){
	system("cls");
	for(int i=1;i<=15;i++){
		for(int j=1;j<=15;j++) cout<<maze[i][j];
		cout<<'\n';
	}
	cout.flush();
}
inline void move(int dx,int dy){
	int nx=playerX+dx,ny=playerY+dy;
	if(nx<1||nx>15||ny<1||ny>15) return;
	if(maze[nx][ny]=='#') return;
	if(maze[nx][ny]=='E'){
		maze[playerX][playerY]=' ';
		maze[nx][ny]='P';
		put();
		cout<<"\n     强强强!!!     \n";
		exit(0);
	}
	maze[playerX][playerY]=' ';
	playerX=nx,playerY=ny;
	maze[playerX][playerY]='P';
}
int main(){
	srand(time(0));
	HideCursor();
	init();//避免枯燥采用了随机地图生成 
	put();
	while(true){
		if(_kbhit()){//同时支持上下左右和WASD操作模式 
			int ch=_getch();
			if(ch==0||ch==224){
				ch=_getch();
				if(ch==72) move(-1,0);
				else if(ch==80) move(1,0);
				else if(ch==75) move(0,-1);
				else if(ch==77) move(0,1);
				put();
			}
			else if(ch=='w'||ch=='W') {move(-1,0);put();}
			else if(ch=='s'||ch=='S') {move(1,0);put();}
			else if(ch=='a'||ch=='A') {move(0,-1);put();}
			else if(ch=='d'||ch=='D') {move(0,1);put();}
		}
	}
	return 0;
}
