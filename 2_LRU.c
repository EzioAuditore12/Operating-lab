#include<stdio.h>
int size;
int isFull=0;
void put_in_least(int var,int arr[2][size],int time){
    int min_val=arr[1][0];
    int least_index=0;
    for(int i=0;i<size;i++){
        if(arr[1][i]<min_val){
            min_val=arr[1][i];
            least_index=i;
        }
    }
    arr[0][least_index]=var;
    arr[1][least_index]=time;
}

int find(int element,int arr[2][size],int time){
    for(int i=0;i<size;i++){
        if(arr[0][i]==element){
                arr[1][i]=time;
                return 1;
        }
    }
    return 0;
}

int hit_or_miss(int input, int arr[2][size],int time){
 int get=find(input,arr,time);
 if(get==1){
    return 1;
 }
 if(isFull<size){
    arr[0][isFull]=input;
    arr[1][isFull]=time;
    isFull++;
    return 1;
 }

 put_in_least(input,arr,time);
 return 0;
}
int main()
{
int n;
printf("Enter the size of frame:");
scanf("%d",&size);
int arr[2][size];
printf("Enter the number of page reference:");
scanf("%d",&n);
for(int i=0;i<size;i++){
    arr[0][i]=-1;
    arr[1][i]=0;
}
int miss=0,hit=0;
for(int i=0;i<n;i++){
    int var;
    scanf("%d",&var);
    int check=hit_or_miss(var,arr,i);
    if(check==1){
        hit++;
    }
    else{
        miss++;
    }
}
printf("Misses are: %d",miss);
return 0;
}