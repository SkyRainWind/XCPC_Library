// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f ,mod =1004535809;

template <typename T>void read(T &x)
{
    x = 0;
    register int f = 1;
    register char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-')f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x * 10ll + ch - '0')%mod;ch = getchar();}
    x *= f;
}

int pw(int a, int b)
{
    int res = 1;
    while(b) {
        if(b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

namespace Poly
{
	const int N = 3000007;
    #define mul(x, y) (1ll * x * y >= mod ? 1ll * x * y % mod : 1ll * x * y)
    #define minus(x, y) (1ll * x - y < 0 ? 1ll * x - y + mod : 1ll * x - y)
    #define plus(x, y) (1ll * x + y >= mod ? 1ll * x + y - mod : 1ll * x + y)
    #define ck(x) (x >= mod ? x - mod : x)//取模运算太慢了

    typedef vector<int> poly;
    const int G = 3;//根据具体的模数而定，原根可不一定不一样！！！
    //一般模数的原根为 2 3 5 7 10 6
    const int inv_G = pw(G, mod - 2);
    int RR[N], deer[2][21][N], inv[N];

    void init(const int t) {//预处理出来NTT里需要的w和wn，砍掉了一个log的时间
        for(int p = 1; p <= t; ++ p) {
            int buf1 = pw(G, (mod - 1) / (1 << p));
            int buf0 = pw(inv_G, (mod - 1) / (1 << p));
            deer[0][p][0] = deer[1][p][0] = 1;
            for(int i = 1; i < (1 << p); ++ i) {
                deer[0][p][i] = 1ll * deer[0][p][i - 1] * buf0 % mod;//逆
                deer[1][p][i] = 1ll * deer[1][p][i - 1] * buf1 % mod;
            }
        }
        inv[1] = 1;
        for(int i = 2; i <= (1 << t); ++ i)
            inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
    }

    int NTT_init(int n) {//快速数论变换预处理
        int limit = 1, L = 0;
        while(limit <= n) limit <<= 1, L ++ ;
        for(int i = 0; i < limit; ++ i)
            RR[i] = (RR[i >> 1] >> 1) | ((i & 1) << (L - 1));
        return limit;
    }

    void NTT(poly &A, int type, int limit) {//快速数论变换
        A.resize(limit);
        for(int i = 0; i < limit; ++ i)
            if(i < RR[i])
                swap(A[i], A[RR[i]]);
        for(int mid = 2, j = 1; mid <= limit; mid <<= 1, ++ j) {
            int len = mid >> 1;
            for(int pos = 0; pos < limit; pos += mid) {
                int *wn = deer[type][j];
                for(int i = pos; i < pos + len; ++ i, ++ wn) {
                    int tmp = 1ll * (*wn) * A[i + len] % mod;
                    A[i + len] = ck(A[i] - tmp + mod);
                    A[i] = ck(A[i] + tmp);
                }
            }
        }
        if(type == 0) {
            for(int i = 0; i < limit; ++ i)
                A[i] = 1ll * A[i] * inv[limit] % mod;
        }
    }

    poly poly_mul(poly A, poly B) {//多项式乘法
        int deg = A.size() + B.size() - 1;
        int limit = NTT_init(deg);
        poly C(limit);
        NTT(A, 1, limit);
        NTT(B, 1, limit);
        for(int i = 0; i < limit; ++ i)
            C[i] = 1ll * A[i] * B[i] % mod;
        NTT(C, 0, limit);
        C.resize(deg);
        return C;
    }
}
using namespace Poly;

int n,k,t, a[100005];

signed main(){
	vector<int>f,g;
	scanf("%d",&n);
	read(k);read(t);
	for(int i=1;i<=n;i++)read(a[i]), f.push_back(a[i]);
	init(20);
	if(t == 0){
		int cur = 1;
		for(int i=1;i<=n;i++){
			g.push_back(cur);
			cur = 1ll * cur * (k+i-1 < 0 ? k+i-1 + mod : k+i-1) % mod;
			cur = 1ll * cur * pw(i, mod - 2) % mod;
		}
		f = poly_mul(f, g);
		for(int i=0;i<n;i++)printf("%d ",f[i]);puts("");
	}else{
		int cur = 1, cur0 = 1;
		for(int i=1;i<=n;i++){
			g.push_back(cur0);
			cur = 1ll * cur * (k-i+1 < 0 ? k-i+1 + mod : k-i+1) % mod;
			cur = 1ll * cur * pw(i, mod - 2) % mod;
			if(i & 1)cur0 = (mod - cur) % mod;
			else cur0 = cur;
//			printf("%d\n",cur);
		}
 		f = poly_mul(f, g);
		for(int i=0;i<n;i++)printf("%d ",f[i]);puts("");
	}

	return 0;
}
