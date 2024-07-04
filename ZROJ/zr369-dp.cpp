// by Balloons
// 为什么别人比你进步的快？ 因为别人比你努力的多！
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1 << 30;

const int maxn=1e5+5;
int n;
int s[maxn];
int ch(int aa,int bb,int cc,int dd){
	if(aa==bb)return 0;
	if(aa==cc)return 0;
	if(aa==dd)return 0;
	if(bb==cc)return 0;
	if(bb==dd)return 0;
	if(cc==dd)return 0;
	return 1;
}

signed main(){
	int ans=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&s[i]);
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){if(a!=b)
			for(int c=1;c<=n;c++){if(a!=c&&b!=c)
				for(int d=1;d<=n;d++){if(a!=d&&b!=d&&c!=d)
					if(a<b&&c<d&&ch(a,b,c,d)&&s[a]<s[b]&&s[c]>s[d])++ans,printf("%d %d %d %d\n",a,b,c,d);
				}
			}
		}
	}
	printf("%lld\n",ans);

	return 0;
}

