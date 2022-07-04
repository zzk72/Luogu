#include<iostream>
#include<string.h>
using namespace std;


const int maxn = 20005;
int n, tcnt = 0;
struct node {
	char key;
	int ls, rs;
}tree[maxn];
char rear[maxn], in[maxn];
int build(int s, int e, int ri) {
	if (s > e)return -1;
	int ret = tcnt++;
	tree[ret].key = rear[ri];
	int r;
	for (r = s; r <= e && in[r] != rear[ri]; r++);
	tree[ret].ls = build(s, r - 1, ri - 1 - (e - r));
	tree[ret].rs = build(r + 1, e, ri - 1);

	return ret;
}


void dfs(int root) {
	if (-1 == root)return;
	printf("%c", tree[root].key);
	dfs(tree[root].ls);
	dfs(tree[root].rs);
}
int main() {
	scanf("%s", in);
	scanf("%s", rear);
	n = strlen(in);
	int root = build(0, n - 1, n - 1);
	dfs(root);
	return 0;
}