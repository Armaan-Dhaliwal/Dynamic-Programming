#include<iostream>
#include<climits>
using namespace std;

int minMCM(int* dimensions, int si, int ei){
    if(si>=ei || ei-si==1){
        return 0;
    }

    if(ei-si==2){
        return dimensions[si]*dimensions[si+1]*dimensions[si+2];
    }

    int min=INT_MAX;
    for(int i=si+1;i<ei;i++){
        int temp = minMCM(dimensions,si,i) + minMCM(dimensions,i,ei) + dimensions[si]*dimensions[i]*dimensions[ei];
        if(temp<min){
            min=temp;
        }
    }
    return min;
}

int main(){
    cout<<"Enter number of matrices: "<<endl;
    int size;
    cin>>size;
    cout<<"Enter dimensions: "<<endl;
    int *dimensions = new int[size+1];
    for(int i=0;i<size+1;i++){
        cin>>dimensions[i];
    }
    cout<<minMCM(dimensions, 0, size);
}