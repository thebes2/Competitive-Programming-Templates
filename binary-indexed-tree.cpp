#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
typedef long long ll;
ll bit[MN];

void update(ll p, ll dif){
	// increments all indices of the array greater than p in O(logN) time
	for(;p<=N;p+=p&-p)
		bit[p] += dif;
}

ll query(ll p){
	// returns the sum of all indices of the array less than p in O(logN) time
	ll sum = 0;
	for(;p>0;p-=p&-p)
		sum += bit[p];
	return sum;
}