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
const int N = 1005, INF = 0x3f3f3f3f;
int n, T[N], B[N], f[N][1 << 8][20];
void chkmin(int &a, int b) {a = min(a, b);}
void work() {
    int i, j, k, h, lir;
    n = read(); for (i = 1; i <= n; i++)
        T[i] = read(), B[i] = read();
    memset(f, INF, sizeof(f)); f[1][0][7] = 0;
    for (i = 1; i <= n; i++) for (j = 0; j < (1 << 8); j++)
    for (k = -8; k <= 7; k++) if (f[i][j][k + 8] != INF) {
        if (j & 1) chkmin(f[i + 1][j >> 1][k + 7], f[i][j][k + 8]);
        else {
            lir = INF;
            for (h = 0; h <= 7; h++) if (!((j >> h) & 1)) {
                if (i + h > lir) break;
                chkmin(lir, i + h + B[i + h]);
                chkmin(f[i][j | (1 << h)][h + 8], f[i][j][k + 8] +
                (i + k ? (T[i + k] ^ T[i + h]) : 0));
                printf("%d %d %d %d %d %d\n",i,j|(1<<h),h+8,f[i][j|(1<<h)][h+8],j,k+8);
            }
        }
    }
    int res = INF; for (k = 0; k <= 8; k++)
        res = min(res, f[n + 1][0][k]);
    printf("%d\n", res);
}
int main() {
    int T = read();
    while (T--) work();
    return 0;
}
