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

int mp[9][9];
int fac[10];
bool hs[370000];
vector<pii> pre;

char tar[10] = "123456789";
int tarhs;
const int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
char pt[5] = "udlr";

int geths(char *s){
	int ans = 0;
	for(int i = 0; i < 9; ++i){
		int tmp = 0;
		for(int j = i + 1; j < 9; ++j){
			if(s[i] > s[j]) ++tmp;
		}
		ans += tmp * fac[8-i];
	}
	return ans;
}

int geth(char *s){
	int ans = 0;
	for(int i = 0; i < 9; ++i){
		if(s[i] != tar[i])
			ans += mp[s[i]-'0'][tar[i]-'0'];
	}
	return ans;
}

struct node {
	int x,y,hs;
	int f,g,h;
	char st[10];
	int dr,id;
	node(char* s,int gg = 0,int op = -1,int idd = 0){
		strcpy(st,s);
		for(int i = 0; i < 9; ++i)
			if(s[i] == '9'){
				x = i / 3;
				y = i % 3;
				break;
			}
		hs = geths(st);
		h = geth(st);
		g = gg;
		f = g + h;
		dr = op;
		id = idd;
	}
	bool operator < (node b) const {
		return f > b.f;
	}
};

void print(pii x){
	if(x.first != -1)
		print(pre[x.second]);
	if(x.first != -1)
		putchar(pt[x.first]);
}
priority_queue<node> pq;

bool bfs(node x){
	while(!pq.empty()) pq.pop();
	memset(hs,0,sizeof(hs));
	pre.clear();
	pq.push(x);
	hs[x.hs] = 1;
	pre.push_back(make_pair(x.dr,-1));
	while(!pq.empty()){
		node tp = pq.top();
		pq.pop();
		if(tp.hs == tarhs){
			print(make_pair(tp.dr,pre[tp.id].second));
			puts("");
			return 1;
		}
		for(int i = 0; i < 4; ++i){
			int dx = tp.x + dir[i][0] , dy = tp.y + dir[i][1];
			if(dx < 3 && dx >= 0 && dy < 3 && dy >= 0){
				char ss[10];
				strcpy(ss,tp.st);
				swap(ss[tp.x*3+tp.y],ss[dx*3+dy]);
				node nxt(ss,tp.g+1,i,pre.size());
				if(!hs[nxt.hs]){
					hs[nxt.hs] = 1;
					pq.push(nxt);
					pre.push_back(make_pair(nxt.dr,tp.id));
				}
			}
		}
	}
	return 0;
}

void init(){
	for(int i = 0; i < 9; ++i){
		for(int j = i + 1; j < 9; ++j){
			mp[i][j] = mp[j][i] = abs(i/3-j/3)+abs(i%3-j%3);
		}
	}
	fac[0] = 1;
	for(int i = 1; i <= 9; ++i){
		fac[i] = fac[i-1] * i;
	}
	tarhs = geths(tar);
}

bool check(char* s){
	int ans = 0;
	for(int i = 0; i < 9; ++i){
		if(s[i] == '9') continue;
		for(int j = 0; j < i; ++j){
			if(s[j] == '9') continue;
			if(s[j] > s[i]) ++ans;
		}
	}
	return !(ans & 1);
}

int main(){
	init();
	char s[10];
	while((cin >> s[0]) != NULL){
		if(s[0] == 'x') s[0] = '9';
		for(int i = 1; i < 9; ++i){
			cin >> s[i];
			if(s[i] == 'x') s[i] = '9';
		}
		if(!check(s))
			printf("unsolvable\n");
		else bfs(node(s,0));
	}
    return 0;
}

