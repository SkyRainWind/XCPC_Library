// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 10005;

template<class T>
struct Flow {
    const int n;
    struct Edge {
        int to;
        T cap;
        Edge(int to, T cap) : to(to), cap(cap) {}
    };
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, h;
    Flow(int n) : n(n), g(n) {}
    
    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            const int u = que.front();
            que.pop();
            for (int i : g[u]) {
                auto v=e[i].to, c=e[i].cap;
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t) {
                        return true;
                    }
                    que.push(v);
                }
            }
        }
        return false;
    }
    
    T dfs(int u, int t, T f) {
        if (u == t) {
            return f;
        }
        auto r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            const int j = g[u][i];
            auto v=e[j].to, c=e[j].cap;
            if (c > 0 && h[v] == h[u] + 1) {
                auto a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0) {
                    return f;
                }
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, T c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    T maxFlow(int s, int t) {
        T ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, std::numeric_limits<T>::max());
        }
        return ans;
    }
};

int n,a[maxn],b[maxn],bela[maxn],belb[maxn];

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	memset(bela,-1,sizeof bela);
	memset(belb,-1,sizeof belb);
	
	for(int i=1;i<=n;i++)
		if(~bela[i])continue;
		else{
			int j = i;
			while(bela[j] == -1){
				bela[j] = i;
				j = a[j];
			}
		}
	for(int i=1;i<=n;i++)
		if(~belb[i])continue;
		else{
			int j = i;
			while(belb[j] == -1){
				belb[j] = i;
				j = b[j];
			}
		}
	
	Flow<int> flow(2*n + 3);
	for(int i=1;i<=n;i++)
		flow.addEdge(bela[i], n + belb[i], 1);
	for(int i=1;i<=n;i++)
		flow.addEdge(2*n+1, i, 1),
		flow.addEdge(n+i, 2*n+2, 1);
	flow.maxFlow(2*n+1, 2*n+2);
	vector<int>ans;
	for(int i=0;i<n;i++)
		if(flow.e[2*i].cap)ans.push_back(i + 1);
	printf("%d\n",ans.size());
	for(int u : ans)printf("%d ",u);puts("");
		
	return 0;
}

