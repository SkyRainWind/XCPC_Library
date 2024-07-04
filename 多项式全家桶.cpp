//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3000007;
const int p = 998244353, gg = 3, ig = 332738118, img = 86583718;
const int mod = 998244353;

template <typename T>void read(T &x)
{
    x = 0;
    register int f = 1;
    register char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-')f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}
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
    #define mul(x, y) (1ll * x * y >= mod ? 1ll * x * y % mod : 1ll * x * y)
    #define minus(x, y) (1ll * x - y < 0 ? 1ll * x - y + mod : 1ll * x - y)
    #define plus(x, y) (1ll * x + y >= mod ? 1ll * x + y - mod : 1ll * x + y)
    #define ck(x) (x >= mod ? x - mod : x)//ȡģ����̫����

    typedef vector<int> poly;
    const int G = 3;//���ݾ����ģ��������ԭ���ɲ�һ����һ��������
    //һ��ģ����ԭ��Ϊ 2 3 5 7 10 6
    const int inv_G = pw(G, mod - 2);
    int RR[N], deer[2][19][N], inv[N];

    void init(const int t) {//Ԥ�������NTT����Ҫ��w��wn��������һ��log��ʱ��
        for(int p = 1; p <= t; ++ p) {
            int buf1 = pw(G, (mod - 1) / (1 << p));
            int buf0 = pw(inv_G, (mod - 1) / (1 << p));
            deer[0][p][0] = deer[1][p][0] = 1;
            for(int i = 1; i < (1 << p); ++ i) {
                deer[0][p][i] = 1ll * deer[0][p][i - 1] * buf0 % mod;//��
                deer[1][p][i] = 1ll * deer[1][p][i - 1] * buf1 % mod;
            }
        }
        inv[1] = 1;
        for(int i = 2; i <= (1 << t); ++ i)
            inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
    }

    int NTT_init(int n) {//�������۱任Ԥ����
        int limit = 1, L = 0;
        while(limit <= n) limit <<= 1, L ++ ;
        for(int i = 0; i < limit; ++ i)
            RR[i] = (RR[i >> 1] >> 1) | ((i & 1) << (L - 1));
        return limit;
    }

    void NTT(poly &A, int type, int limit) {//�������۱任
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

    poly poly_mul(poly A, poly B) {//����ʽ�˷�
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

    poly poly_inv(poly &f, int deg) {//����ʽ����
        if(deg == 1)
            return poly(1, pw(f[0], mod - 2));

        poly A(f.begin(), f.begin() + deg);
        poly B = poly_inv(f, (deg + 1) >> 1);
        int limit = NTT_init(deg << 1);
        NTT(A, 1, limit), NTT(B, 1, limit);
        for(int i = 0; i < limit; ++ i)
            A[i] = B[i] * (2 - 1ll * A[i] * B[i] % mod + mod) % mod;
        NTT(A, 0, limit);
        A.resize(deg);
        return A;
    }

    poly poly_dev(poly f) {//����ʽ��
        int n = f.size();
        for(int i = 1; i < n; ++ i) f[i - 1] = 1ll * f[i] * i % mod;
        return f.resize(n - 1), f;//f[0] = 0������ֱ������,��1��ʼ
    }

    poly poly_idev(poly f) {//����ʽ�����
        int n = f.size();
        for(int i = n - 1; i ; -- i) f[i] = 1ll * f[i - 1] * inv[i] % mod;
        return f[0] = 0, f;
    }

    poly poly_ln(poly f, int deg) {//����ʽ�����
        poly A = poly_idev(poly_mul(poly_dev(f), poly_inv(f, deg)));
        return A.resize(deg), A;
    }

    poly poly_exp(poly &f, int deg) {//����ʽ��ָ��
        if(deg == 1)
            return poly(1, 1);

        poly B = poly_exp(f, (deg + 1) >> 1);
        B.resize(deg);
        poly lnB = poly_ln(B, deg);
        for(int i = 0; i < deg; ++ i)
            lnB[i] = ck(f[i] - lnB[i] + mod);

        int limit = NTT_init(deg << 1);//n -> n^2
        NTT(B, 1, limit), NTT(lnB, 1, limit);
        for(int i = 0; i < limit; ++ i)
            B[i] = 1ll * B[i] * (1 + lnB[i]) % mod;
        NTT(B, 0, limit);
        B.resize(deg);
        return B;
    }

    poly poly_sqrt(poly &f, int deg) {//����ʽ����
        if(deg == 1) return poly(1, 1);
        poly A(f.begin(), f.begin() + deg);
        poly B = poly_sqrt(f, (deg + 1) >> 1);
        poly IB = poly_inv(B, deg);
        int limit = NTT_init(deg << 1);
        NTT(A, 1, limit), NTT(IB, 1, limit);
        for(int i = 0; i < limit; ++ i)
            A[i] = 1ll * A[i] * IB[i] % mod;
        NTT(A, 0, limit);
        for(int i =0; i < deg; ++ i)
            A[i] = 1ll * (A[i] + B[i]) * inv[2] % mod;
        A.resize(deg);
        return A;
    }

    poly poly_pow(poly f, int k) {//����ʽ������
        f = poly_ln(f, f.size());
        for(auto &x : f) x = 1ll * x * k % mod;
        return poly_exp(f, f.size());
    }

    poly poly_cos(poly f, int deg) {//����ʽ���Ǻ�����cos��
        poly A(f.begin(), f.begin() + deg);
        poly B(deg), C(deg);
        for(int i = 0; i < deg; ++ i)
            A[i] = 1ll * A[i] * img % mod;

        B = poly_exp(A, deg);
        C = poly_inv(B, deg);
        int inv2 = pw(2, mod - 2);
        for(int i = 0; i < deg; ++ i)
            A[i] = 1ll * (1ll * B[i] + C[i]) % mod * inv2 % mod;
        return A;
    }

    poly poly_sin(poly f, int deg) {//����ʽ���Ǻ�����sin��
        poly A(f.begin(), f.begin() + deg);
        poly B(deg), C(deg);
        for(int i = 0; i < deg; ++ i)
            A[i] = 1ll * A[i] * img % mod;

        B = poly_exp(A, deg);
        C = poly_inv(B, deg);
        int inv2i = pw(img << 1, mod - 2);
        for(int i = 0; i < deg; ++ i)
            A[i] = 1ll * (1ll * B[i] - C[i] + mod) % mod * inv2i % mod;
        return A;
    }

    poly poly_arcsin(poly f, int deg) {
        poly A(f.size()), B(f.size()), C(f.size());
        A = poly_dev(f);
        B = poly_mul(f, f);
        for(int i = 0; i < deg; ++ i)
            B[i] = minus(mod, B[i]);
        B[0] = plus(B[0], 1);
        C = poly_sqrt(B, deg);
        C = poly_inv(C, deg);
        C = poly_mul(A, C);
        C = poly_idev(C);
        return C;
    }

    poly poly_arctan(poly f, int deg) {
        poly A(f.size()), B(f.size()), C(f.size());
        A = poly_dev(f);
        B = poly_mul(f, f);
        B[0] = plus(B[0], 1);
        C = poly_inv(B, deg);
        C = poly_mul(A, C);
        C = poly_idev(C);
        return C;
    }
}

using Poly::poly;
using Poly::poly_arcsin;
using Poly::poly_arctan;

int n, m, x, k, type;
poly f, g;
char s[N];

int main()
{
    Poly::init(18);//2^21 = 2,097,152,������Ŀ���ݶ���ʽ�����Ĵ�С���ɵ�����ע���С��Ҫ��deer����ͬ��(21+1=22)

    read(n), read(type);

    for(int i = 0; i < n; ++ i)
        read(x), f.push_back(x);

    if(type == 0) g = poly_arcsin(f, n);
    else g = poly_arctan(f, n);

    for(int i = 0; i < n; ++ i)
        printf("%d ", g[i]);
    return 0;
}

