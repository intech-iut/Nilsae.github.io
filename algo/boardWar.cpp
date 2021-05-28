#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
#define forr(a,b,c) for(long long a=b;a<c;a++)
// #define fst cin.tie(0);ios_base::sync_with_stdio(false);cout<<fixed;cout<<setprecision(1);
int r,c;

ll mod = 1e9+7;
class Graph
{
    int V;
    list<pair<int,int>> *adj;
public:
    Graph(int V);
    void addEdge(pair<int,int> v, pair<int,int> w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair<int,int>>[V];
}

void Graph::addEdge(pair<int,int> v, pair<int,int> w)
{
  // felan= v.first*

    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty())
    {

        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int min(int a, int b){
   return a<b ?a :b;
}
int max(int a, int b){
   return a>b ?a :b;
}
int main(){
  // fst
  int num,m,n,w,warr[1000];
  cin>>num;
  for(int i=0;i<num;i++){
    cin>>r>>c>>m>>n;
    cin>>w;

    // for(int j=0;j<w;j++){
    //   cin>>warr[j];
    // }
    Graph g((r*c));
     // g.addEdge(0, m);
    for(int j=0;j<r*c;j++){
      g.addEdge(j,j+m+n)
    }


  }
}
