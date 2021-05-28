#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
// #define mod 1e9+7
typedef long long ll;
#define forr(a,b,c) for(long long a=b;a<c;a++)

#define fst cin.tie(0);ios_base::sync_with_stdio(false);cout<<fixed;cout<<setprecision(1);
ll mod =1e9+7;
ll arr[ll(1e6)];
ll count( int n)
{
 ll table[n+1];
 memset(table, 0, sizeof(table));
 table[0] = 1;

 for(ll i=n-2; i>=0; i--){
 // for(ll j=arr[i]; j<=n; j++)
  if(arr[i]==0){
    int mulval;
    if(arr[i-1]!=0){
      if(arr[i+1]-arr[i-1]==2||arr[i+1]-arr[i-1]==-2) mulval=1;
      else if(arr[i+1]-arr[i-1]==1||arr[i+1]-arr[i-1]==-1) mulval=2;
      else if (arr[i+1]-arr[i-1]==0) mulval=3;
    }
    else{
      int j=i-1;
      int possi=1;
      while (!arr[j]) j--,possi++;
    }
  }
 table[j] += table[j-arr[i]]%mod;

}
 return table[n]%mod;

}
    int main(){
      fst
      int n,x;
      cin>>n>>x;
      // ll arr[n];
      for(ll i=0;i<n;i++) cin>>arr[i];
      // n, x = map(int, input().split())
      // arr = [int(x) for x in input().split()]
      cout<<(count(n))%mod;
    }
