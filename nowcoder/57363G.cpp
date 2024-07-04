// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=1e6+5;

unordered_map<int,int>mp;
int n,k;
int d[35],res=0,a[maxn];

void insert(int x){
	for(int i=29;i>=0;i--)if(x&(1<<i)){
		if(!d[i]){d[i]=x,++res;break;}
		x ^= d[i]; 
	}
}

signed main(){
	int te;scanf("%d",&te);
	while(te--){
		mp.clear();res=0;
		memset(d,0,sizeof d);
		
		int f=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1); 
		n=unique(a+1,a+n+1)-(a+1);
		for(int i=1;i<=n;i++){
			int pos = lower_bound(a+1,a+n+1, k^a[i]) - a;
			if(pos <= n && a[pos] == (k^a[i]))f=1;
		}
		
		if(f){puts("Alice");continue;}
		for(int i=1;i<=n;i++)
			insert(a[i]^k);
		if((1<<res)==n)puts("Bob");
		else puts("Draw");
	}

	return 0;
}

