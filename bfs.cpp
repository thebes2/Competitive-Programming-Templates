#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int N, M, i, x, y, vis[MN];
vector<int> adj[MN];
queue<int> q;

int main(){
  // finds all nodes that can be reached starting from node 1 and travelling along the given edges
  for(scanf("%d%d",&N,&M),i=1;i<=M;i++){
    scanf("%d%d",&x,&y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  q.push(1); vis[1]=1;
  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(auto v : adj[cur])
      if(!vis[v]) vis[v]=1, q.push(v);
  }
  for(i=1;i<=N;i++)
    if(vis[i]) printf("%d\n",i);
   return 0;
}
