#include<bits/stdc++.h>
using namespace std;
int n;
int disk_size=200;
void SCAN(vector<int> & arr,int head,int direction){
    vector<int> left,right;
    if(direction==1){
        right.push_back(disk_size-1);
    }
    else{
        left.push_back(0);
    }
    for(int i=0;i<n;i++){
        if(head>arr[i]){
            left.push_back(arr[i]);
        }
        else{
            right.push_back(arr[i]);
        }
    }
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    vector<int> seek_sequence;
    int distance;
    int seek_count=0;
    int run=2;
    while(run--){
    if(direction==0){
        for(int i=left.size()-1;i>=0;i--){
            seek_sequence.push_back(left[i]);
            distance=abs(left[i]-head);
            seek_count+=distance;
            head=left[i];
        }
        direction=1;
    }
    else if(direction==1){
        for(int i=0;i<right.size();i++){
            seek_sequence.push_back(right[i]);
            distance=abs(right[i]-head);
            seek_count+=distance;
            head=right[i];
        }
        direction=0;
    }
    }
    printf("Total num of seek operations %d\n",seek_count);
}
int main(){
    printf("Enter the number of disk requests:");
    scanf("%d",&n);
    vector<int> arr;
    for(int i=0;i<n;i++){
        int var;
        cin>>var;
        arr.push_back(var);
    }
    int head;
    cout<<"Enter the head:";
    cin>>head;
    int direction;
    cout<<"Please enter 1 for right and 0 for left:";
    cin>>direction;
    SCAN(arr,head,direction);
}