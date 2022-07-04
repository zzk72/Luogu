#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define cit(x,y,z)  for(int x=y;x<=z;x++)

inline int read() {
    int x = 0; int w = 1; register char c = getchar();
    for (; c ^ '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-') w = -1, c = getchar();
    for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    return x * w;
}
using namespace std;
const int maxn = 1e5 + 5;
const int maxe = 1e6 + 5;

int n, e;
int vis[maxn];
vector<int>G[maxn];
int b = 0, d = 0;

void dfs(int u) {
    if (vis[u])return;
    printf("%d", u); d++;
    if (d < n)printf(" ");
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); i++) {
        int to = G[u][i];
        if (!vis[to])dfs(to);
    }
}
void bfs() {
    cit(i, 0, n)vis[i] = 0;
    queue<int>Q;
    Q.push(1); vis[1] = 1;
    while (!Q.empty()) {
        int u = Q.front();Q.pop();
        printf("%d", u); b++;
        if (b < n)printf(" ");
        for (int i = 0; i < G[u].size(); i++) {
            int to = G[u][i];
            if (!vis[to]) {
                Q.push(to); vis[to] = 1;
            }
        }
    }

}

int main() {
    n = read(); e = read();
    cit(i, 1, e) {
        int x = read(), y = read();
        G[x].push_back(y);
    }
    cit(i, 1, n) {
        sort(G[i].begin(), G[i].end());
    }
    dfs(1);
    printf("\n");
    bfs();
    return 0;
}
