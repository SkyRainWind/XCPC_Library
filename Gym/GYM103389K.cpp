// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

signed main(){
	int n,t=0;
	scanf("%d",&n);
	printf("%.10f\n",1.0 / n);
	return 0;
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch != '|')ch = getchar();
		ch = getchar();
		while(ch != '|'){t += (ch == '-');ch = getchar();}
	}
	printf("%d\n",t);

	return 0;
}

