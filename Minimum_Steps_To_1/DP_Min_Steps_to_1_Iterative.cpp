 #include<iostream>
 #include<climits>
 using namespace std;

 int main(){
    
    cout<<"Enter your Number: "<<endl;
    int n;
    cin>>n;

    int *arr = new int[n+1];
    arr[0]=0;
    arr[1]=0;
    arr[2]=1;
    arr[3]=1;
            for(int i=4;i<=n;i++){
                int a = INT_MAX;
                int b = INT_MAX;
                if(i%2==0){
                    a = arr[i/2];
                }
                if(i%3==0){
                    b = arr[i/3];
                }
                int c = arr[i-1];
                arr[i] = 1+min(a,min(b,c));
            }
            cout<<arr[n]<<endl;
    }
