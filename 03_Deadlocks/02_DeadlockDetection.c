#include<stdio.h>
int pn,rn;
int isStable(int FutureMatrix[pn][rn],int av_rv[rn]){
    int count=0;
    for(int i=0;i<pn;i++){
        for(int j=0;j<rn;j++){
            if(av_rv[j]>FutureMatrix[i][j]){
                count++;
            }
        }
        if(count==rn){
            return i;
        }
        count=0;
    }
    return -1;
}
int main()
{
printf("Enter the number of processes you want:");
scanf("%d",&pn);
printf("Enter the number of resources you want:");
scanf("%d",&rn);
int MaxMatrix[pn][rn],allocateMatrix[pn][rn],FutureMatrix[pn][rn];
int resource_vector[rn],allocate_resource_vector[rn];
printf("Enter the MaxMatrix:\n");
for(int i=0;i<pn;i++){
    for(int j=0;j<rn;j++){
        scanf("%d",&MaxMatrix[i][j]);
    }
}
printf("Enter the allocated Matrix:\n");
for(int i=0;i<pn;i++){
    for(int j=0;j<rn;j++){
        scanf("%d",&allocateMatrix[i][j]);
        FutureMatrix[i][j]=MaxMatrix[i][j]-allocateMatrix[i][j];
    }
}
printf("Enter the resource vector:\n");
for(int i=0;i<rn;i++){
    scanf("%d",&resource_vector[i]);
}
for(int j=0;j<rn;j++){
    allocate_resource_vector[j]=0;
    for(int i=0;i<pn;i++){
        allocate_resource_vector[j]+=allocateMatrix[i][j];
    }
    allocate_resource_vector[j]=abs(resource_vector[j]-allocate_resource_vector[j]);
}
printf("Availale Resource vectors are:\n");
for(int i=0;i<rn;i++){
    printf("%d ",allocate_resource_vector[i]);
}
printf("\n");
if(isStable(FutureMatrix,allocate_resource_vector)==-1){
    printf("Deadlock Detected");
}
else{
    printf("No deadlock detected");
}
return 0;
}