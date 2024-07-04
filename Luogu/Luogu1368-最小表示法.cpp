// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 6e5+5;

int n;
int s[maxn];
struct min_repre{
	int solve(){
		for(int i=n+1;i<=2*n;i++)s[i] = s[i-n];
		int i=1, j=2, k=0;
		while(k <= n && i<=n && j<=n){
			if(s[i+k] == s[j+k])++ k;
			else{
				if(s[i+k] > s[j+k])i = i+k+1;
				else j = j+k+1;
				if(i == j)++ i;
				k = 0;
			}
		}
		i = min(i, j);
		return i;
	}
	int mxsuf(){
		int i=1, j=2, k=0;
		while(k <= n && i<=n && j<=n){
			if(i+k>n && j+k>n)break;
			if(s[i+k] == s[j+k])++ k;
			else{
				if(s[i+k] < s[j+k])i = i+k+1;
				else j = j+k+1;
				if(i == j)++ i;
				k = 0;
			}
		}
		i = min(i, j);
		return i;
	}
}repre;

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
//	int id = repre.solve();
//	for(int i=id;i<=n+id-1;i++)printf("%d ",s[i]);puts("");
	int mid = repre.mxsuf();
	printf("%d\n",mid);

	return 0;
}

