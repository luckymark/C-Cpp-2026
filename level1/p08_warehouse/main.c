#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXGOOD 100
#define MAXGOODLEN 50
#define FILENAME "inventory.txt"

typedef struct {
    char model[MAXGOODLEN];
    int quantity;
    
}Item;

Item inventory[MAXGOOD];
int item_count=0;

void load_data(){
    FILE *fp=fopen(FILENAME,"r");
    if(fp==NULL){
        return;
    }
    item_count=0;
    while(fscanf(fp,"%49s %d", inventory[item_count].model, &inventory[item_count].quantity) == 2){
        item_count++;
         if (item_count >= MAXGOOD) {
            printf("警告：库存已达最大容量限制！\n");
            break;
    }
    }
    fclose(fp);
}

void save_data(){
    FILE *fp=fopen(FILENAME,"w");
    if(fp==NULL){
        printf("无法保存数据到文件!\n");
        return;
    }
    for(int i=0;i<item_count;i++){
        fprintf(fp,"%s %d\n",inventory[i].model,inventory[i].quantity);
    }
    fclose(fp);
}

void show_inventory(){
    printf("\n---当前库存列表---\n");
    if(item_count==0){
        printf("库存为空！");
        return;
    }
    printf("%-20s|%-10s\n","型号","数量");
    printf("---------------------------------\n");

    for( int i=0;i<item_count;i++){
        printf("%-20s|%-10d\n",inventory[i].model,inventory[i].quantity);
    }
    printf("---------------------------------\n");
    
}


void stock_in(){
    char model[MAXGOODLEN];
    int quantity;
    printf("请输入入库型号");
    scanf("%49s",model);
    printf("请输入入库货物数量");
    scanf("%d",&quantity);
    if(quantity<=0){
        printf("入库数量必须大于0");
        return;
    }
    for (int i=0;i<item_count;i++){
        if(strcmp(inventory[i].model,model)==0){
            inventory[i].quantity+=quantity;
            printf("入库成功 %s当前库存为:%d\n",model,inventory[i].quantity);
            return;

        }
    }

    if(item_count<MAXGOOD){
        inventory[item_count].quantity=quantity;
        strcpy(inventory[item_count].model, model);
        item_count++;
        printf("新货物 %s 入库成功 当前数量:%d\n",model,quantity);
    }else{
        printf("入库失败!库存种类已达上限\n");
    }

}


void stock_out(){
    char model[MAXGOODLEN];
    int quantity;
    printf("请输入出库货物型号:");
    scanf("%49s",model);
    printf("请输入出库货物数量:");
    scanf("%d",&quantity);
    if(quantity<=0){
        printf("出库数量必须大于0");
        return;
    }
    for (int i=0;i<item_count;i++){
        if(strcmp(inventory[i].model,model)==0){
            if(inventory[i].quantity>=quantity){
                inventory[i].quantity-=quantity;
                printf("出库成功 %s 当前库存为:%d\n",model,inventory[i].quantity);
            }else{
                printf("出库失败! %s 库存不足 当前库存为:%d\n",model,quantity);

            }
            return;    

        }
        
    }

    printf("出库失败!未找到型号为 %s 的货物\n",model);




}
int main(){
    int choice;
    load_data();
    while(1){
        printf("\n-----------------------------\n");
        printf("          进销存系统------\n");
        printf("\n-----------------------------\n");
        printf("1,显示存货列表\n");
        printf("2,入库\n");
        printf("3,出库\n");
        printf("4,退出程序\n");
        if(scanf("%d",&choice)!=1){
            while (getchar()!='\n');
            printf("输入无效，请输入数字！\n");
            continue;
            
        }
        while (getchar() != '\n');
        
        switch(choice){
            case 1:
                show_inventory();
                break;
            case 2:
                stock_in();
                break;
            case 3:
                stock_out();
                break;
            case 4:
                save_data();
                printf("数据已保存,退出程序\n");
                return 0;

            default:
                printf("无效操作,请重新输入！\n");
                break;
        }
    }
    return 0;
}
    
    
