#include <bits/stdc++.h>

using namespace std;

const int maxn = 50010;

struct node{
	int l, r;
	int v, lsv, rsv;
	int lazy;
}st[maxn<<2];

void pushup(int o){
	if(st[o<<1].lsv == st[o<<1].r - st[o<<1].l + 1)
		st[o].lsv = st[o<<1].lsv + st[o<<1|1].lsv;
	else st[o].lsv = st[o<<1].lsv;
	if(st[o<<1|1].rsv == st[o<<1|1].r - st[o<<1|1].l + 1)
		st[o].rsv = st[o<<1].rsv + st[o<<1|1].rsv;
	else st[o].rsv = st[o<<1|1].rsv;
	st[o].v = max(max(st[o<<1].v, st[o<<1|1].v), st[o<<1].rsv+st[o<<1|1].lsv);
}

void pushdown(int o){
	if(st[o].lazy != -1){
		int lsl = st[o<<1].r - st[o<<1].l + 1;
		int rsl = st[o<<1|1].r - st[o<<1|1].l + 1;
		st[o<<1].lazy = st[o<<1|1].lazy = st[o].lazy;
		st[o<<1].v = st[o<<1].lsv = st[o<<1].rsv = st[o].lazy * lsl;
		st[o<<1|1].v = st[o<<1|1].lsv = st[o<<1|1].rsv = st[o].lazy * rsl;
		st[o].lazy = -1;
	}
}

void build(int o, int l, int r){
	st[o].l = l, st[o].r = r, st[o].lazy = -1;
	st[o].v = st[o].lsv = st[o].rsv = r - l + 1;
	if(l == r) return;
	int mid = l + r >> 1;
	build(o<<1, l, mid);
	build(o<<1|1, mid+1, r);
}

void update(int o, int l, int r, int v){
	if(st[o].l == l && st[o].r == r){
		int rtl = st[o].r - st[o].l + 1;
		st[o].v = st[o].lsv = st[o].rsv = v * rtl;
		st[o].lazy = v;
		return;
	}
	pushdown(o);
	int mid = st[o].l + st[o].r >> 1;
	if(r <= mid) update(o<<1, l, r, v);
	else if(l > mid) update(o<<1|1, l, r, v);
	else{
		update(o<<1, l, mid, v);
		update(o<<1|1, mid+1, r, v);
	}
	pushup(o);
}

int query(int o, int sz){
	if(st[o].l == st[o].r) return st[o].l;
	if(st[o].lsv >= sz) return st[o].l;
	pushdown(o);
	int mid = st[o].l + st[o].r >> 1;
	int ans = -1;
	if(st[o<<1].v >= sz) ans = query(o<<1, sz);
	else if(st[o<<1].rsv + st[o<<1|1].lsv >= sz){
		return mid - st[o<<1].rsv + 1;
	}
	else ans = query(o<<1|1, sz);
	return ans;
}

int main(){
	int n, q;
	while(~scanf("%d%d", &n, &q)){
		build(1, 1, n);
		for(int i = 0; i < q; ++i){
			int op; scanf("%d", &op);
			if(op == 1){
				int v; scanf("%d", &v);
				if(st[1].v >= v){
					int p = query(1, v);
					printf("%d\n", p);
					update(1, p, p + v - 1, 0);
				}
				else puts("0");
			}
			else{
				int l, r; scanf("%d%d", &l, &r);
				update(1, l, l + r - 1, 1);
			}
		}
	}
	return 0;
}

