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
  int num;
  cin>>num;
  long lezat[num],k=0;
  for(int i=0;i<num;i++)cin>>lezat[i];
  // sort(lezat,lezat+num);
  int ebteda=0,enteha=num-1;
  long long sum[2]={0};
  for(int i=0;i<num;i++){
    if(lezat[ebteda]>lezat[enteha]){
          sum[k++%2]+=lezat[ebteda];
          ebteda++;
    }
    else
    {
          sum[k++%2]+=lezat[enteha];
          enteha--;
    }
  }
  // while(ebteda!=enteha){
  //   if(lezat[ebteda]>lezat[enteha]){
  //     sum+=lezat[ebteda];
  //     ebteda++;
  //   }
  //   else{
  //     sum+=lezat[enteha];
  //     enteha--;
  //   }
  //   if (ebteda==enteha) break;
  //   if(lezat[ebteda]>lezat[enteha]){
  //     ebteda++;
  //   }
  //   else{
  //     enteha--;
  //   }
  // }
  cout<<sum[0]<<" "<<sum[1];
}
