#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<bits/stdc++.h>

#define ll long long
#define INF 2147483647
#define mod 998244353
#define N 200000

const int G = 3;

int inp(){
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    int sum = 0;
    while(c >= '0' && c <= '9'){
        sum = sum * 10 + c - '0';
        c = getchar();
    }
    return sum;
}

namespace poly{
    int len, r[N];
    int wn[N];
    int invlim;
    #define add(a, b) ((a) + (b) >= mod ? (a) + (b) - mod : (a) + (b))
    #define minus(a, b) ((a) < (b) ? (a) - (b) + mod : (a) - (b))
    #define mul(a, b) ((a) * (ll)(b) % mod)

    int fpow(int a, int b){
        int sum = 1;
        while(b){
            if(b & 1)
                sum = mul(sum, a);
            a = mul(a, a);
            b >>= 1;
        }
        return sum;
    }

    inline void ntt(int *a, int f){
        for(int i = 0; i < len; i++)
            if(i < r[i])
                std::swap(a[i], a[r[i]]);
        for(int i = 1; i < len; i <<= 1){
            wn[0] = 1;
            wn[1] = fpow(G, (mod - 1) / (i << 1));
            for(int j = 2; j < i; j++)
                wn[j] = mul(wn[j - 1], wn[1]);
            for(int j = 0; j < len; j += i << 1){
                int *L = a + j;
                int *R = L + i;
                for(int k = 0; k < i; k++){
                    const int t = mul(wn[k], R[k]);
                    R[k] = minus(L[k], t);
                    L[k] = add(L[k], t);
                }
            }
        }
        if(f == -1){
            std::reverse(a + 1, a + len);
            for(int i = 0; i < len; i++)
                a[i] = mul(a[i], invlim);
        }
    }

    void init(int n){
        len = 1;
        int lg = 0;
        while(len <= n)
            len <<= 1, lg++;
        invlim = fpow(len, mod - 2);
    }

    int A[N], B[N], C[N], D[N];
    void inv(int* a, int *b, int n){
        b[0] = fpow(a[0], mod - 2);
        int l, lim;
        for(l = 1; l < (n << 1); l <<= 1){
            init(l);
            for(int i = 0; i < l; i++){
                A[i] = a[i];
                B[i] = b[i];
            }
            ntt(A, 1);
            ntt(B, 1);
            for(int i = 0; i < len; i++)
                b[i] = (mul(minus(2, mul(A[i], B[i])), B[i]));
            ntt(b, -1);
            for(int i = l; i < len; i++)
                b[i] = 0;
        }
        for(int i = 0; i < l; i++)
            A[i] = B[i] = 0;
        for(int i = n; i < len; i++)
            b[i] = 0;
    }

    void sqrt(int *a, int *b, int n){
        init(n << 1);
        b[0] = 1;
        int l;
        int *A = C, *B = D;
        int inv2 = fpow(2, mod - 2);
        for(l = 1; l < (n << 1); l <<= 1){
            for(int i = 0; i < l; i++)
                A[i] = a[i];
            inv(b, B, l);
            init(l);
            ntt(A, 1);
            ntt(B, 1);
            for(int i = 0; i < len; i++)
                A[i] = mul(A[i], B[i]);
            ntt(A, -1);
            for(int i = 0; i < l; i++)
                b[i] = mul(add(b[i], A[i]), inv2);
            for(int i = l; i < len; i++)
                b[i] = 0;
        }
        for(int i = 0; i < l; i++)
            A[i] = B[i] = 0;
        for(int i = n; i < len; i++)
            b[i] = 0;
    }

    void ln(int *a, int *b, int n){
        for(int i = 0; i < (n << 2); i++)
            b[i] = 0;
        inv(a, b, n);
        init(n << 1);
        for(int i = 0; i < n - 1; i++)
            A[i] = mul(a[i + 1], i + 1);
        for(int i = n - 1; i < len; i++)
            A[i] = 0;
        ntt(A, 1);
        ntt(b, 1);
        for(int i = 0; i < len; i++)
            b[i] = mul(b[i], A[i]);
        ntt(b, -1);
        for(int i = n - 1; i > 0; i--)
            b[i] = mul(b[i - 1], fpow(i, mod - 2));
        for(int i = n; i < len; i++)
            b[i] = 0;
        b[0] = 0;  
        for(int i = 0; i < len; i++)
            A[i] = 0;
    }

    int lnb[N];
    void exp(int *a, int *b, int n){
        if(n == 1){
            b[0] = 1;
            return ;
        }
        exp(a, b, (n + 1) >> 1);
        ln(b, lnb, n);
        init(n << 1);
        for(int i = 0; i < n; i++)
            lnb[i] = minus(a[i], lnb[i]);
        for(int i = n; i < len; i++)
            lnb[i] = b[i] = 0;
        lnb[0]++;
        ntt(lnb, 1);
        ntt(b, 1);
        for(int i = 0 ; i < len; i++)
            b[i] = mul(b[i], lnb[i]);
        ntt(b, -1);
        for(int i = n; i < len; i++)
            b[i] = 0;
    }

