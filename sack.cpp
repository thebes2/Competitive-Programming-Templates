#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
typedef long long ll;
int id[MN], sz[MN], N, i, x, y, rt[MN], nxt;
map<int,int> mp[MN], cnt; ll ans;
vector<pair<int,int>> adj[MN];
void go(int n,int p){
	sz[n] = 1;
	for(auto v : adj[n]){
		if(v.first == p) continue;
		rt[v.first]=rt[n]+v.second;
		go(v.first,n);sz[n]+=sz[v.first];
	}
}
void solve(int n,int p){
	for(auto v : adj[n])
		if(v.first!=p) solve(v.first,n);
	pair<int,int> b(-1,-1);
	for(auto v : adj[n])
		if(v.first!=p&&sz[v.first]>b.first)
			b = {sz[v.first], v.first};
	if(b.second==-1) id[n]=++nxt;
	else id[n]=id[b.second];
	mp[id[n]][rt[n]]++;
	if(mp[id[n]].count(rt[n]-1)) ans+=mp[id[n]][rt[n]-1];
	if(mp[id[n]].count(rt[n]+1)) ans+=mp[id[n]][rt[n]+1];
	for(auto v : adj[n]){
		if(v.first==p||v.first==b.second) continue;
		for(auto e : mp[id[v.first]]){
			if(mp[id[n]].count(2*rt[n]-e.first-1))
				ans+=1LL*mp[id[n]][2*rt[n]-e.first-1]*e.second;
			if(mp[id[n]].count(2*rt[n]-e.first+1))
				ans+=1LL*mp[id[n]][2*rt[n]-e.first+1]*e.second;
		}
		for(auto e : mp[id[v.first]])
			mp[id[n]][e.first] += e.second;
	}
}

int main(){
	for(scanf("%d",&N),i=1;i<N;i++){
		char c;scanf("%d%d %c",&x,&y,&c);
		adj[x].push_back({y,c=='r'?1:-1});
		adj[y].push_back({x,c=='r'?1:-1});
	}
	go(1, 0); solve(1, 0);
	printf("%lld\n",ans-N+1);
	return 0;
}
