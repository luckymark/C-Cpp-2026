#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
char maze[20][20];
int playerX,playerY;
int cc;
int cnt,tt;
int minSteps[100];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
inline void HideCursor(){
	CONSOLE_CURSOR_INFO cursor_info={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
inline void loadScore(){
	ifstream fin("score.txt");
	if(!fin) return;
	string line;
	while(getline(fin,line)){
		if(line.empty()) continue;
		int nums[2]={0,0},idx=0;
		for(int i=0;i<(int)line.size();i++){
			if(line[i]>='0'&&line[i]<='9'){
				nums[idx]=nums[idx]*10+(line[i]-'0');
			}else if(nums[idx]>0){
				idx++;
				if(idx>=2) break;
			}
		}
		if(nums[0]>0&&nums[1]>0) minSteps[nums[0]]=nums[1];
	}
	fin.close();
}
inline void updateScore(){
	if(minSteps[tt]==0||cnt<minSteps[tt]){
		minSteps[tt]=cnt;
		cout<<"\n恭喜破纪录!!!\n";
	}
	ofstream fout("score.txt");
	for(int i=1;i<=99;i++){
		if(minSteps[i]!=0){
			fout<<"关卡"<<i<<" 最少步数:"<<minSteps[i]<<'\n';
		}
	}
	fout.close();
}
inline bool loadMap(int tt){
	ifstream fin("map"+to_string(tt)+".txt");
	if(!fin) return 0;
	memset(maze,' ',sizeof(maze));
	string line;
	int row=0;
	while(getline(fin,line)&&(++row<=15)){
		int len=line.size();
		for(int j=0;j<len&&j<15;j++){
			maze[row][j+1]=line[j];
			if(line[j]=='P') playerX=row,playerY=j+1;
			if(line[j]=='O') cc++;
		}
	}
	fin.close();
	if((!playerX)||(!playerY)) return 0;
	return 1;
}
inline void put(){
	system("cls");
	cout<<"关卡:"<<tt<<"  步数:"<<cnt<<'\n';
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
	if(maze[nx][ny]=='O'||maze[nx][ny]=='*'){
		int nnx=nx+dx,nny=ny+dy;
		if(maze[nnx][nny]=='#'||maze[nnx][nny]=='O'||maze[nnx][nny]=='*') return;
		if(maze[nx][ny]=='*'){
			cc++;
			maze[nx][ny]='X';
		}
		else maze[nx][ny]=' ';
		if(maze[nnx][nny]=='X'){
			maze[nnx][nny]='*';cc--;
		}
		else maze[nnx][nny]='O';
		if(maze[playerX][playerY]=='+') maze[playerX][playerY]='X';
		else maze[playerX][playerY]=' ';
	}
	else{
		if(maze[playerX][playerY]=='+') maze[playerX][playerY]='X';
		else maze[playerX][playerY]=' ';
	}	
	playerX=nx,playerY=ny;
	if(maze[playerX][playerY]=='X') maze[playerX][playerY]='+';
	else maze[playerX][playerY]='P';	
	cnt++;
	if(!cc){
		put();
		cout<<"\n强强强!!!\n";
		cout<<"本次共用步数："<<cnt<<"步\n";
		updateScore();
		_getch();
		exit(0);
	}
}
int main(){
	srand(time(0));
	HideCursor();	
	loadScore();
	cout<<"请输入您想要玩第几张地图\n";
	cin>>tt;
	if(!loadMap(tt)){
		cout<<"???"; 
		return 0;
	}
	put();
	while(1){
		if(_kbhit()){
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
