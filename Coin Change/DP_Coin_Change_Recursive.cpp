#include<iostream>
#include<math.h>
using namespace std;

void Recursive_Count(int &count, int n, int sum, int si){
    if(si>n){
        return;
    }

    if (sum<0)
    {
        return;
    }
    
    if(sum==0){
        count++;
        return;
    }

    for(int i=si;i<=n;i++){
        Recursive_Count(count,n,sum-i,i);
    }
    
}

int main(){
    cout<<"Enter number of coins: "<<endl;
    int size;
    cin>>size;
    int *nums = new int[size];
    for(int i=0;i<size;i++){
        nums[i]=i+1;
    }
    cout<<"Enter sum:"<<endl;
    int sum;
    cin>>sum;

    int count=0;
    Recursive_Count(count,size,sum,1);
    cout<<count<<endl;
}