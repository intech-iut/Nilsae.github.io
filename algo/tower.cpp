#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
#define forr(a,b,c) for(long long a=b;a<c;a++)
// #define fst cin.tie(0);ios_base::sync_with_stdio(false);cout<<fixed;cout<<setprecision(1);

ll mod = 1e9+7;
int min(int a, int b){
   return a<b ?a :b;
}
int max(int a, int b){
   return a>b ?a :b;
}
int main(){
  // fst
int num;
cin>>num;
while(num){
  int a[num][2];
  for(int i=0;i<num;i++) cin>>a[i][0]>>a[i][1];
  int bw1= a[num-1][1];
  int bw=bw1;
  int dp[num][bw1];
  memset(dp,0,sizeof(dp));
  for(int i=0;i<num;i++){
    dp[i][0]=0;
  }
  for(int i=0;i<num-1;i++){
    // for(int j=0;j< bw1;j++){
    if(bw<=0) break;
      if(bw-a[i+1][0]<=0){
        dp[i+1][bw]=dp[i][bw];
      }
      else{
        if(dp[i][bw]>dp[i][min(bw-a[i+1][0],a[i+1][1])]){
          dp[i+1][bw]=dp[i][bw];
        }
        else{
          dp[i+1][bw]=1+dp[i][min(bw-a[i][0],a[i][1])];
          bw=min(bw-a[i][0],a[i][1]);
        }

    }
    // }
  }

int max=-1;
for(int i=0;i<num;i++){
  for(int j=0;j<bw1;j++){
    cout<<dp[i][j]<<" ";
    if(dp[i][j]>max){
      max=dp[i][j];
    }
}
cout<<endl;
}
cout<<max+1;


  cin>>num;
}
}
