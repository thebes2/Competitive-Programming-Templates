#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int dist[MN], N, M, i, x, y, w;
vector<pair<int,int>> adj[MN];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

int main(){
  // computes length of the shortest path from node 1 to all other nodes
	for(scanf("%d%d",&N,&M),i=1;i<=M;i++){
		scanf("%d%d%d",&x,&y,&w);
		adj[x].push_back({w,y});
		adj[y].push_back({w,x});
	}
	q.push({0,1});
	memset(dist,-1,sizeof(dist));
	while(q.size()){
		auto cur=q.top(); q.pop();
		if(dist[cur.second]!=-1) continue;
		dist[cur.second]=cur.first;
		for(auto v : adj[cur.second])
			q.push({cur.first+v.first,v.second});
	}
	for(i=1;i<=N;i++)
		printf("%d\n",dist[i]);
	return 0;
}
