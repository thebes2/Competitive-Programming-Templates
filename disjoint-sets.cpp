#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int ds[MN];

void init(int N){
	// initializes the disjoint sets
	for(int i=1;i<=N;i++)
		ds[i] = i;
}

int fnd(int n){
	// returns the parent of n
	if(ds[n]==n) return n;
	else return ds[n]=fnd(ds[n]);
}

bool same(int x,int y){
	// checks if x and y are in the same disjoint set
	return fnd(x)==fnd(y);
}

void unite(int x,int y){
	// merges the set containing x and the set containing y
	int A = fnd(x), B = fnd(y);
	ds[A] = B;
}