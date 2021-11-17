#include<iostream>
#include<vector>
using namespace std;
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int minimum(vector<vector<int> > &A,int m,int n) {
    int arr[m][n];
    arr[m-1][n-1]=max(1,1-A[m-1][n-1]);

    for(int i=m-2;i>=0;i--){
        arr[i][n-1]=max(arr[i+1][n-1]-A[i][n-1],1);
    }
    for(int i=n-2;i>=0;i--){
        arr[m-1][i]=max(arr[m-1][i+1]-A[m-1][i],1);
    }

    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            int d=max(arr[i+1][j]-A[i][j],1);
            int r=max(arr[i][j+1]-A[i][j],1);
            arr[i][j]=min(r,d);
        }
    }

    return arr[0][0];
}
int main(){
    int m,n;
    cin>>m;
    cin>>n;
    vector<vector<int> > d( n , vector<int> (m, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>d[i][j];
        }
    }
    cout<<minimum(d,m,n);
}
