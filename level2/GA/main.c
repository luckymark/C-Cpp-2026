#include<bits/stdc++.h>
using namespace std;
char maze[20][20];
int sx,sy,ex,ey;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
struct Ind{
    char p[61];//移动序列(基因) 
    int w;//权值 
    int x,y;
}pop[105];
inline void load(){
    ifstream fin("map.txt");
    string line;
    for(int i=1;i<=15;i++){
        getline(fin,line);
        for(int j=1;j<=15;j++){
            if(j<=(int)line.size()) maze[i][j]=line[j-1];
            else maze[i][j]=' ';
            if(maze[i][j]=='P') sx=i,sy=j;
            if(maze[i][j]=='E') ex=i,ey=j;
        }
    }
    fin.close();
}
inline void calc(Ind &a){
    int X=sx,Y=sy;
    int step=0;
    for(int i=1;i<=60;i++){
    	step++;
        int d=a.p[i];
        int nx=X+dx[d],ny=Y+dy[d];
        if(nx<1||nx>15||ny<1||ny>15||maze[nx][ny]=='#') continue;
        X=nx,Y=ny;
        if(X==ex&&Y==ey) break;
    }
    a.x=X,a.y=Y;
    int dis=abs(X-ex)+abs(Y-ey);
    if(X==ex&&Y==ey) a.w=100000-step*100;
    else a.w=100000-dis*200-step*100;
}
inline void draw(Ind &a){
    int cx=sx,cy=sy;
    for(int i=1;i<=60;i++){
        int d=a.p[i];
        int nx=cx+dx[d],ny=cy+dy[d];
        if(nx<1||nx>15||ny<1||ny>15||maze[nx][ny]=='#') continue;
        cx=nx,cy=ny;
        if(cx==ex&&cy==ey) break;
        if(maze[cx][cy]==' ') maze[cx][cy]='o';
    }
    for(int i=1;i<=15;i++){
        for(int j=1;j<=15;j++) cout<<maze[i][j];
        cout<<'\n';
    }
}
int cmp(Ind x,Ind y){
	return x.w>y.w;
}
int main(){
    srand(time(0));
    load();
    for(int i=1;i<=100;i++){
        for(int j=1;j<=60;j++) pop[i].p[j]=rand()%4;
        calc(pop[i]);
    }
    clock_t st=clock();
    int f=0;
    for(int g=1;g<=10000||(!f);g++){
    	f=0;
        for(int i=1;i<=100;i++) calc(pop[i]);
        sort(pop+1,pop+101,cmp);
         if(pop[1].x==ex&&pop[1].y==ey) f=1;
        for(int i=21;i<=100;i++){//后80为杂交变异所得
            int a=rand()%20+1,b=rand()%20+1;
            int p=rand()%60+1;
            for(int k=1;k<p;k++) pop[i].p[k]=pop[a].p[k];
            for(int k=p;k<=60;k++) pop[i].p[k]=pop[b].p[k];
            if(rand()%100<5) pop[i].p[rand()%60+1]=rand()%4;
        }
    }
    draw(pop[1]);
    clock_t en=clock();
    cout<<"耗时: "<<(en-st)*1000.0/CLOCKS_PER_SEC<<"ms\n";
    return 0;
}
