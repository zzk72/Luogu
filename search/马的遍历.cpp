#include<iostream>
#include<queue>

using namespace std;
const int maxn = 2e6;
const int inf = 0x3f3f3f3f;
int r[9] = { 1,2,2,1,-1,-2,-2,-1 };
int c[9] = { 2,1,-1,-2,-2,-1,1,2 };
int n, m, x, y,vis[405][405];
int ans[405][405];
int main() {
	scanf("%d%d%d%d", &m, &n, &x, &y);
	queue<pair<int,int> > Q;
	Q.push(make_pair(x, y));
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++)
			ans[i][j] = -1;
	ans[x][y] = 0;
	while (!Q.empty()) {
		int xx = Q.front().first;
		int yy = Q.front().second;
		Q.pop();
		if (vis[xx][yy])continue;
		//cout << xx << " " << yy << '\n';
		vis[xx][yy] = 1;
		for (int i = 0; i < 8; i++) {
			int tx = xx + r[i], ty = yy + c[i];
			if ((ans[tx][ty] > ans[xx][yy] + 1 || ans[tx][ty] == -1) && tx <= m && ty <= n && tx > 0 && ty > 0) {
				ans[tx][ty] = ans[xx][yy] + 1;
				Q.push(make_pair(tx, ty));
			}
		}
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			printf("%-5d", ans[i][j]);
			if (j == n)printf("\n");
		}
	return 0;
}