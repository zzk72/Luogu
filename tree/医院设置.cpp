#include<iostream>
using namespace std;
inline int read() {
    int x = 0; int w = 1; register char c = getchar();
    for (; c ^ '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-') w = -1, c = getchar();
    for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    return x * w;
}

const int maxn = 1005;
int ecnt = 1;
int head[maxn], tot, n, deep[maxn], sz[maxn], pre[maxn], ans, dis[maxn];

struct edge {
    int to, next;
}edges[maxn << 1];
inline void addedge(int x, int y) {
    edges[ecnt].to = y;
    edges[ecnt].next = head[x];
    head[x] = ecnt++;
}
inline void dfs(int rt, int fa) {//dfsԤ�����õ�ÿ���ڵ����ȼ������Ĵ�С
    deep[rt] = deep[fa] + 1;
    for (int i = head[rt]; i; i = edges[i].next) {
        if (edges[i].to == fa)continue;
        dfs(edges[i].to, rt);
        pre[rt] += pre[edges[i].to];
    }
}

inline void dp(int rt, int fa) {
    for (int i = head[rt]; i; i = edges[i].next) {
        if (edges[i].to == fa)continue;
        dis[edges[i].to] = dis[rt] + pre[1] - pre[edges[i].to]*2;//preΪ�������Ĵ�С��һ���һ��һ���һ;
        if (dis[edges[i].to] < ans)ans = dis[edges[i].to];
        dp(edges[i].to, rt);
    }
}
int main() {
   n=read();
    for (register int i = 1; i <= n; ++i) {
        int a, b;
        sz[i]=read(); a=read(); b=read();
        pre[i] = sz[i];
        if (a) {
            addedge(i, a);
            addedge(a, i);
        }
        if (b) {
            addedge(i, b);
            addedge(b, i);
        }
    }
    dfs(1, 0);
    for ( int i = 1; i <= n; ++i) {
        dis[1] += (deep[i] - 1) * sz[i];
    }
    ans = dis[1];
    dp(1, 0);
    printf("%d",ans);
    return 0;
}

