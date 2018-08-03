#include <bits/stdc++.h>
using namespace std;
// treap template:
struct node{
	int key, p, sz;
	node *l, *r;
	node(int K):key(K),p(rand()),sz(1),l(NULL),r(NULL){};
}*root;

int sz(node *n){return n?n->sz:0;}
void upd_sz(node *&n){if(n)n->sz=sz(n->l)+sz(n->r)+1;}

void split(node *n,node *&l,node *&r,int key){
	if(!n) l=r=NULL;
	else if(key<n->key) split(n->l,l,n->l,key),r=n;
	else split(n->r,n->r,r,key),l=n;
	upd_sz(n);
}

void merge(node *&n,node *l,node *r){
	if(!l||!r) n=l?l:r;
	else if(l->p>r->p) merge(l->r,l->r,r),n=l;
	else merge(r->l,l,r->l),n=r;
	upd_sz(n);
}

// inserts a node into the treap
void insert(node *&n,node *it){
	if(!n) n=it;
	else if(n->p<it->p) split(n,it->l,it->r,it->key),n=it;
	else insert(n->key<=it->key?n->r:n->l,it);
	upd_sz(n);
}

// removes a node from the treap if it exists
void remove(node *&n,int key){
	if(!n) return;
	else if(n->key==key) merge(n,n->l,n->r);
	else remove(n->key<=key?n->r:n->l,key);
	upd_sz(n);
}