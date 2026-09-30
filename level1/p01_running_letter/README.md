#include<bits/stdc++.h>
#include <windows.h>
using namespace std;
//用了关闭光标和查询显示屏宽度函数来符合任务要求 
void HideCursor(){
CONSOLE_CURSOR_INFO cursor_info={1,0};
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
int getConsoleWidth(){
CONSOLE_SCREEN_BUFFER_INFO csbi;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
return csbi.srWindow.Right-csbi.srWindow.Left+1;
}
int main(){
    HideCursor();
    int cnt=0,f=0;
    int N=getConsoleWidth()-1;//这里a恰好卡到边界
	//部分显示器可能导致到下一行 调整一下即可 
    while(1){;
        system("cls");
        for(int i=0;i<cnt;i++) cout<<' ';
        cout<<'a'<<flush;
        Sleep(50);
        if(!f){
            cnt++;
            if(cnt>=N){
                cnt=N;
                f=1;
            }
        }
        else{
            cnt--;
            if(!cnt) f=0;
        }
    }
    return 0;
}
