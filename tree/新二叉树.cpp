#include<iostream>
#include<vector>
using namespace std;
const int maxn = 128;

int n, in[maxn],be[maxn];
vector<int>G[maxn];

void dfs(int u) {
    printf("%c", u);
    for (int i = 0; i < G[u].size();i++) {
        dfs(G[u][i]);
    }
}


int main() {
    scanf("%d", &n);
   
    char r, ls, rs;
    char s[10];
    for (int i = 1; i <= n;i++) {
        scanf("%s", s);
        r = s[0]; ls = s[1], rs = s[2];
        be[r] = 1, be[ls] = 1, be[rs] = 1;
        if (ls != '*')G[r].push_back(ls),in[ls]++;
        if (rs != '*')G[r].push_back(rs),in[rs]++;

    }
    int root='a';
    for (int i = 'a'; i <= 'z'; i++) {
        if (be[i]&&in[i] == 0)root = i;
   }
     dfs(root); 
     return 0;
}
