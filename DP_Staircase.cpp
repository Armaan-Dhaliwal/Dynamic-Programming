#include<iostream>
using namespace std;

int main(){
    cout<<"Enter your Number: "<<endl;
    int n;
    cin>>n;

    int *arr = new int[n+1];
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr[3]=1+arr[2]+arr[1];
    for(int i=4;i<=n;i++){
        arr[i]=arr[i-3]+arr[i-2]+arr[i-1];
    }
    cout<<arr[n]<<endl;
}