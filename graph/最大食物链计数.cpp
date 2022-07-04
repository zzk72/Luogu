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
const int maxn = 5005;
const int maxe = 1e5 + 5;

int n, e;
int in[maxn], out[maxn];
long long w[maxn];
vector<int>G[maxn];
void topo() {
    queue<int>Q;
    cit(i, 1, n) {
        if (0 == in[i]) {
            Q.push(i); w[i] = 1;
        }
    }
    cit(i, 1, n) {
        if (Q.empty())return;
        int u = Q.front();Q.pop();
        for (int i = 0; i < G[u].size();i++) {
            int to = G[u][i];
            w[to] += w[u];
            if (w[to] >= 80112002)w[to] %= 80112002;
            in[to]--;
            if (0 == in[to])Q.push(to);
        }
    }

}


int main() {
    n = read(); e = read();
    cit(i, 1, e) {
        int x = read(), y = read();
        G[x].push_back(y);
        in[y]++; out[x]++;
    }
    topo();
    long long ret=0;
    cit(i, 1, n) {
        if (0 == out[i]) ret =ret+w[i];
        if (ret >= 80112002)ret %= 80112002;
    }
    printf("%d", ret);
    return 0;
}
