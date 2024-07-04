// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,a[maxn],m;
map<ll,int>mp;

namespace fastIO
{
    #define BUF_SIZE 100000
    bool IOerror=0;
    inline char nc()
	{
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline ll read()
	{
        bool sign=0; char ch=nc();ll x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return 0;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
        return x;
    }
    #undef BUF_SIZE
};
using namespace fastIO;
#define qr() read()

void solve(){
	m = 0;
	mp.clear();
	n=qr();
	for(int i=1;i<=n;i++)a[i]=qr(), m = max(m, a[i]), ++ mp[a[i]];
	
	ll ans = 0;
	for(auto it : mp){
		if(it.second >= 3)
			ans += 1ll*it.second*(it.second-1)*(it.second-2);
	}
	int tm = (int)ceil(pow(1.0*m, 2.0/3) + 1);
	for(int i=1;i<=n;i++){
		if(a[i] >= tm){
			for(int j=2;1ll*a[i]*j <= m;j++){
				if(a[i]%j != 0)continue;
				if(mp.count(a[i]*j) && mp.count(a[i]/j)){
					ans += 1ll * mp[a[i]/j] * mp[a[i]*j]; 
				}
			}
		}else{
			if(a[i]>1 && mp.count(1ll*a[i]*a[i]))ans += 1ll*mp[1]*mp[1ll*a[i]*a[i]];
			for(int j=2;j*j <= a[i];j++){
				if(a[i]%j != 0)continue;
				if(mp.count(a[i]/j) && mp.count(1ll*a[i]*j)){
					ans += 1ll * mp[a[i]/j] * mp[1ll*a[i]*j]; 
				}
				if(j*j == a[i])continue;
				if(mp.count(j) && mp.count(1ll*a[i]/j*a[i])){
					ans += 1ll * mp[j] * mp[1ll*a[i]/j*a[i]];
				}
			}
//			printf("-- %d\n",ans);
		}
	}
	printf("%lld\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

