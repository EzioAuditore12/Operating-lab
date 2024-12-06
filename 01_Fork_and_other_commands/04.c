#include<stdio.h>
#include<string.h>
int main(){
    char arr1[100],arr2[100],c;
    FILE *f1=fopen("New.txt","r");
    int count=0;
    while(fscanf(f1,"%c",&c)!=EOF){
        arr1[count]=c;
        count++;
    }
    printf("%s",arr1);
    FILE *f2=fopen("New2.txt","r");
    int count2=0;
    while(fscanf(f2,"%c",&c)!=EOF){
        arr2[count2]=c;
        count2++;
    }
    printf("%s",arr2);
}