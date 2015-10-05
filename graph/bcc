#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 3;
const int maxm = 2e5 + 3;
const double eps = 1e-9;

struct Edge{
	int u, v, nxt;
}E[maxm];

int n, m, e, ck;
int head[maxn];

void addedge(int u, int v){
	E[e].u = u, E[e].v = v;
	E[e].nxt = head[u], head[u] = e++;
}

int low[maxn], pre[maxn];
int ans[maxm >> 1];


//edge-biconnect
int bcc_cnt;
stack<int> S;
vector<int> bcc[maxn];

int dfs(int u, int fa){
	int lowu = pre[u] = ++ck;
	S.push(u);
	int child = 0;
	for(int i = head[u]; i != -1; i = E[i].nxt){
		int v = E[i].v;
		if(!pre[v]){
			++child;
			int lowv = dfs(v, u);
			lowu = min(lowv, lowu);
		}
		else if(pre[v] < pre[u] && v != fa){
			lowu = min(lowu, pre[v]);
		}
	}
	low[u] = lowu;
	if(low[u] == pre[u]){
		bcc[++bcc_cnt].clear();
		while(true){
			int x = S.top();
			S.pop();
			bcc[bcc_cnt].push_back(x);
			if(x == u) break;
		}
	}
	return lowu;
}

//point-biconnect
int pbcc_cnt;
stack<int> pS;
vector<int> pbcc[maxm>>1];

int dfs2(int u, int fa){
	int lowu = pre[u] = ck++;
	int child = 0;
	for(int i = head[u]; i != -1; i = E[i].nxt){
		int v = E[i].v;
		if(!pre[v]){
			++child;
			pS.push(i);
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if(lowv >= pre[u]){
				pbcc[++pbcc_cnt].clear();
				while(true){
					int x = pS.top();
					pS.pop();
					pbcc[pbcc_cnt].push_back(((x|1)+1)>>1);
					if(E[x].u == u && E[x].v == v) break;
				}
			}
		}
		else if(pre[v] < pre[u] && v != fa){
			pS.push(i);
			lowu = min(lowu, pre[v]);
		}
	}
	low[u] = lowu;
	return lowu;
}

int main(){
	while(~scanf("%d%d", &n, &m)){
		memset(head, -1, sizeof(head));
		memset(pre, 0, sizeof(pre));
		memset(low, 0, sizeof(low));
		e = ck = bcc_cnt = pbcc_cnt = 0;
		for(int i = 0; i < m; ++i){
			int u, v; scanf("%d%d", &u, &v);
			addedge(u, v);
			addedge(v, u);
		}
		for(int i = 1; i <= n; ++i)
			if(!pre[i]) dfs2(i, -1);
		for(int i = 1; i <= pbcc_cnt; ++i)
			sort(pbcc[i].begin(), pbcc[i].end());
		for(int i = 1; i <= pbcc_cnt; ++i){
			for(int j = 0; j < pbcc[i].size(); ++j)
				ans[pbcc[i][j]] = pbcc[i][0];
		}
		printf("%d\n", bcc_cnt);
		for(int i = 1; i <= m; ++i){
			printf("%d%c", ans[i], i == m ? '\n' : ' ');
		}
	}
    return 0;
}

