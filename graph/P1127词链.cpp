#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define cit(x,y,z)  for(int x=y;x<=z;x++)
//Å·À­Â·

using namespace std;
const int maxn = 30;
const int maxe = 1005;

int n;
int vis[maxn];
vector<pair<int,string> >G[maxn];
vector<string> word;
void dfs() {

}

int main() {
    scanf("%d", &n);
    string tmp;
    cit(i, 1, n) {
        cin >> tmp;
        word.push_back(tmp);
        G[tmp.front() - 'a'].push_back(make_pair( * tmp.end() - 'a',tmp));
    }

    cit(i, 1, n) {
        sort(G[i].begin(), G[i].end());
    }
   
    return 0;
}
