// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int k,n;
map<int,ll>fib;
int s;
signed main(){
	scanf("%d%d",&s,&k);
	fib[k] = 1;
	ll sum = 1,t;
	for(int i=k+1;i<=k+100;i++){
		fib[i] = sum;
		sum = sum + fib[i] - (i-k < k ? 0 : fib[i-k]);
//		printf("%d %d\n",i,sum);
		if(sum > s){t=i;break;}
	}
//	for(auto it : fib)printf("%d %d\n",it.first,it.second);
	vector<int>vc;
	for(int i=t;i>=k;i--)
		if(s >= fib[i])s -= fib[i], vc.push_back(fib[i]);
	vc.push_back(0);
	printf("%d\n",vc.size());
	for(auto it : vc)printf("%d ",it);

	return 0;
}

