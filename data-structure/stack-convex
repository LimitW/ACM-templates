#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const int maxn = 1e5 + 3;

struct node{
	int x, h, id;
	bool operator < (node b) const {
		return x < b.x;
	}
}a[2*maxn];

double ans[maxn];

stack<pair<int, double> > S;

int n, m;

void solve(){
	while(!S.empty()) S.pop();
	S.push(make_pair(0, 0));
	for(int i = 1; i < n; ++i){
		while(!S.empty()){
			int x = S.top().first;
			if(a[i].h >= a[x].h){
				S.pop();
				continue;
			}
			double pre = S.top().second;
			double k = 1.0 * (a[x].h - a[i].h) / (a[i].x - a[x].x);
			if(k <= pre) S.pop();
			else{
				if(a[i].id != -1){
					int x = S.top().first;
					ans[a[i].id] += atan(1.0 * (a[i].x - a[x].x) / a[x].h);
				}
				S.push(make_pair(i, k));
				break;
			}
		}
		if(S.empty()) S.push(make_pair(i, 0));
	}
}

int main(){
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		memset(ans, 0, sizeof(ans));
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &a[i].x, &a[i].h);
			a[i].id = -1;
		}
		scanf("%d", &m);
		for(int i = 0; i < m; ++i){
			int v; scanf("%d", &v);
			a[i+n].x = v;
			a[i+n].h = 0;
			a[i+n].id = i;
		}
		n += m;
		sort(a, a + n);
		solve();
		for(int i = 0; i < n; ++i)
			a[i].x = -a[i].x;
		sort(a, a + n);
		solve();
		printf("Case #%d:\n", kase);
		for(int i = 0; i < m; ++i)
			printf("%.10f\n", ans[i]/pi*180);
	}
	return 0;
}

