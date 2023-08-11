#include<iostream>
using namespace std;

int Min_to_One(int n){
    if(n==1){
        return 0;
    }
    
    if(n%2==0 && n%3==0){
        return 1+min(Min_to_One(n-1),min(Min_to_One(n/3),Min_to_One(n/2)));
    }
    else if(n%2==0 && n%3!=0){
        return 1+min(Min_to_One(n-1),Min_to_One(n/2));
    }
    else if(n%2!=0 && n%3==0){
        return 1+min(Min_to_One(n-1),Min_to_One(n/3));
    }
    // else{
        return 1+Min_to_One(n-1);
    // }
}

int main(){
    cout<<"Enter your Number: "<<endl;
    int n;
    cin>>n;
    cout<<Min_to_One(n)<<endl;
}