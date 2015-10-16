#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 3;

int a[maxn], d[maxn], f[maxn];

int main(){
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		int n, l; scanf("%d%d", &n, &l);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		int len = 0;
		d[0] = -INF;
		for(int i = n; i > 0; --i){
			if(-a[i] > d[len]){
				d[++len] = -a[i];
				f[i] = len;
			}
			else{
				int p = lower_bound(d, d + len + 1, -a[i]) - d;
				d[p] = -a[i];
				f[i] = p;
			}
		}
		int ans = 0; len = 0;
		for(int i = l + 1; i <= n; ++i){
			int p = lower_bound(d, d + len + 1, a[i]) - d;
			ans = max(ans, p - 1 + f[i]);
			if(a[i-l] > d[len]) d[++len] = a[i-l];
			else{
				int p = lower_bound(d, d + len + 1, a[i-l]) - d;
				d[p] = a[i-l];
			}
		}
		printf("Case #%d: %d\n", kase, max(len, ans));
	}
	return 0;
}

