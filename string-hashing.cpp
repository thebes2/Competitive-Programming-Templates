#include <bits/stdc++.h>
using namespace std;

// string hashing converts strings into a number which can then be compared in O(1)
const int MN=1e5+5,seed=131;
int pw[MN]={1}, hsh[MN], i, h;
string s, t;

int getHash(int x,int y){
	if(x==0) return hsh[y];
	return hsh[y]-hsh[x-1]*pw[y-x+1];
}

int main(){
	// checks if t is a substring of s in O(|S|)
	cin >> s >> t;
	for(i=0;i<s.size();i++){
		if(!i) hsh[i]=s[i]-'a';
		else hsh[i]=hsh[i-1]*seed+s[i]-'a';
		pw[i+1] = pw[i]*seed;
	}
	for(i=0;i<t.size();i++)
		h = h*seed + t[i]-'a';
	for(i=0;i<=s.size()-t.size();i++){
		if(getHash(i,i+t.size()-1)==h){
			printf("String t was found at position %d\n",i);
			return 0;
		}
	}
	printf("String t is not a substring of s\n");
	return 0;
}