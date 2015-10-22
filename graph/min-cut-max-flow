#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 3;
const int INF = 0x3f3f3f3f;

struct Edge{
	int from, to, cap, flow, cost;
};

struct MCMF{

	vector<Edge> edges;
	vector<int> G[maxn];
	int inq[maxn];
	int d[maxn];
	int p[maxn];
	int a[maxn];
	int s, t, n;
	void init(int n){
		this->n = n;
		edges.clear();
		for(int i = 0; i < n; ++i) G[i].clear();
	}

	void AddEdge(int from, int to, int cap, int cost){
		edges.push_back((Edge){from, to, cap, 0, cost});
		edges.push_back((Edge){to, from, 0, 0, -cost});
		int m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	bool SPFA(int &flow, int &cost){
		for(int i = 0; i < n; ++i) d[i] = INF;
		memset(inq, 0, sizeof(inq));
		queue<int> Q; Q.push(s);
		d[s] = 0, inq[s] = 1, p[s] = 0, a[s] = INF;
		while(!Q.empty()){
			int u = Q.front(); Q.pop();
			inq[u] = 0;
			for(int i = 0; i < G[u].size(); ++i){
				Edge& e = edges[G[u][i]];
				if(e.cap > e.flow && d[e.to] > d[u] + e.cost){
					d[e.to] = d[u] + e.cost;
					p[e.to] = G[u][i];
					a[e.to] = min(a[u], e.cap - e.flow);
					if(!inq[e.to]) Q.push(e.to), inq[e.to] = 1;
				}
			}
		}
		if(d[t] == INF) return false;
		flow += a[t];
		cost += d[t] * a[t];
		int u = t;
		while(u != s){
			edges[p[u]].flow += a[t];
			edges[p[u]^1].flow -= a[t];
			u = edges[p[u]].from;
		}
		return true;
	}
	int MinCostMaxFlow(int s, int t){
		this->s = s, this->t = t;
		int flow = 0, cost = 0;
		while(SPFA(flow, cost));
		return flow;
	}
}solver;

int g[201][201];

vector<int> ones;

int vis[201];

void dfs(int u, int n, int m, int t){
	vis[u] = 1;
	for(int i = 1; i <= n; ++i){
		if(!vis[i] && g[u][i]){
			solver.AddEdge(t, i + m, 1, 0);
			dfs(i, n, m, t);
		}
	}
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		memset(g, 0, sizeof(g));
		ones.clear();
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		solver.init(n + m + 2);
		for(int i = 1; i <= m; ++i){
			solver.AddEdge(0, i, k, m - i);
		}
		for(int i = 1; i <= n; ++i){
			solver.AddEdge(m + i, n + m + 1, 1, 0);
		}
		for(int i = 1; i <= m; ++i){
			int op, u, v; scanf("%d", &op);
			if(op == 1){
				scanf("%d", &u);
				memset(vis, 0, sizeof(vis));
				dfs(u, n, m, i);
				solver.AddEdge(i, u + m, 1, 0);
				ones.push_back(i);
			}
			else if(op == 2){
				scanf("%d%d", &u, &v);
				if(u != v) g[u][v] = 1, g[v][u] = 1;
			}
			else{
				int p; scanf("%d", &p);
				while(p--){
					scanf("%d%d", &u, &v);
					g[u][v] = g[v][u] = 0;
				}
			}
		}
		int ans = solver.MinCostMaxFlow(0, n + m + 1);
		printf("%d\n", ans);
		for(int i = 0; i < ones.size(); ++i){
			printf("%d%c", solver.edges[(ones[i]-1)<<1].flow, i+1==ones.size()?'\n':' ');
		}
	}
	return 0;
}

