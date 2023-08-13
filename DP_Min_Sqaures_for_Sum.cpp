#include<iostream>
#include<math.h>
#include<climits>
using namespace std;

int main(){
    cout<<"Enter your number: "<<endl;
    int n;
    cin>>n;
    int* arr = new int[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        int min =INT_MAX;
        int s = sqrt(i);
        for(int j=1;j<=s;j++){
            int temp = i-j*j;
            if(arr[temp]+1<min){
                min=1+arr[temp];
            }
        }
        arr[i]=min;
    }
    cout<<arr[n]<<endl;
}