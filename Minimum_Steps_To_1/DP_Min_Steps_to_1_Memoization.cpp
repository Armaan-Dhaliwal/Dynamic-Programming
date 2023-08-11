#include<iostream>
#include<climits>
using namespace std;

int Min_to_One(int n,int* arr){
    if(n==1){
        return 0;
    }

    if(arr[n]!=-1){
        return arr[n];
    }
    
    int a =INT_MAX;
    int b =INT_MAX;

    if(n%2==0){
        a = Min_to_One(n/2,arr);
    }
    if(n%3==0){
        b = Min_to_One(n/3,arr);
    }
    
    int c = Min_to_One(n-1,arr);
    arr[n] = 1+min(a,min(b,c));

    return arr[n];
}

int Parent(int n){
    int *arr = new int[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=-1;    }
    return Min_to_One(n,arr);
}

int main(){
    cout<<"Enter your Number: "<<endl;
    int n;
    cin>>n;
    cout<<Parent(n)<<endl;
}