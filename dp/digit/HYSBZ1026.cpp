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

LL dp[12][12];
LL pw[12];

LL dfs(int i, int p, bool less, bool zero, LL x){
	if(i == -1) return less;
	if(less && !zero && dp[i][p] != -1) return dp[i][p];
	int d = (x / pw[i]) % 10ll;
	LL ans = 0;
	for(int j = 0; j < 10; ++j){
		if(!less && j > d) break;
		bool nxt = less || j < d;
		if(zero) ans += dfs(i - 1, j, nxt, j == 0, x);
		else if(abs(j - p) > 1) ans += dfs(i - 1, j, nxt, 0, x);
	}
	if(less && !zero) dp[i][p] = ans;
	return ans;
}

LL A, B;

int main(){
	pw[0] = 1;
	for(int i = 1; i < 11; ++i){
		pw[i] = pw[i-1] * 10ll;
	}
	memset(dp, -1, sizeof(dp));
	while(~scanf("%lld%lld", &A, &B)){
		printf("%lld\n", dfs(10, 0, 0, 1, B + 1) - dfs(10, 0, 0, 1, A));
	}
	return 0;
}

