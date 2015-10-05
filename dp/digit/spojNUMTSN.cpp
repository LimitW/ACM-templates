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

LL dp[55][20][20][20];
int x[55];

LL dfs(int i, int a, int b, int c, bool less){
	if(i == -1) return less && a > 0 && a == b && a == c;
	if(less && dp[i][a][b][c] != -1) return dp[i][a][b][c];
	LL ans = 0;
	for(int j = 0; j <= 9; ++j){
		if(!less && j > x[i]) break;
		bool nxt = less || j < x[i];
		if(j == 3 && a < 17)
			ans = (ans + dfs(i - 1, a + 1, b, c, nxt)) % mod;
		else if(j == 6 && b < 17)
			ans = (ans + dfs(i - 1, a, b + 1, c, nxt)) % mod;
		else if(j == 9 && c < 17)
			ans = (ans + dfs(i - 1, a, b, c + 1, nxt)) % mod;
		else
			ans = (ans + dfs(i - 1, a, b, c, nxt)) % mod;
	}
	if(less) dp[i][a][b][c] = ans;
	return ans;
}

void addOne(char *s){
	int n = strlen(s), add = 1;
	for(int i = n - 1; add && i >= 0; --i){
		if(s[i] == '9') s[i] = '0';
		else ++s[i], --add;
	}
	if(add){
		s[n + 1] = 0;
		for(int i = n - 1; i >= 0; --i)
			s[i + 1] = s[i];
		s[0] = '1';
	}
}

LL solve(char *s){
	memset(x, 0, sizeof(x));
	int i = 0, j = strlen(s) - 1;
	while(j >= 0) x[j--] = s[i++] - '0';
	return dfs(strlen(s), 0, 0, 0, 0);
}

int main(){
	int T; scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	char a[55], b[55];
	for(int kase = 1; kase <= T; ++kase){
		scanf("%s%s", a, b);
		addOne(b);
		LL ans = solve(b) - solve(a);
		while(ans < 0) ans += mod;
		cout << ans << '\n';
	}
	return 0;
}


