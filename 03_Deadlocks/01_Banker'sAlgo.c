#include<stdio.h>
int pn, rn;
int isStable(int future[pn][rn],int av_rv[rn]){
    int count=0;
    for(int i=0;i<pn;i++){
        for(int j=0;j<rn;j++){
            if(av_rv[j]>=future[i][j]){
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
void vector_add(int arr1[],int arr2[]){
    for(int i=0;i<rn;i++){
        arr1[i]=arr1[i]+arr2[i];
    }
}
void printSeq(int futureMatrix[pn][rn],int allocateMatrix[pn][rn],int av_rv[rn]){
    int pi=0;
    while (isStable(futureMatrix,av_rv)!=-1)
    {
        pi=isStable(futureMatrix,av_rv);
        if(pi!=-1){
            vector_add(av_rv,allocateMatrix[pi]);
            for(int k=0;k<rn;k++){
                futureMatrix[pi][k]=9999;
            }
            printf("p%d->",pi);
        }
    }
    
}
int main()
{
printf("Enter the number of processes you want:");
scanf("%d",&pn);
printf("Enter the number of resources you want:");
scanf("%d",&rn);
int maxMatrix[pn][rn];
int allocMatrix[pn][rn];
int futureMatrix[pn][rn];
printf("Enter the values of maxMatrix:\n");
for(int i=0;i<pn;i++){
    for(int j=0;j<rn;j++){
        scanf("%d",&maxMatrix[i][j]);
    }
}
printf("Enter the values of allocMatrix:\n");
for(int i=0;i<pn;i++){
    for(int j=0;j<rn;j++){
        scanf("%d",&allocMatrix[i][j]);
        futureMatrix[i][j]=maxMatrix[i][j]-allocMatrix[i][j];
    }
}
int resource_vector[rn];
printf("Enter the resource vector:\n");
for(int i=0;i<rn;i++){
    scanf("%d",&resource_vector[i]);
}
int available_resource_vector[rn];
for(int j=0;j<rn;j++){
    available_resource_vector[j]=0;
    for(int i=0;i<pn;i++){
        available_resource_vector[j]+=allocMatrix[i][j];
    }
    available_resource_vector[j]=abs(resource_vector[j]-available_resource_vector[j]);
}
printf("Available Resource vectors are:\n");
for(int i=0;i<rn;i++){
    printf("%d ",available_resource_vector[i]);
}
if(isStable(futureMatrix,available_resource_vector)==-1){
    printf("Request can't be fulfiled");
    return 0;
}
printf("\n");
printSeq(futureMatrix,allocMatrix,available_resource_vector);
return 0;
}