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

int n,a,b;
int v[maxn],ans[1005][1005];

signed main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	
	for(int cd=0;cd<=a+b;cd++){
		int l=max(0,cd-b),r=min(a,cd);
		int sum=0;
		for(int x : v){
			sum += x;
			l = max({l,sum,cd+sum-b});
			r = min({r,a+sum,sum+cd});
		}
		if(l>r)l=r=max(0,cd-b);
		int res=l;
		for(int x : v){
			if(x>0)res-=min({res,x,b-(cd-res)});
			else res+=min({cd-res,-x,a-res});
		}
		for(int c=0;c<=cd;c++)
			if(c<=a&&cd-c<=b)
				ans[c][cd-c] = (c<l ? res : (c>r ? res+r-l : res+c-l));
	}
	for(int i=0;i<=a;i++,puts(""))
		for(int j=0;j<=b;j++)printf("%d ",ans[i][j]);

	return 0;
}

