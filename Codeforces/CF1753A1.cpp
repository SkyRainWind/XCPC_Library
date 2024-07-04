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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

int n;
int a[maxn];

void solve(){
	scanf("%d",&n);
	int s= 0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), s+=a[i];
	if(s & 1){
		puts("-1");
		return ;
	}
	vector<pii>ans;
	for(int i=2;i<=n;){
		if(s > 0){
			int j;
			for(j = i;j<=n;j++)
				if(a[j] == -1)break;
			-- j;
			if(j == i-1){++ i;continue;}
			ans.push_back(mpr(i,j));
			i = j+1;
		}else{
			int j;
			for(j = i;j<=n;j++)
				if(a[j] == 1)break;
			-- j;
			if(j == i-1){++ i;continue;}
			ans.push_back(mpr(i,j));
			i = j+1;
		}
	}
	vector<pii>ans0;
	int lst = 1;
	for(pii u : ans){
		ans0.push_back(mpr(lst, u.first));
		lst = u.second + 1;
	}
	if(lst <= n)ans0.push_back(mpr(lst, n));
	printf("%d\n",ans0.size() + ans.size());
	for(int i=0;i<ans0.size();i++){
		printf("%d %d\n",ans0[i].first,ans0[i].second);
		if(i < ans.size())
			printf("%d %d\n",ans[i].first, ans[i].second);
	}
}

signed main(){
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}


