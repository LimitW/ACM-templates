#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 3;

#define LL long long
#define pii pair<int, int>

//union-find set with weight
int p[maxn], d[maxn];

int getfa(int x){
	if(p[x] == x) return x;
	int fa = getfa(p[x]);
	d[x] += d[p[x]];
	return p[x] = fa;
}

bool Union(int u, int v, int w){
	int x = getfa(u), y = getfa(v);
	if(x == y) return d[v] == d[u] + w;
	p[y] = x;
	d[y] = d[u] + w - d[v];
	return 1;
}

int main(){
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		int ans = 0;
		memset(d, 0, sizeof(d));
		for(int i = 1; i <= n; ++i) p[i] = i;
		for(int i = 0; i < m; ++i){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			if(!Union(u, v, w)) ++ans;
		}
		cout << ans << '\n';
	}
	return 0;
}

