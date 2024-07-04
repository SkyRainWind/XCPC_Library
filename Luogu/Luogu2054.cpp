// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define int LL

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

long long gcd(long long a,long long b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

//欧拉函数:复杂度O(n^(0.5)),返回[1,n-1]中所有和n互素的数的个数和
long long phi(long long x)
{
    long long sum=x;
    for(long long i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            sum=sum-sum/i;
            while(x%i==0) x/=i;
        }
    }
    if(x!=1) sum=sum-sum/x;
    return sum;
}

long long Mod_Mul(long long a,long long b,long long mod)
{
    long long sum=0;
    while(b)
    {
        if(b&1) sum=(sum+a)%mod;
        b>>=1;
        a = (a+a)%mod;
    }
    return sum;
}


//a^b%mod 快速幂
long long Quk_Mul(long long a,long long b,long long mod)
{
    long long qsum=1;
    while(b)
    {
        if(b&1) qsum=Mod_Mul(qsum,a,mod);
        b>>=1;
        a=Mod_Mul(a, a, mod);
    }
    return qsum;
}

long long GetJie(long long A,long long M)
{
    long long d = gcd(A,M);
    if(d != 1) return -1;
    long long m=phi(M);
    //然后对m进行拆分
    long long prm[100],prmcnt[100];
    int pcnt=0;
    memset(prmcnt,0,sizeof(prmcnt));
    long long tm = m;
    for(long long i=2;i*i<=tm;i++)
    {
        if(tm%i==0)
        {
            prm[pcnt]=i;
            while(tm%i==0)
            {
                prmcnt[pcnt]++;
                tm/=i;
            }
            pcnt++;
        }
    }
    if(tm!=1)
    {
        prm[pcnt]=tm;
        prmcnt[pcnt]=1;
        pcnt++;
    }
    for(int i=0;i<pcnt;i++)
    {
        for(int j=0;j<prmcnt[i];j++)
        {
            if( Quk_Mul(A, m/prm[i], M)==1 )
            {
                m/=prm[i];
            }
        }
    }
    return m;
}

LL pw(LL x,LL mod){
	if(!x)return 1;if(x==1)return 2;
	LL mid=  pw(x>>1,mod);
	int fuck = Mod_Mul(mid,mid,mod);
	if(x&1)return Mod_Mul(fuck,2,mod);
	return fuck;
}

signed main(){
	LL n,m,L;scanf("%lld%lld%lld",&n,&m,&L);
	if(n == 0){
		return puts("0"), 0;
	}
	LL md = GetJie(2,n+1);
	m %= md;
	if(m == 0)return printf("%lld\n",L),0;
	m = md-m;
	printf("%lld\n",Mod_Mul(L,pw(m%(n+1),n+1),n+1));

	return 0;
}


