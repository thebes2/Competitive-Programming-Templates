#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int N, i, sa[MN], hsh[MN], pw[MN]={1};
string s;

int getHsh(int x,int y){return hsh[y]-hsh[x-1]*pw[y-x+1];}

bool sufCmp(int i,int j){
	int lo=0, hi=s.size()-max(i,j);
	while(lo < hi){
		int m = lo+hi>>1;
		if(getHsh(i,i+m)==getHsh(j,j+m)) lo=m+1;
		else hi=m;
	}
	return s[i+lo]<s[j+lo];
}

int main(){
	cin >> s; N = s.size();
	s.insert(s.begin(),'$');
	s.push_back('$');
	for(i=1;i<=N;i++){
		hsh[i]=hsh[i-1]*131+s[i]-'a';
		pw[i]=pw[i-1]*131;
		sa[i]=i;
	}
	stable_sort(sa+1,sa+N+1,sufCmp);
	return 0;
}