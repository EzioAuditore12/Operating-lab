#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of terms you want:");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int seek_movement=0;
    for(int i=0;i<n;i++){
        seek_movement+=abs(arr[i+1]-arr[i]);
    }
    printf("Seek movemenet is %d",seek_movement);
return 0;
}