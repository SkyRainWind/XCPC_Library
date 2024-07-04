// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5, maxm=1e6+5, mod=1e9+33;

int n,q,a[maxn],blo;
struct que{int l,r,id;}qu[maxn];
int notpm[maxm], pm[maxm], pcnt=0, least[maxm];
int pref[maxn],cubdiv[maxn];

void xxs(){
	notpm[1] = 1;
	for(int i=2;i<=maxm-5;i++){
		if(!notpm[i]){
			pm[++pcnt]=i;
			least[i] = pcnt;
		}
		for(int j=1;j<=pcnt && i*pm[j]<=maxm-5;j++){
			notpm[i*pm[j]] = 1;
			least[i*pm[j]] = j;
			if(i%pm[j] == 0)break;
		}
	}
}

int pw(int x,int y){
	if(y==0)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

signed main(){
	xxs();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	pref[0] = 1;
	for(int i=1;i<=n;i++){
		int b = a[i];
		int tmp = 1;
		pref[i] = pref[i-1];
		while(b != 1){
			int le = least[b], cnt = 0;
			while(least[b] == le){
				b /= pm[le];
				++ cnt;
			}
			int inv = pw(pm[le], mod-2);
			for(int j=1;j<=cubdiv[le];j++)pref[i]=1ll*pref[i]*inv%mod;
			(cubdiv[le] += cnt) %= 3;
			for(int j=1;j<=cubdiv[le];j++)pref[i]=1ll*pref[i]*pm[le]%mod;
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;scanf("%d%d",&x,&y);
//		printf("%d %d\n",pref[x-1],pref[y]);
		if(pref[x-1] == pref[y])puts("Yes");
		else puts("No");
	}
	
	return 0;
}

