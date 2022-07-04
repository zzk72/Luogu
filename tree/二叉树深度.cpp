#include<iostream>
#define cit(x,y,z)  for(int x=y;x<=z;x++)
#define inf 0x3f3f3f3f

inline int read() {
    int x = 0; int w = 1; register char c = getchar();
    for (; c ^ '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-') w = -1, c = getchar();
    for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    return x * w;
}
using namespace std;
const int maxn = 1e6 + 5;
const int maxe = 1e6 + 5;

int n, e, ecnt = 0;
int head[maxn], vis[maxn];
struct node {
    int to, next;
}edges[maxe << 1 + 1];//链式前向星存无向图要开二倍空间，一条边存两次,切记切记

int dfs(int u) {
    vis[u] = 1;
    if (head[u] == -1)return 1;
    int h = 1;
    for (int i = head[u]; ~i; i = edges[i].next) {
        h=max(h,dfs(edges[i].to));
    }
    return h + 1;
}

inline void addedge(int x, int y) {//头插法
    edges[ecnt].to = y;
    edges[ecnt].next = head[x];
    head[x] = ecnt++;
}

int main() {
    n = read(); 
    cit(i, 0, n) {
        head[i] = -1;
    }
    cit(i, 1, n) {
        int x = read(), y = read();
        if(x)addedge(i, x); 
        if(y)addedge(i, y);
    }
    int ret = dfs(1);
    cout << ret;
}
