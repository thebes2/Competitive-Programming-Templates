#include <bits/stdc++.h>
using namespace std;

// suffix automaton can be traversed like a normal suffix trie 
// but can be constructed in O(|S|)
struct suf_a{int len,lnk; map<char,int> e;}sa[2*MN];
int sz, last, p;

void init(){
	// initialize suffix automaton
	while(sz){
		sa[sz].len=sa[sz].lnk=0;
		sa[sz].e.clear(); sz--;
	}
	sa[0].lnk = -1; sz=1;
}

void add(char c){
	// add character to end of automaton
	int n = sz++;
	sa[n].len = sa[last].len + 1;
	for(p=last;p!=-1&&!sa[p].e.count(c);p=sa[p].lnk)
		sa[p].e[c] = n;
	if(p == -1) sa[n].lnk = 0;
	else{
		int q = sa[p].e[c];
		if(sa[p].len+1 == sa[q].len)
			sa[n].lnk = q;
		else{
			int tmp = sz++;
			sa[tmp].len = sa[p].len+1;
			sa[tmp].e = sa[q].e;
			sa[tmp].lnk = sa[q].lnk;
			for(;p!=-1&&sa[p].e[c]==q; p=sa[p].lnk)
				sa[p].e[c] = tmp;
			sa[q].lnk = sa[n].lnk = tmp;
		}
	}
	last = n;
}
