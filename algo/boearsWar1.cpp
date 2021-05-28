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
  // fst
  int num,m,n,w;

  cin>>num;
  for(int i=0;i<num;i++){
    cin>>r>>c>>m>>n;
    cin>>w;
    pair<int,int>warr[w];
    int sign[r][c];
    memset(sign,0, r*c);
    for(int j=0;j<w;j++){
      cin>>warr[j].first>>warr[j].second;
    }
    int sig=-1;//fard
    // for(int j=0;j<r;j++){
      // for(int k=0;k<c;k++){
    int j=0,k=0;
    while(true){
    if(j+m>=0&&k+n>=0&&j+m<r&&k+n<c&&sign[j+m][k+n]==0){
          sign[j+m][k+n]=sig;
          j=j+m;
          k=k+n;
          sig*=-1;
        // }
      // }
    }
    if(j-m>=0&&k+n>=0&&j-m<r&&k+n<c&&sign[j-m][k+n]==0){
          sign[j-m][k+n]=sig;
          j=j-m;
          k=k+n;
          sig*=-1;
        // }
      // }
    }
    if(j+m>=0&&k-n>=0&&j+m<r&&k-n<c&&sign[j+m][k-n]==0){
          sign[j+m][k-n]=sig;
          j=j+m;
          k=k-n;
          sig*=-1;
        // }
      // }
    }
    if(j-m>=0&&k-n>=0&&j-m<r&&k-n<c&&sign[j-m][k-n]==0){
          sign[j-m][k-n]=sig;
          j=j-m;
          k=k-n;
          sig*=-1;
        // }
      // }
    }
    if (j==0&&k==0) break;
}

int zoj=0,fard=0;
for(int o=0;o<r;o++){
  for(int p=0;p<c;p++){
    if (sign[o][p]==-1) fard++;
    else if (sign[o][p]==1) zoj++;
  }
}
cout<<"Case "<<i+1<<": "<<zoj<<" "<<fard<<endl;
  }
}
