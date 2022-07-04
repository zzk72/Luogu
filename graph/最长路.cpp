#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define cit(x,y,z)  for(int x=y;x<=z;x++)
const int inf = 1e9 + 5;

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
int path[maxn],dist[maxn];
vector<pair<int, int> >G[maxn];

bool bellfd() {
	for (int i = 1; i <=n; i++) {						
		path[i] = -1; dist[i] = inf; 	
	}													
	dist[1] = 0;										

	for (int i = 0; i < n; i++) {//
		bool relaxed = false;//基本优化，放松标记
		for (int j = 1; j <= n; j++) {//对所有边进行松弛操作
			for (int k = 0; k < G[j].size();k++) {
				int to = G[j][k].first;
				if (dist[to] > dist[j] + G[j][k].second) {
					dist[to] = dist[j] + G[j][k].second;
					path[to] = j;
					relaxed = true;
				}
			}
		}
		if (!relaxed)break;//若一次遍历无放松，则可直接停止
	}
	for (int j = 1; j <= n; j++) {//对所有边进行松弛操作
		for (int k = 0; k < G[j].size(); k++) {
			int to = G[j][k].first;
			if (dist[to] > dist[j] + G[j][k].second) {
				return false;
			}
		}
	}
	return true;
}

int main() {
    n = read(); e = read();
    cit(i, 1, e) {
        int x = read(), y = read(),w=read();
        G[x].push_back(make_pair(y, -w));
    }
	bellfd();
	if (dist[n]!=inf)printf("%d", -dist[n]);
	else printf("-1");
    return 0;
}