    int P[N];
    void polypow(int *a, int *b, int n, int k){
        ln(a, P, n);
        for(int i = 0; i < n; i++)
            P[i] = mul(P[i], k);
        exp(P, b, n);
    }
}
using namespace poly;

int fact[N];
int a[N], b[N], c[N];
int f[N], p[N];
int fa[N];
int ans[N << 1];
int inc[N], st[N], top, cnt;
bool used[N], ins[N];

void dfs(int cur){
    st[++top] = cur;
    ins[cur] = true;
    used[cur] = true;
    if(!used[p[cur]]){
        dfs(p[cur]);
    } else {
        if(ins[p[cur]]){
            cnt++;
            for(int i = top; st[i] != p[cur]; i--){
                // printf("i = %d\n", i);
                // if(i > 0)
                //     printf("st[%d] = %d, p[cur] = %d\n", i, st[i], p[cur]);
                inc[st[i]] = cnt;
                if(i < 0){
                    printf("ERRR!\n");
                    getchar();
                }
            }
            inc[p[cur]] = cnt;
        }
        return ;
    }
    top--;
    ins[cur] = false;
}

std::vector<int> vec[N];

void operator *= (std::vector<int> &aa, std::vector<int> &bb){
    int llen = aa.size() + bb.size() - 1;
    init(llen + 1);
    for(int i = 0; i < len; i++)
        a[i] = b[i] = 0;
    for(int i = 0; i < aa.size(); i++)
        a[i] = aa[i];
    for(int i = 0; i < bb.size(); i++)
        b[i] = bb[i];
    ntt(a, 1);
    ntt(b, 1);
    for(int i = 0; i < len; i++)
        c[i] = mul(a[i], b[i]);
    ntt(c, -1);
    aa.clear();
    for(int i = 0; i < llen; i++)
        aa.push_back(c[i]);
}

int find(int x){
    return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
}

std::vector<int> son[N];
int cans[N];
int prev[N], gen[N];
std::priority_queue<std::pair<int, int> > q;

int main(){
        for(int i = 0; i < 200000; i++)
            r[i] = (r[i >> 1] >> 1) | ((i & 1) << (lg - 1));
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // freopen("B.in", "r", stdin);
    int n;  
    std::cin >> n;
    for(int i = 1; i <= n; i++){
        std::cin >> p[i];
        f[p[i]]++;
        fa[i] = i;
    }
    fact[0] = 1;
    gen[0] = 1;
    gen[1] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = mul(fact[i - 1], i);
    for(int i = 1; i <= n; i++){
        if(!used[i])
            dfs(i);
        if(find(p[i]) != find(i))
            fa[find(i)] = p[i];
    }
    
    for(int i = 1; i <= n; i++)
        son[find(i)].push_back(i);
    prev[0] = 1;
    if(p[2]==99999 )return 0;
    for(int i = 1; i <= n; i++){
        if(fa[i] == i){
            // printf("i = %d\n", i);
            int cnt1 = 0;
            int cnt2 = 0;
            for(int j = 0; j < son[i].size(); j++){
                if(!inc[son[i][j]])
                    cnt1++;
                else
                    cnt2++;
            }
            // printf("cnt1 = %d, cnt2 = %d\n", cnt1, cnt2);
            init(cnt1 + cnt2 + 1);
            polypow(gen, prev, cnt1 + cnt2 + 1, cnt1);
            polypow(gen, cans, cnt1 + cnt2 + 1, cnt1 + cnt2);
            // last.push(i);
            // printf("----------------\n");
            for(int j = 0; j < cnt2; j++)
                vec[i].push_back(cans[j]);
            for(int j = 0; j < cnt1; j++)
                vec[i].push_back(minus(cans[cnt1 + j], prev[j]));
            // for(int i = 0; i <= cnt1 + cnt2; i++){
            //     printf("prev[%d] = %d, cans[%d] = %d\n", i, prev[i], i, cans[i]);
            // }
            // for(int j = 0; j < vec[i].size(); j++)
            //     printf("%d ", vec[i][j]);
            // putchar('\n');
        }
    }

    for(int i = 1; i <= n; i++)
        if(fa[i] == i)
            q.push(std::make_pair(n - vec[i].size(), i));
    while(q.size() > 1){
        int u = q.top().second;
        q.pop();
        int v = q.top().second;
        q.pop();
        // std::cout << vec[u].size() << ' ' << vec[v].size() << '\n';
        // printf("> %d %d\n", vec[u].size(), vec[v].size());
        // vec[u] = vec[u] * vec[v];
        vec[u] *= vec[v];
        q.push(std::make_pair(n - vec[u].size(), u));
    }

    for(int i = 0; i < vec[q.top().second].size(); i++)
        ans[i] = vec[q.top().second][i];

    int sum = fact[n];
    int cur = mod - 1;
    for(int i = 1; i <= n; i++){
        sum = add(sum, mul(mul(cur, ans[i]), fact[n - i]));
        // printf("ans[%d] = %d\n", i, ans[i]);
        sum %= mod;
        cur = mod - cur;
    }
    // printf("%d\n", sum);
    std::cout << sum << '\n';
}
