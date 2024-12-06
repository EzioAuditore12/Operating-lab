#include<bits/stdc++.h>
using namespace std;
int n;
int disk_size=200;
void SCAN(vector<int> & arr,int head){
    vector<int> left,right;
  
        right.push_back(disk_size-1);
    
        left.push_back(0);
    
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
   
        for(int i=0;i<right.size();i++){
            seek_sequence.push_back(right[i]);
            distance=abs(right[i]-head);
            seek_count+=distance;
            head=right[i];
        }
        head=0;
        seek_count+=(disk_size-1);
        for(int i=0;i<left.size();i++){
            seek_sequence.push_back(left[i]);
            distance=abs(left[i]-head);
            seek_count+=distance;
            head=left[i];
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
    CSCAN(arr,head);
}