#include<bits/stdc++.h>
const int maxn = 500500;
int n, m, s;
struct T{ int to, nxt; } way[maxn << 1];
int h[maxn], num;
int st[20][maxn], dfn[maxn], tot;
inline int min(int x,int y){ return dfn[x] < dfn[y] ? x : y; }
inline void link(int x,int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
inline void dfs(int x,int fa = 0) {
	st[0][tot] = fa, dfn[x] = ++tot;
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != fa)
		dfs(way[i].to, x);
}
inline int lca(int x,int y) {
	if(dfn[x] > dfn[y]) std::swap(x, y);
	const int lg = std::__lg(dfn[y] - dfn[x]);
	return x != y ? min(st[lg][dfn[x]], st[lg][dfn[y] - (1 << lg)]) : x;
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> s;
	for(int i = 1,x,y;i < n;++i)
		std::cin >> x >> y, link(x,y);
	dfs(s);
	for(int i = 1;i < 20;++i) for(int j = 1;j + (1 << i) - 1 < n;++j)
		st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
	for(int i = 1,x,y;i <= m;++i) {
		std::cin >> x >> y;
		std::cout << lca(x,y) << '\n';
	}
}
 
