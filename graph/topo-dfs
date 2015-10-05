//============================================================================
// Name        : LA4255.cpp
// Author      : LimitW
// Date        : 2014.11.4
// Version     :
// Copyright   : LA4255  AOAPC
// Description : Topological Sort
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cstdlib>
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
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

int ans[12] , sum[12] , topo[12];
int G[12][12];
int vis[12];
int t;

bool dfs(int u,int n){
    vis[u] = -1;
    for(int v = 0; v <= n; v++){
        if(G[u][v] != 0){
            if(vis[v] < 0) return false;
            else if(!vis[v] && !dfs(v,n)) return false;
        }
    }
    vis[u] = 1; topo[t--] = u;
    return true;
}

bool toposort(int n){
    t = n;
    memset(vis,0,sizeof(vis));
    for(int u = 0; u <= n; u++){
        if(!vis[u]){
            if(!dfs(u,n)) return false;
        }
    }
    return true;
}

vector<pii> v;

int main(){
    int T; cin >> T;
    while(T--){
    	v.clear();
        memset(G,0,sizeof(G));
        int n; cin >> n;
        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j++)
            {
                char x; cin >> x;
                if(x == '-') G[j][i-1] = 1;
                if(x == '0') v.push_back(make_pair(i-1,j));
                if(x == '+') G[i-1][j] = 1;
            }
        toposort(n);
        memset(sum,-1,sizeof(sum));
        sum[0] = 0;
        int pos = 0;
        for(pos = 0; pos <= n; pos++){
        	if(sum[topo[pos]] == 0) break;
        }
        for(int i = pos - 1; i >= 0; i--){
        	sum[topo[i]] = sum[topo[i+1]] - 1;
        }
        for(int i = pos + 1; i <= n; i++){
        	sum[topo[i]] = sum[topo[i-1]] + 1;
        }
        for(int i = 0; i < v.size(); i++)
        {
        	sum[v[i].second] = sum[v[i].first];
        }
        for(int i = 1; i <= n; i++){
            ans[i] = sum[i] - sum[i-1];
            if( i != n ) printf("%d ",ans[i]);
            else printf("%d\n",ans[n]);
        }
    }
    return 0;
}
