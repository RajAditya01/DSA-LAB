#include<bits/stdc++.h>
using namespace std;
bool isSafe(int row,int col,int **arr,int n,int value){
       for(int i=0;i<n;i++){
        if(arr[row][i]==value){
            return false;
        }
        if(arr[i][col]==value){
            return false;
        }
        if(arr[3*(row/3)+i/3][3*(col/3)+i%3]==value){
            return false;
        }
       }
       return true;
}
bool solve(int**arr,int n){
      for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(arr[row][col]==0){
                for(int k=1;k<=9;k++){                   
                    if(isSafe(row,col,arr,n,k)){
                        arr[row][col]=k;
                        bool nextSol=solve(arr,n);
                        if(nextSol){
                            return true;
                        }
                        else{
                            arr[row][col]=0;
                        }
                    }
                }
                return false;

            }
        }
      }
     return true;
}

void sudokuSolver(int **arr,int n){
    solve(arr,n);
}

int main(){
int n;
cin>>n;
int *arr=new int[n];
for(int i=0;i<n;i++){
    arr[i]=new int[n]; 
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
    }
}
sudokuSolver(arr,n);
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
for(int i=0;i<n;i++){
    delete[] arr [i];
}
delete[]arr;
return  0;
}