#include<iostream>
using namespace std;

//Bottom-up approach: Dynamic Programming
//Generally Iterative
int main(){
    int n;
    cout<<"Enter your number: "<<endl;
    cin>>n;
    int *arr = new int[n+1];
    arr[0]=0;
    arr[1]=1;
    if(n==1 || n==0){
        cout<<n<<endl;
    }
    else{
        for(int i=2;i<=n;i++){
            arr[i]=arr[i-1]+arr[i-2];
        }  
        cout<<arr[n]<<endl;
    }
    
}