#include<iostream>
#include<queue>
#define cit(x,y,z)  for(int x=y;x<=z;x++)
const int inf = 1e6+5;
typedef long long ll;

using namespace std;
const int maxn = 1e4 + 5;
const int maxe = 1e6 + 5;
const int maxl = 103;

int n, e, ecnt = 0;
int head[maxn], in[maxn],cost[maxn],en[maxn];
struct node {
    int to,next;
}edges[maxe];

inline void addedge(int x, int y) {
    edges[ecnt].to = y;
    edges[ecnt].next = head[x];
    head[x] = ecnt++;
}

bool topo() {
    queue<int>Q;
    cit(j, 1, n) {
        if (in[j] == 0) {
            Q.push(j);
            en[j] = cost[j];
        }
    }
    cit(j, 0, n) {
        if (Q.empty())return 0;
        int tmp = Q.front(); Q.pop();
        for (int i = head[tmp]; ~i; i = edges[i].next) {
            int near = edges[i].to; in[near]--;
            if (en[near] < en[tmp] + cost[near]) {
                en[near] = en[tmp] + cost[near];
               
           }
            if (in[near] == 0)Q.push(near);
        }
    }
    return 1;
}

int main() {
    scanf("%d", &n);
    cit(i, 0, n + 1) head[i] = -1;
    int x, y, v;
    cit(i, 1, n) {
        scanf("%d%d", &x, &y);
        cost[x] = y;
        //en[x] = 0;
        while (1) {
            scanf("%d", &v);
            if (0 == v)break;
            addedge(v, x); 
            in[x]++;
        }
    }
    int ret = 0;
    topo();
    cit(i, 0, n)ret = max(ret, en[i]);
    printf("%d", ret);
    return 0;
}