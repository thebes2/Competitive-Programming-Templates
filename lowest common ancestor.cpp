#include<bits/stdc++.h>
using namespace std;
int maxn = 21;
vector < int > adj[10000];
int level[1000];
int lca[1000][21];
void dfs(int node, int par) {
	lca[node][0] = par;
	if(par == -1)
	level[node] = 0;
	else
	level[node] = level[par]+1;
	for(int ch: adj[node]) {
		if(ch == par) continue;
		dfs(ch, node);
	}
}
void init(int x) {
	dfs(1, -1);
	for(int j = 1; j <= maxn; j++) {
		for(int i = 1; i <= x; i++) {
			if(lca[i][j-1] != -1) {
				int par = lca[i][j-1];
				lca[i][j] = lca[par][j-1];
			}
		}
	}
}
int logg(int pp) {
	int ans;
	for(int i = 0; i < 32; i++) {
		if(pp&(1<<i)) {
			ans = i;
		}
	}
	return ans;
}

int la(int a, int b) {
	if(level[a] > level[b])
	swap(a, b);
	int d = level[b]-level[a];

	while(d > 0) {
		int i = logg(d);
		b = lca[b][i];
		d -= (1<<i);
	}
	if(a == b) return a;
	for(int maxn; i >= 0; i--) {
		if((lca[a][i] != -1) && (lca[a][i] != lca[b][i])) {
			a = lca[a][i];
			b = lca[b][i];

		}
	}
	return lca[a][0];


}
int main() {
	int x,
	y;
	cin>>x>>y;
	for(int i = 1; i <= x; i++) {
		for(int j = 0; j <= maxn; j++) {
			lca[i][j] = -1;
		}
	}

	for(int i = 1; i <= x-1; i++) {
		int u,
		v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	init(x);
	while(y--) {
		int a,
		b;
		cin>>a>>b;
		cout<<la(a, b)<<endl;
	}
	return 0;
}
