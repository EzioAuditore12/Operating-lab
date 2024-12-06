#include<stdio.h>
int findElement(int element,int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]==element){
            return 1; 
        }
    }
    return 0;
}
int hit_or_miss(int input,int arr[],int *ptr,int n){
    int get=findElement(input,arr,n);
    if(get==1){
        return 1;
    }
    if(*ptr==n){
        *ptr=0;
    }
    arr[*ptr]=input;
    (*ptr)++;
    return 0;
}
int main()
{
int size;
printf("Enter the frame size");
scanf("%d",&size);
int n;
printf("Enter the no. of page references you want:");
scanf("%d",&n);
int arr[size];
int temp=0,hit=0,miss=0;
int * ptr=&temp;
for(int i=0;i<n;i++){
    int var;
    scanf("%d",&var);
    int check=hit_or_miss(var,arr,ptr,size);
    if(check==1){
        hit++;
    }
    else{
        miss++;
    }
}
printf("Number of misses are: %d",miss);
return 0;
}