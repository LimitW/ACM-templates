#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int maxn = 2e4 + 3;
const int maxm = 1e5 + 3;
const double eps = 1e-9;

struct Edge{
	int u, v, nxt;
}E[maxm], E2[maxm];

int n, m, e;
int head[maxn], w[maxn];

void addedge(int u, int v, Edge* E){
	E[e].u = u, E[e].v = v;
	E[e].nxt = head[u], head[u] = e++;
}

int ck, scc_cnt;
int pre[maxn], lowlink[maxn];
stack<int> S;
vector<int> scc[maxn];
int sccno[maxn];

void dfs(int u){
	pre[u] = lowlink[u] = ++ck;
	S.push(u);
	for(int i = head[u]; i != -1; i = E[i].nxt){
		int v = E[i].v;
		if(!pre[v]){
			dfs(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		}
		else if(!sccno[v]){
			lowlink[u] = min(lowlink[u], pre[v]);
		}
	}
	if(lowlink[u] == pre[u]){
		scc[++scc_cnt].clear();
		while(true){
			int x = S.top(); S.pop();
			scc[scc_cnt].push_back(x);
			sccno[x] = scc_cnt;
			if(u == x) break;
		}
	}
}

int nw[maxn], vis[maxn];

void canarrive(int u){
	vis[u] = 1;
	for(int i = head[u]; i != -1; i = E2[i].nxt){
		int v = E2[i].v;
		if(vis[v]) continue;
		canarrive(v);
	}
}

int d[maxn], ans[maxn], mx[maxn];
queue<int> Q;

int topo(){
	memset(mx, 0, sizeof(mx));
	memset(ans, 0, sizeof(ans));
	memset(d, 0, sizeof(d));
	for(int i = 0; i < e; ++i) ++d[E2[i].v];
	for(int i = 1; i <= scc_cnt; ++i){
		ans[i] += nw[i];
		if(!d[i]) Q.push(i);
	}
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		for(int i = head[x]; i != -1; i = E2[i].nxt){
			int v = E2[i].v;
			d[v]--, mx[v] = max(ans[x], mx[v]);
			if(d[v] == 0){
				ans[v] += mx[v];
				Q.push(v);
			}
		}
	}
	int res = 0;
	for(int i = 1; i <= scc_cnt; ++i)
		res = max(res, ans[i]);
	return res;
}

int main(){
	while(~scanf("%d%d", &n, &m)){
		memset(head, -1, sizeof(head));
		memset(pre, 0, sizeof(pre));
		memset(lowlink, 0, sizeof(lowlink));
		e = ck = scc_cnt = 0;
		for(int i = 1; i <= n; ++i)
			scanf("%d", &w[i]);
		for(int i = 0; i < m; ++i){
			int u, v; scanf("%d%d", &u, &v);
			addedge(u, v, E);
		}
		for(int i = 1; i <= n; ++i)
			if(!pre[i]) dfs(i);
		memset(head, -1, sizeof(head));
		e = 0;
		for(int i = 0; i < m; ++i){
			int u = sccno[E[i].u], v = sccno[E[i].v];
			if(u != v) addedge(u, v, E2);
		}
		for(int i = 1; i <= scc_cnt; ++i){
			int v = 0;
			for(int j = 0; j < scc[i].size(); ++j)
				v += w[scc[i][j]];
			nw[i] = v;
		}
		memset(vis, 0, sizeof(vis));
		canarrive(sccno[1]);
		for(int i = 1; i <= scc_cnt; ++i)
			if(!vis[i]) nw[i] = 0;
		printf("%d\n",topo());
	}
    return 0;
}

