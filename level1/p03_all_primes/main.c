#include<stdio.h>
#include<math.h>
#include<time.h>
int main()
{   
    int limit = 1000;
    int count = 0;

    struct timespec start, end;
    timespec_get(&start,TIME_UTC);

    printf("2-%d以内的所有素数为:\n",limit);
    printf("%d",2);
    count++;
    
    for(int num=3;num<=limit;num+=2){
        int isPrime=1;
        int root=(int)sqrt((double)num);
        for(int i=3;i<=root;i+=2){
            if(num%i==0){
                isPrime=0;
                break;
            }
        }
        if(isPrime){
            printf("%d",num);
            count++;
        }

        
           
    }
    timespec_get(&end,TIME_UTC);
    long long elapsed_ns=(end.tv_sec-start.tv_sec)*1000000000LL+(end.tv_nsec-start.tv_nsec);
    double total_time=elapsed_ns/1e9;
    

    printf("\n素数总个数为:%d\n",count);
    printf("总计算时间为:%.6f秒\n",total_time);
    return 0;

}
