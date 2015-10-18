#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 57;

const int x = 133;

const int maxn = 1e5 + 3;

int xp[maxn], sp[maxn];
char s[maxn];

struct node{
    int l, r, h, lazy;
}st[maxn<<2];

void pushup(int o){
    int lsl = st[o<<1].r - st[o<<1].l + 1;
    st[o].h = ((1ll * st[o<<1|1].h * xp[lsl] % mod) + st[o<<1].h) % mod;
}

void pushdown(int o){
    if(st[o].lazy != -1){
        st[o<<1].lazy = st[o<<1|1].lazy = st[o].lazy;
        int lsl = st[o<<1].r - st[o<<1].l + 1;
        int rsl = st[o<<1|1].r - st[o<<1|1].l + 1;
        st[o<<1].h = (1ll * st[o].lazy * sp[lsl-1]) % mod;
        st[o<<1|1].h = (1ll * st[o].lazy * sp[rsl-1]) % mod;
        st[o].lazy = -1;
    }
}

void build(int o, int l, int r){
    st[o].l = l, st[o].r = r, st[o].lazy = -1;
    if(l == r) { st[o].h = s[l-1]; return; }
    int mid = l + r >> 1;
    build(o<<1, l, mid);
    build(o<<1|1, mid+1, r);
    pushup(o);
}

void update(int o, int l, int r, int v){
    if(st[o].l == l && st[o].r == r){
        int rl = st[o].r - st[o].l + 1;
        st[o].h = (1ll * v * sp[rl-1]) % mod;
        st[o].lazy = v;
        return;
    }
    pushdown(o);
    int mid = st[o].l + st[o].r >> 1;
    if(l > mid) update(o<<1|1, l, r, v);
    else if(r <= mid) update(o<<1, l, r, v);
    else{
        update(o<<1, l, mid, v);
        update(o<<1|1, mid+1, r, v);
    }
    pushup(o);
}

int query(int o, int l, int r){
    if(st[o].l == l && st[o].r == r)
        return st[o].h;
    pushdown(o);
    int ans = 0;
    int mid = st[o].l + st[o].r >> 1;
    if(l > mid) ans = query(o<<1|1, l, r);
    else if(r <= mid) ans = query(o<<1, l, r);
    else {
    	//IMPORTANT!!
    	//lsl != st[o].l + st[o].r >> 1;
        int lsl = mid - l + 1;
        ans = (1ll * query(o<<1|1, mid+1, r) * xp[lsl]) % mod;
        ans = (ans + query(o<<1, l, mid)) % mod;
    }
    return ans;
}

int main(){
    xp[0] = sp[0] = 1;
    for(int i = 1; i < maxn; ++i){
        xp[i] = 1ll * xp[i-1] * x % mod;
        sp[i] = (sp[i-1] + xp[i]) % mod;
    }
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    scanf("%s", s);
    build(1, 1, n);
    int op, l, r, v;
    for(int i = 0; i < m + k; ++i){
        scanf("%d%d%d%d", &op, &l, &r, &v);
        if(op == 2){
            if(r - l + 1 <= v) puts("YES");
            else{
                int hsl = query(1, l, r - v);
                int hsr = query(1, l + v, r);
                puts(hsl == hsr ? "YES" : "NO");
            }
        }
        else update(1, l, r, v + '0');
    }
    return 0;
}

