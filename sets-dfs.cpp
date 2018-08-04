#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int N, M, i, x, y, cnt;
set<int> adj[MN], to;

void dfs(int n){
  vector<int> nxt; cnt++;
  for(auto it=to.begin();it!=to.end();){
    if(adj[n].count(*it)){it++; continue;}
    nxt.push_back(*it); 
    auto tmp = it; it++;
    to.erase(tmp);
  }
  for(auto v : nxt)
    dfs(v);
}

int main(){
  // given a complete graph with N nodes, there are M edges that are not part of the graph
  // prints the sizes of the connected components of this graph
  for(scanf("%d%d",&N,&M),i=1;i<=M;i++){
    scanf("%d%d",&x,&y);
    adj[x].insert(y);
    adj[y].insert(x);
  }
  for(i=1;i<=N;i++)
    to.insert(i);
  while(to.size()){
    auto it=to.begin(); cnt=0;
    int tmp = *it; to.erase(it);
    dfs(tmp);
    printf("%d\n",cnt);
  }
  return 0;
}
