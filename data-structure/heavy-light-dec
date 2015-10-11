#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

const int maxn = 3e4 + 3;
const int maxm = 1e5 + 3;

struct edge{
	int v, nxt;
}E[2*maxn];

int head[maxn], e;

void addedge(int u, int v){
	E[e].v = v, E[e].nxt = head[u], head[u] = e++;
}

int fa[maxn], son[maxn], sz[maxn], dep[maxn];

void dfs(int u){
	sz[u] = 1; son[u] = 0;
	for(int i = head[u]; ~i; i = E[i].nxt){
		if(E[i].v == fa[u]) continue;
		fa[E[i].v] = u;
		dep[E[i].v] = dep[u] + 1;
		dfs(E[i].v);
		if(sz[E[i].v] > sz[son[u]]) son[u] = E[i].v;
		sz[u] += sz[E[i].v];
	}
}

int w[maxn], top[maxn], z;

void dfs2(int u, int tp){
	w[u] = ++z; top[u] = tp;
	if(son[u]) dfs2(son[u], top[u]);
	for(int i = head[u]; ~i; i = E[i].nxt){
		if(E[i].v == son[u] || E[i].v == fa[u]) continue;
		dfs2(E[i].v, E[i].v);
	}
}

struct node{
	int v, lazy;
}st[maxn<<2];

void pushup(int o){
	st[o].v = st[o<<1].v + st[o<<1|1].v;
}

void pushdown(int o){
	if(st[o].lazy){
		st[o<<1].v = st[o<<1|1].v = 0;
		st[o<<1].lazy = st[o<<1|1].lazy = 1;
		st[o].lazy = 0;
	}
}

void build(int o, int l, int r){
	st[o].lazy = 0;
	if(l == r) { st[o].v = 1; return; }
	int mid = l + r >> 1;
	build(o<<1, l, mid);
	build(o<<1|1, mid+1, r);
	pushup(o);
}

void update(int o, int l, int r, int ql, int qr){
	if(l == ql && r == qr){
		st[o].v = 0;
		st[o].lazy = 1;
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if(qr <= mid) update(o<<1, l, mid, ql, qr);
	else if(ql > mid) update(o<<1|1, mid+1, r, ql, qr);
	else{
		update(o<<1, l, mid, ql, mid);
		update(o<<1|1, mid+1, r, mid+1, qr);
	}
	pushup(o);
}

int query(int o, int l, int r, int ql, int qr){
	if(l == ql && r == qr) return st[o].v;
	pushdown(o);
	int mid = l + r >> 1;
	int ans = 0;
	if(qr <= mid) ans = query(o<<1, l, mid, ql, qr);
	else if(ql > mid) ans = query(o<<1|1, mid+1, r, ql, qr);
	else ans = query(o<<1, l, mid, ql, mid) + query(o<<1|1, mid+1, r, mid+1, qr);
	return ans;
}

int n, m, q;

void updatex(int l, int r){
	int f1 = top[l], f2 = top[r], u = l, v = r;
	while(f1 != f2){
		if(dep[f1] < dep[f2]){
			swap(f1, f2);
			swap(u, v);
		}
		update(1, 1, z, w[f1], w[u]);
		u = fa[f1];
		f1 = top[u];
	}
	if(u != v){
		if(dep[u] > dep[v]) swap(u, v);
		update(1, 1, z, w[son[u]], w[v]);
	}
}

int queryx(int l, int r){
	int f1 = top[l], f2 = top[r], u = l, v = r;
	int ans = 0;
	while(f1 != f2){
		if(dep[f1] < dep[f2]){
			swap(f1, f2);
			swap(u, v);
		}
		ans += query(1, 1, z, w[f1], w[u]);
		u = fa[f1];
		f1 = top[u];
	}
	if(u != v){
		if(dep[u] > dep[v]) swap(u, v);
		ans += query(1, 1, z, w[son[u]], w[v]);
	}
	return ans;
}

struct query{
	int op, u, v;
}Q[maxm];

int p[maxn];

int getfa(int x){
	return p[x] == x ? x : p[x] = getfa(p[x]);
}

multiset<pair<int, int> > Edge;

int main(){
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		printf("Case #%d:\n", kase);
		scanf("%d%d%d", &n, &m, &q);
		Edge.clear();
		for(int i = 0; i < m; ++i){
			int u, v; scanf("%d%d", &u, &v);
			if(u > v) swap(u, v);
			Edge.insert(make_pair(u, v));
		}
		multiset<pair<int, int> >::iterator it;
		for(int i = 0; i < q; ++i){
			scanf("%d%d%d", &Q[i].op, &Q[i].u, &Q[i].v);
			if(Q[i].u > Q[i].v) swap(Q[i].u, Q[i].v);
			if(Q[i].op == 1){
				pair<int, int> cur = make_pair(Q[i].u, Q[i].v);
				it = Edge.lower_bound(cur);
				Edge.erase(it);
			}
		}
		e = 0;
		memset(head, -1, sizeof(head));
		for(int i = 1; i <= n; ++i) p[i] = i;
		it = Edge.begin();
		for(; it != Edge.end(); ){
			int u = it->first, v = it->second;
			int x = getfa(u), y = getfa(v);
			if(x != y){
				p[y] = x;
				addedge(u, v);
				addedge(v, u);
				it = Edge.erase(it);
			}
			else ++it;
		}
		z = 0;
		memset(son, 0, sizeof(son));
		memset(sz, 0, sizeof(sz));
		dfs(1); dfs2(1, 1);
		build(1, 1, z);
		vector<int> ans;
		ans.clear();
		for(it = Edge.begin(); it != Edge.end(); ++it)
			updatex(it->first, it->second);
		for(int i = q - 1; i >= 0; --i){
			int u = Q[i].u, v = Q[i].v;
			if(Q[i].op == 1) updatex(u, v);
			else ans.push_back(queryx(u, v));
		}
		while(ans.size() > 0){
			printf("%d\n", ans.back());
			ans.pop_back();
		}
	}
    return 0;
}

