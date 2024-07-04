#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
inline int read() {
    int res = 0; bool bo = 0; char c;
    while (((c = getchar()) < '0' || c > '9') && c != '-');
    if (c == '-') bo = 1; else res = c - 48;
    while ((c = getchar()) >= '0' && c <= '9')
        res = (res << 3) + (res << 1) + (c - 48);
    return bo ? ~res + 1 : res;
}
const int N = 55, M = 3005, PYZ = 1e4;
struct cyx {
    int m, n, v[N][N];
    cyx() {}
    cyx(int _m, int _n) :
        m(_m), n(_n) {memset(v, 0, sizeof(v));}
    friend inline cyx operator * (cyx a, cyx b) {
        cyx res = cyx(a.m, b.n); int i, j, k;
        for (i = 1; i <= res.m; i++) for (j = 1; j <= res.n; j++)
        for (k = 1; k <= a.n; k++)
            (res.v[i][j] += a.v[i][k] * b.v[k][j]) %= PYZ;
        return res;
    }
    friend inline cyx operator ^ (cyx a, int b) {
        int i, d = b; cyx c = a, res = cyx(a.m, a.n);
        for (i = 1; i <= res.m; i++) res.v[i][i] = 1;
        while (d) {
            if (d & 1) res = res * c;
            c = c * c;
            d >>= 1;
        }
        return res;
    }
} P[15], Q, F;
int n, m, S, T, K, nf, ecnt, nxt[M], adj[N], go[M];
bool vis[15][N];
void add_edge(int u, int v) {
    nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}
int main() {
    int i, j, k, x, y; n = read(); m = read(); S = read() + 1;
    T = read() + 1; K = read(); for (i = 1; i <= m; i++) {
        x = read() + 1; y = read() + 1;
        add_edge(x, y); add_edge(y, x);
    }
    nf = read(); for (i = 1; i <= nf; i++) {
        x = read(); for (j = 0; j < x; j++) {
            y = read() + 1;
            for (k = j; k < 12; k += x)
                vis[k][y] = 1;
        }
    }
    Q = cyx(n, n); for (i = 1; i <= n; i++) Q.v[i][i] = 1;
    for (j = 0; j < 12; j++) {
        P[j] = cyx(n, n);
        for (i = 1; i <= n; i++)
            for (int e = adj[i]; e; e = nxt[e])
                if (!vis[j][go[e]]) P[j].v[i][go[e]] = 1;
        if (j) Q = Q * P[j];
    }
    for(int i=1;i<=n;i++,puts(""))
    	for(int j=1;j<=n;j++)printf("%d ",P[1].v[i][j]);
    Q = Q * P[0]; F = Q ^ (K / 12);
    for (j = 1; j <= K % 12; j++) F = F * P[j];
    printf("%d\n", F.v[S][T]);
    return 0;
}
