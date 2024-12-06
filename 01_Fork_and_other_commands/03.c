#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
int main(){
    DIR *dir;
    struct dirent * entry;
    dir=opendir(".");
    while((entry=readdir(dir))!=NULL){
        printf("%s\n",entry->d_name);
    }
    closedir(dir);
}