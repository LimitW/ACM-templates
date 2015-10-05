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

bool f[100005];
int dp[100005];
int A[100005], C[100005];

int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) && (n || m)){
		memset(f, 0, sizeof(f));
		for (int i = 0; i < n; ++i){
			scanf("%d", &A[i]);
		}
		for (int i = 0; i < n; ++i){
			scanf("%d", &C[i]);
		}
		f[0] = 1;
		for (int i = 0; i < n; ++i){
			memset(dp, 0, sizeof(dp));
			for (int j = A[i]; j <= m; ++j){
				if (f[j] ||dp[j - A[i]] >= C[i] || !f[j - A[i]]) continue;
				dp[j] = dp[j - A[i]] + 1;
				f[j] = 1;
			}
		}
		int ans = 0;
		for (int j = 1; j <= m; ++j){
			if (f[j]) ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
