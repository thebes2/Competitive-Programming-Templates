#include <bits/stdc++.h>
using namespace std;

const int MN = 1e7+5;
bitset<MN> prime;
int i, j;

int main(){
	prime.set();
	prime[0] = 0;
	prime[1] = 0;
	for(i=2;i<MN;i++){
		if(!prime[i]) continue;
		for(j=i*i;j<MN;j+=i)
			prime[j] = 0;
	}
	return 0;
}