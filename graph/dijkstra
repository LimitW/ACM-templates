//构造最短路问题 Dijkstra
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <bitset>
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>

const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 5e4 + 3;
const int mod = 1e9 + 7;


LL wn[maxn],w[maxn*2],dist[maxn];
int vis[maxn];
int head[maxn],nxt[maxn*2],u[maxn*2],v[maxn*2];
int e;
priority_queue<pii,vector<pii>,greater<pii> > pq;

void addedge(int uu,int vv,int ww){
	u[e] = uu; v[e] = vv; w[e] = ww;
	nxt[e] = head[uu]; head[uu] = e++;
}

void Dijkstra(int n){
	while(!pq.empty()) pq.pop();
	memset(vis,0,sizeof(vis));
	dist[1] = 0;
	for(int i = 2; i <= n; ++i){
		dist[i] = INF;
	}
	pq.push(make_pair(dist[1],1));
	while(!pq.empty()){
		pii tp = pq.top(); pq.pop();
		int uu = tp.second;
		if(vis[uu]) continue; vis[uu] = 1;
		for(int e = head[uu]; e != -1; e = nxt[e]){
			if(vis[v[e]]) continue;
			if(dist[v[e]] > dist[uu] + w[e]){
				dist[v[e]] = dist[uu] + w[e];
				pq.push(make_pair(dist[v[e]],v[e]));
			}
		}
	}
}

int main(){
	int T; scanf("%d",&T);
	for(int kase = 0; kase < T; ++kase){
		e = 0;
		memset(head,-1,sizeof(head));
		int n,m; scanf("%d%d",&n,&m);
		for(int i = 0; i < n; ++i)
			scanf("%lld",&wn[i]);
		for(int i = 0; i < m; ++i){
			int uu,vv; LL ww;
			scanf("%d%d%lld",&uu,&vv,&ww);
			addedge(uu,vv,ww);
			addedge(vv,uu,ww);
		}
		Dijkstra(n);
		LL ans = 0;
		for(int i = 2; i <= n; ++i){
			if(dist[i] >= INF){ ans = -1; break; }
			ans += dist[i] * wn[i-1];
		}
		if(ans == -1) puts("No Answer");
		else printf("%lld\n",ans);
	}
    return 0;
}
