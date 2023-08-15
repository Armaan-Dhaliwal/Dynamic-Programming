#include<iostream>
#include<math.h>
using namespace std;
//2D Memoization: 

int Recursive_Count(int **arr,int n, int sum, int si){
    if(si>n){
        return 0;
    }

    if (sum<0)
    {
        return 0;
    }
    
    if(sum==0){
        return 1;
    } 

    if(arr[sum][si]!=-1){
        return arr[sum][si];
    }
    

    int count=0;
    for(int i=si;i<=n;i++){
        count+= Recursive_Count(arr,n,sum-i,i);
    }
    if(count!=0){
        arr[sum][si]=count;
        //cout<<" at "<<sum<<" : "<<arr[sum][si]<<endl;
    }
    
    return count;
}

int Wrapper(int count, int n, int sum, int si){
    int** arr = new int*[sum+1];
    for(int i=0;i<sum+1;i++){
        arr[i]= new int[n+1];
    }

    for(int i=0;i<sum+1;i++){
        for(int j=0;j<n+1;j++){
            arr[i][j]=-1;
        }
    }
    
    return Recursive_Count(arr,n,sum,si);

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
    cout<<Wrapper(count,size,sum,1)<<endl;
    //cout<<count<<endl;
}