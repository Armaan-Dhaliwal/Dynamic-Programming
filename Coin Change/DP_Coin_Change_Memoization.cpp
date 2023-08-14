#include<iostream>
#include<math.h>
using namespace std;

void Recursive_Count(int arr[], int &count, int n, int sum, int si){
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

    if(arr[sum]!=-1){
        count+= arr[sum];
        return;
    }

    for(int i=si;i<=n;i++){
        Recursive_Count(arr,count,n,sum-i,i);
    }
    
}

void Wrapper(int &count, int n, int sum, int si){
    int* arr = new int[sum+1];
    for(int i=0;i<sum+1;i++){
        arr[i]=-1;
    }
    
    Recursive_Count(arr,count,n,sum,si);

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
    Wrapper(count,size,sum,1);
    cout<<count<<endl;
}