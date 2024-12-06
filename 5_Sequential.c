#include<stdio.h>
#include<string.h>
int max_disk_size=200;
typedef struct File{
char name[50];
int startBlock;
int length;
}File;
typedef struct Disk{
    int blocks[200];
}Disk;

int allocatedFile(File * file,Disk * disk){
    int start=file->startBlock;
    int end=file->length;

    for(int i=start;i<start+end;i++){
        if(disk->blocks[i]==0){
            disk->blocks[i]=1;
        }
    }
    return 1;
}

void find_file(File files[], int n, char input[]){
for(int i=0;i<n;i++){
if((strcmp(files[i].name, input)) == 0){
printf("\n\nFile Name: %s\n", files[i].name);
printf("Start Block: %d\n", files[i].startBlock);
printf("No. of Blocks: %d\n", files[i].length);
printf("Blocks Occupied: ");
for(int j=files[i].startBlock;j<(files[i].length+files[i].startBlock);j++){
printf("%d, ",j);
}
printf("\n");
break;
}
}
}

int main()
{
int n;
printf("Enter the number of files you want:");
scanf("%d",&n);
File files[n];
Disk disk;
for(int i=0;i<max_disk_size;i++){
    disk.blocks[i]=0;
}
for(int i=0;i<n;i++){
    printf("Enter the file name:");
    scanf("%s",files[i].name);
    printf("Enter the file starting point:");
    scanf("%d",&files[i].startBlock);
    printf("Enter the length of file:");
    scanf("%d",&files[i].length);
    if(allocatedFile(&files[i],&disk)){
        printf("Allocated successfully!\n");
    }
}
char input[50];
printf("Enter the file to be searched:");
scanf("%s",input);
find_file(files,n,input);
return 0;
}