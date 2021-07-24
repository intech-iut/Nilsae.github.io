#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
#define forr(a,b,c) for(long long a=b;a<c;a++)
// #define fst cin.tie(0);ios_base::sync_with_stdio(false);cout<<fixed;cout<<setprecision(1);
int r,c;

ll mod = 1e9+7;
int main(){
  // int n,m;
  // cin>>n>>m;
  // int mat[n][m];
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<m ;j++){
  //     cin>>mat[i][j];
  //   }
  // }
  // for(int i=0;i<n;i++){
  //   if (mat[i][0]==0){
  //   for(int j=0;j<m ;j++){
  //     mat[i][j]=!mat[i][j];
  //   }
  // }
  // }
  // // for(int i=0;i<n;i++){
  // //   for(int j=0;j<m ;j++){
  // //     cout<<mat[i][j]<<" ";
  // //   }
  // //   cout<<endl;
  // // }
  // long ans=0;
  // long felan=1;
  // for(int i=0;i<n;i++){
  //
  //   for(int j=m-1;j>=0;j--){
  //     ans+=mat[i][j]*felan;
  //     felan*=2;
  //   }
  //   felan=1;
  // }
  // cout<<ans;
  for i in range(len(grid)):
       if grid[i][0]==0:
           for j in range(len(grid[0])):
               if grid[i][j]==1:
                   grid[i][j]=0
               else:
                   grid[i][j]=1

   # Counting number of 0 for each Column
   m=len(grid)
   n=len(grid[0])
   col=[0]*n
   for i in range(m):
       for j in range(n):
           if grid[i][j]==0:
               col[j]+=1

   # if number of zeroes are greater then one in column then toggle that column
   for j in range(n):
       if col[j]>(m-col[j]):
           for i in range(m):
               if grid[i][j]==1:
                   grid[i][j]=0
               else:
                   grid[i][j]=1

   # Calculating the sum
   num=0
   for row in grid:
       p=0
       for j in range(n-1,-1,-1):
           num+=row[j]*(2**p)
           p+=1
cout<<num;
}
