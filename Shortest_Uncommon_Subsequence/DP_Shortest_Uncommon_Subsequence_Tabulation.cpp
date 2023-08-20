#include<iostream>
#include<vector>
#include<string>
using namespace std;

int shortestUnSub(string S, string T) {
          int arr[501][501];
          int s=S.length();
          int t=T.length();
          
          arr[s][t]=501;
          for(int i=0;i<501;i++){
              for(int j=0;j<501;j++){
                  if(i>=s){
                      arr[i][j] = 501;
                  }
                  else if(j>=t){
                    arr[i][j] = 1;
                }
              }
          }
          
          for(int i=s-1;i>=0;i--){
              for(int j=t-1;j>=0;j--){
                    int k = j;
                    while(k<T.size()){
                        if(S[i]==T[k]){
                            break;
                        }
                        k++;
                    }
                
                if(k==T.size()){
                    arr[i][j] =  1;
                    continue;
                }
                
                arr[i][j] = min(arr[i+1][j], 1+arr[i+1][k+1]);
            }
        }
        //cout<<arr[0][0]<<endl;
        if(arr[0][0]>=501){
            return -1;
        }
        return arr[0][0];
    }
    