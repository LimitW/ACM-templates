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
const int maxn = 1e5 + 3;
const int maxm = 2e5 + 3;
const double eps = 1e-9;

int f[32][32];

void init(){
	f[0][0] = 1;
	for(int i = 1; i < 32; ++i){
		f[i][0] = 1;
		for(int j = 1; j <= i; ++j)
			f[i][j] = f[i-1][j] + f[i-1][j-1];
	}
}

int dfs(int x, int k){
	int ans = 0, tot = 0;
	for(int i = 31; i > 0; --i){
		if(x & (1 << i)){
			++tot;
			if(tot > k) break;
			x ^= (1 << i);
		}
		if((1 << i - 1) <= x)
			ans += f[i - 1][k - tot];
	}
	if(x + tot == k) ++ans;
	return ans;
}

int solve(int a, int b, int k){
	return dfs(b,k) - dfs(a-1,k);
}

int main(){
	init();
	int T; scanf("%d", &T);
	while(T--){
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		if(n == 0) ++n, --k;
		else if(m == 0) --m, --k;
		if(k == 0){
			puts("0");
			continue;
		}
		int o = 1, ng = 0;
		if(m < 0){
			n ^= (1 << 31), m ^= (1 << 31), ng = 1;
		}
		while(k > 0) k -= solve(n, m, o++);
		k += solve(n, m, --o);
		unsigned int l = n, r = m, ans;
		while(l <= r){
			unsigned int mid = l + r >> 1;
			int v = solve(n, mid, o);
			if(v < k) l = mid + 1;
			else if(v > k) r = mid - 1;
			else r = mid - 1, ans = mid;
		}
		printf("%d\n", ng == 1 ? (int)(ans ^ (1 << 31)) : (int)ans);
	}
	return 0;
}

