// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n;
struct node{int out,id;}de[maxn];
int cmp(node a,node b){return a.out>b.out;}

int check(int in){
	in<<=1;
	int sq = (int)sqrt(1.0 * in+0.5);
	return sq*(sq+1) == in;
}

int res[maxn];
signed main(){
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		printf("? %d ",i);
		for(int j=1;j<=n;j++)printf("%d",i!=j);
		puts("");fflush(stdout);
		scanf("%d",&de[i].out);de[i].id = i;
	}
	sort(de+1,de+n+1,cmp);
	int ans=n;
	int in=0;
	for(int i=1;i<=n;i++){
		in += (n-1) - de[i].out;
		int rst = i;
		if(in == rst*(rst-1)/2){ans = i;break;}
	}
	
	for(int i=1;i<=ans;i++)res[de[i].id] = 1;
	printf("! ");for(int i=1;i<=n;i++)printf("%d",res[i]);fflush(stdout);

	return 0;
}

