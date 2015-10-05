//HDU2255
//KM, max weight match, n^3
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
const int maxn = 300 + 3;
const int maxm = maxn * maxn;

class KM{
public:
	int n, m;
	int g[maxn][maxn];
	int link[maxn], lx[maxn], ly[maxn];
	int slack[maxn];
	bool visx[maxn], visy[maxn];
	bool dfs(int x){
		visx[x] = 1;
		for(int y = 0; y < m; ++y){
			if(visy[y]) continue;
			int tmp = lx[x] + ly[y] - g[x][y];
			if(!tmp){
				visy[y] = 1;
				if(link[y] == -1 || dfs(link[y])){
					link[y] = x;
					return 1;
				}
			}
			else if(slack[y] > tmp)
				slack[y] = tmp;
		}
		return 0;
	}

	int km(){
		memset(link, -1, sizeof(link));
		memset(ly, 0, sizeof(lx));
		memset(lx, 0, sizeof(lx));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				lx[i] = max(lx[i], g[i][j]);
		for(int x = 0; x < n; ++x){
			memset(slack, INF, sizeof(slack));
			while(1){
				memset(visx, 0, sizeof(visx));
				memset(visy, 0, sizeof(visy));
				if(dfs(x)) break;
				int d = INF;
				for(int i = 0; i < m; ++i)
					if(!visy[i] && d > slack[i])
						d = slack[i];
				for(int i = 0; i < n; ++i)
					if(visx[i]) lx[i] -= d;
				for(int i = 0; i < m; ++i){
					if(visy[i]) ly[i] += d;
					else slack[i] -= d;
				}
			}
		}
		int res = 0;
		for(int i = 0; i < m; ++i)
			if(~link[i]) res += g[link[i]][i];
		return res;
	}

	void gragh(int nn){
		m = n = nn;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				scanf("%d", &g[i][j]);
	}

};


int main(){
	int n;
	while(~scanf("%d", &n)){
		KM g; g.gragh(n);
		printf("%d\n", g.km());
	}
	return 0;
}
