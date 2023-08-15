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


int main(){
    cout<<"Enter number of coins: "<<endl;
    int size;
    cin>>size;

    cout<<"Enter sum:"<<endl;
    int sum;
    cin>>sum;

    int** arr = new int*[sum+1];
    for(int i=0;i<sum+1;i++){
        arr[i]= new int[size+1];
        arr[i][0]=0;
    }

    for(int i=0;i<size+1;i++){
        arr[0][i]=1;
    }

     for (int i = 1; i <= sum; i++) {
        for (int j = 1; j <= size; j++) {
            arr[i][j] = arr[i][j - 1];
            if (i >= j) {
                arr[i][j] += arr[i - j][j];
            }
        }
    }
    cout<<arr[sum][size]<<endl;
}