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

//i-th bit
//Current a,b,k is less than A,B,K or not.
LL dp[32][2][2][2];
int a, b, k;

int getBit(int num, int i){
	return (num >> i) & 1;
}

LL dfs(int i, int la, int lb, int lk){
	if(i == -1)
		return la && lb && lk;
	if(dp[i][la][lb][lk] != -1)
		return dp[i][la][lb][lk];
	int ma = la || getBit(a, i);
	int mb = lb || getBit(b, i);
	int mk = lk || getBit(k, i);
	dp[i][la][lb][lk] = dfs(i - 1, ma, mb, mk); // 0 0 0
	if(ma) dp[i][la][lb][lk] += dfs(i - 1, la, mb, mk); // 1 0 0
	if(mb) dp[i][la][lb][lk] += dfs(i - 1, ma, lb, mk); // 0 1 0
	if(ma && mb && mk) //1 1 1
		dp[i][la][lb][lk] += dfs(i - 1, la, lb, lk);
	return dp[i][la][lb][lk];
}

int main(){
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		memset(dp, -1, sizeof(dp));
		scanf("%d%d%d", &a, &b, &k);
		printf("Case #%d: %lld\n", kase, dfs(31, 0, 0, 0));
	}
	return 0;
}

