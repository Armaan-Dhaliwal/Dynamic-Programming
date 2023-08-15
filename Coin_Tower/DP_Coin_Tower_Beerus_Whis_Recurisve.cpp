#include<iostream>
using namespace std;

// 0: Beerus
// 1: Whis
bool Winner(int N, int* arr, bool turn){
    if(N==0){
        return (turn==0?1:0);
    }

    if(N<0){
        return (turn==0?0:1);
    }

    bool res1 = Winner(N-arr[0],arr,!turn);
    bool res2 = Winner(N-arr[1],arr,!turn);
    bool res3 = Winner(N-arr[2],arr,!turn);
    bool result = res1 || res2 || res3;

    if(res1==turn){
        //return Winner(N-arr[0],arr,!turn);
		return res1;
    }
    if(res2==turn){
        // return  Winner(N-arr[1],arr,!turn);
		return res2;
    }
    if(res3==turn){
        // return Winner(N-arr[2],arr,!turn);
		return res3;
    }
        return result;
}

int main(){
    cout<<"Enter value of N:"<<endl;
    int N;
    cin>>N;
    int arr[3]={1,2,3};
    cout<<"Enter two moves: "<<endl;
    cin>>arr[1];
    cin>>arr[2];

    cout<<Winner(N,arr,0);
}