#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5, MM = 5e5+5;
// normal segtree
struct seg{int s;}st[3*MN];
// lazy segtree
struct lseg{int s, upd;}st[3*MN];
// persistent segtree
struct pseg{int l, r, s;}st[30*MM];

template<typename T>
inline void calc(T* i,T l,T r){
	// get answer for current node

}

template<typename T>
inline void init(T* i,int idx){
	// init segtree leaf node

}

// normal segtree functions:
void build(int i, int s, int e){
	if(s != e){
		build(2*i,s,(s+e)/2);
		build(2*i+1,(s+e)/2+1,e);
		calc<seg>(&st[i],st[2*i],st[2*i+1]);
	}
	else init<seg>(&st[i],s);
}

void update(int i,int s,int e,int ind){
	if(s != e){
		if((s+e)/2<ind) update(2*i+1,(s+e)/2+1,e,ind);
		else update(2*i,s,(s+e)/2,ind);
		calc<seg>(&st[i],st[2*i],st[2*i+1]);
	}
	else init<seg>(&st[i],s);
}

seg query(int i,int s,int e,int qs,int qe){
	if(s>=qs&&e<=qe) return st[i];
	else if((s+e)/2<qs) return query(2*i+1,(s+e)/2+1,e,qs,qe);
	else if((s+e)/2>=qe) return query(2*i,s,(s+e)/2,qs,qe);
	else{
		seg l=query(2*i,s,(s+e)/2,qs,qe), r=query(2*i+1,(s+e)/2+1,e,qs,qe);
		seg ret; calc<seg>(&ret,l,r); return ret;
	}
}

// lazy segment tree functions
inline void lazy_prop(lseg *p,int val){
	// how the lazy parameter is propagated

}

inline void lazy_upd(lseg* n,int s,int e){
	// how to update values using lazy value

}

void push_down(int i, int s, int e){
	lazy_upd(&st[i],s,e);
	if(s != e) {
		lazy_prop(&st[2*i],st[i].upd);
		lazy_prop(&st[2*i+1],st[i].upd);
	}
	st[i].upd = 0;
}

void build(int i,int s,int e){
	if(s != e){
		build(2*i,s,(s+e)/2);
		build(2*i+1,(s+e)/2+1,e);
		calc<lseg>(&st[i],st[2*i],st[2*i+1]);
	}
	else init<lseg>(&st[i],s);
}

lseg query(int i,int s,int e,int qs,int qe){
	if(st[i].upd!=0) push_down(i,s,e);
	if(s>=qs&&e<=qe) return st[i];
	else if((s+e)/2<qs) return query(2*i+1,(s+e)/2+1,e,qs,qe);
	else if((s+e)/2>=qe) return query(2*i,s,(s+e)/2,qs,qe);
	else{
		lseg l=query(2*i,s,(s+e)/2,qs,qe),r=query(2*i+1,(s+e)/2+1,e,qs,qe);
		lseg ret; calc<lseg>(&ret,l,r); return ret;
	}
}

void update(int i,int s,int e,int ss,int se,int val){
	if(st[i].upd!=0) push_down(i,s,e);
	if(s>=ss&&e<=se) st[i].upd=val, push_down(i,s,e);
	else{
		if((s+e)/2<ss){
			update(2*i+1,(s+e)/2+1,e,ss,se,val);
			push_down(2*i,s,(s+e)/2);
		}
		else if((s+e)/2>=se){
			update(2*i,s,(s+e)/2,ss,se,val);
			push_down(2*i+1,(s+e)/2+1,e);
		}
		else{
			update(2*i,s,(s+e)/2,ss,se,val);
			update(2*i+1,(s+e)/2+1,e,ss,se,val);
		}
		calc<lseg>(&st[i],st[2*i],st[2*i+1]);
	}
}

// persistent segment tree functions
int nxt, root[MM];

int build(int s,int e){
	int cur = nxt++;
	if(s==e) init<pseg>(&st[cur],s);
	else{
		st[cur].l = build(s,(s+e)/2);
		st[cur].r = build((s+e)/2+1,e);
		calc<pseg>(&st[cur],st[st[cur].l],st[st[cur].r]);
	}
	return cur;
}

pseg query(int n,int s,int e,int ss,int se){
	if(s>=ss&&e<=se) return st[i];
	else if((s+e)/2<ss) return query(2*i+1,(s+e)/2+1,e,ss,se);
	else if((s+e)/2>=se) return query(2*i,s,(s+e)/2,ss,se);
	else{
		pseg l=query(2*i,s,(s+e)/2,ss,se),r=query(2*i+1,(s+e)/2+1,e,ss,se);
		pseg ret; calc<pseg>(&ret,l,r); return ret;
	}
}

int update(int n,int s,int e,int ind){
	int cur = nxt++;
	if(s==e) init<pseg>(&st[cur],s);
	else{
		if((s+e)/2<ind){
			st[cur].l = st[n].l;
			st[cur].r = update(st[n].r,(s+e)/2+1,e,ind);
		}
		else{
			st[cur].r = st[n].r;
			st[cur].l = update(st[n].l,s,(s+e)/2,ind);
		}
		calc<pseg>(&st[cur],st[st[cur].l],st[st[cur].r]);
	}
	return cur;
}
