#include<iostream>
#include<string.h>
using namespace std;


const int maxn = 20005;
int n,tcnt=0;
struct node {
	char key;
	int ls, rs;
}tree[maxn];
char pre[maxn], in[maxn];
int build(int s, int e, int pi) {
	if (s > e)return -1;
	int ret = tcnt++;
	tree[ret].key= pre[pi];
	int r;
	for (r = s; r <= e && in[r] != pre[pi]; r++);
	tree[ret].ls = build(s, r - 1, pi + 1);
	tree[ret].rs = build(r + 1, e, pi + 1 + r - s);
	return ret;
}


void dfs(int root) {
	if (-1==root)return;
	dfs(tree[root].ls);
	dfs(tree[root].rs);
	printf("%c", tree[root].key);
}
int main() {
	scanf("%s", in);
	scanf("%s", pre);
    n = strlen(pre);
	int root = build(0, n - 1, 0);
	dfs(root);
	return 0;
}