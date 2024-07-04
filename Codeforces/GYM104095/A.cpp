// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int n,m;
struct node{
	int c,t,id;
}a[maxn];
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].c,&a[i].t);a[i].id=i;
	}
	sort(a+1,a+n+1,[&](node a,node b){
		if(a.c == b.c){
			if(a.t == b.t)return a.id<b.id;
			return a.t>b.t;
		}
		return a.c<b.c;
	});
	int lst=0;
	for(int i=1;i<=n;i++)
		if(a[i].c != lst){
			printf("%d ",a[i].id);
			lst=a[i].c;
		}

	return 0;
}

