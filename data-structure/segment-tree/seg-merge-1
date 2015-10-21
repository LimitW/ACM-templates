#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;

int a[maxn];

struct node{
	int l, r;
	int v, lsv, rsv;
}st[maxn<<2];

void pushup(int o){
	int lsl = st[o<<1].r - st[o<<1].l + 1;
	int rsl = st[o<<1|1].r - st[o<<1|1].l + 1;
	st[o].lsv = st[o<<1].lsv;
	st[o].rsv = st[o<<1|1].rsv;
	st[o].v = max(st[o<<1].v, st[o<<1|1].v);
	if(a[st[o<<1].r] < a[st[o<<1|1].l]){
		if(st[o<<1].lsv == lsl)
			st[o].lsv += st[o<<1|1].lsv;
		if(st[o<<1|1].rsv == rsl)
			st[o].rsv += st[o<<1].rsv;
		st[o].v = max(st[o].v, st[o<<1].rsv + st[o<<1|1].lsv);
	}
}

void build(int o, int l, int r){
	st[o].l = l, st[o].r = r;
	if(l == r){
		st[o].v = st[o].lsv = st[o].rsv = 1;
		return;
	}
	int mid = l + r >> 1;
	build(o<<1, l, mid);
	build(o<<1|1, mid+1, r);
	pushup(o);
}

void update(int o, int p, int v){
	if(st[o].l == st[o].r && st[o].l == p){
		a[p] = v;
		return;
	}
	int mid = st[o].l + st[o].r >> 1;
	if(p <= mid) update(o<<1, p, v);
	else update(o<<1|1, p, v);
	pushup(o);
}

int query(int o, int l, int r){
	if(l == st[o].l && r == st[o].r)
		return st[o].v;
	int mid = st[o].l + st[o].r >> 1;
	int ans;
	if(l > mid) ans = query(o<<1|1, l, r);
	else if(r <= mid) ans = query(o<<1, l, r);
	else{
		int x, y;
		x = query(o<<1, l, mid);
		y = query(o<<1|1, mid+1, r);
		ans = max(x, y);
		if(a[mid] < a[mid+1]){
			x = min(st[o<<1].rsv, mid - l + 1);
			y = min(st[o<<1|1].lsv, r - mid);
			ans = max(ans, x + y);
		}
	}
	return ans;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n, q; scanf("%d%d", &n, &q);
		for(int i = 1; i <= n; ++i)
			scanf("%d", a + i);
		build(1, 1, n);
		for(int i = 0; i < q; ++i){
			char op[5]; int l, r;
			scanf("%s%d%d", op, &l, &r);
			if(op[0] == 'U') update(1, l+1, r);
			else printf("%d\n", query(1, l+1, r+1));
		}
	}
	return 0;
}

