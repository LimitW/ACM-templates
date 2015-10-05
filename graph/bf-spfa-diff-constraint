//#pragma comment(linker, "/STACK:1024000000,1024000000")

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

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int maxn = 100 + 10;
const int maxm = 2 * maxn;

int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int n, m, e;

int head[maxn], nxt[maxm];
int u[maxm], v[maxm], w[maxm];
int dist[maxn];

void addedge(int uu,int vv,int ww){
	u[e] = uu, v[e] = vv, w[e] = ww;
	nxt[e] = head[uu], head[uu] = e++;
}

bool relax(int uu,int vv,int ww){
	if(dist[vv] > dist[uu] + ww){
		dist[vv] = dist[uu] + ww;
		return 1;
	}
	return 0;
}

bool bellmanford(int s){
	for(int i = 0; i <= n; ++i){
		dist[i] = INF;
	}
	dist[s] = 0; bool flag;
	for(int i = 0; i < n + 1; ++i){
		flag = false;
		for(int j = 0; j < e; ++j){
			if(relax(u[j],v[j],w[j]))
				flag = true;
		}
		if(!flag) break;
	}
	for(int j = 0; j < e; ++j){
		if(relax(u[j],v[j],w[j]))
			return 0;
	}
	return 1;
}

queue<int> q;
int inq[maxn], in[maxn];

bool spfa(int s){
	memset(inq,0,sizeof(inq));
	memset(in,0,sizeof(in));
	while(!q.empty()) q.pop();
	for(int i = 0; i <= n; ++i)
		dist[i] = (i == s ? 0 : INF);
	q.push(s), inq[s] = 1, ++in[s];
	while(!q.empty()){
		int tp = q.front();
		q.pop(), inq[tp] = 0;
		for(int ee = head[tp]; ee != -1; ee = nxt[ee]){
			if(relax(u[ee],v[ee],w[ee])){
				if(!inq[v[ee]]){
					q.push(v[ee]), inq[v[ee]] = 1, ++in[v[ee]];
					if(in[v[ee]] > n + 1)
						return 0;
				}
			}
		}
	}
	return 1;
}

int main(){
	while(scanf("%d",&n) && n){
		scanf("%d",&m);
		e = 0;
		memset(head,-1,sizeof(head));
		int a,b,k; char s[3];
		for(int i = 0; i < m; ++i){
			scanf("%d %d %s %d",&a,&b,s,&k);
			b += a, --a;
			if(s[0] == 'g') addedge(b,a,-k-1);
			else addedge(a,b,k-1);
		}
		for(int i = 0; i <= n; ++i)
			addedge(n+1,i,0);
		if(bellmanford(n+1)) puts("lamentable kingdom");
	//	if(spfa(n+1)) puts("lamentable kingdom");
		else puts("successful conspiracy");
	}
	return 0;
}

