// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int INF = 0x3f3f3f3f, maxn = 2e5+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n,qu;
char s[maxn];
struct mat{
	ll a[2][2];
	mat(){memset(a,0x3f,sizeof a);}
}a[maxn];
struct segm{
	mat sum;
}se[maxn << 2];

mat operator * (mat a,mat b){
	mat c;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				c.a[i][j] = min(c.a[i][j], a.a[i][k] + b.a[k][j]);
	return c;
}

void build(int l,int r,int num){
	if(l == r){
		se[num].sum = a[l];
		return ;
	}
	int mid = l+r>>1;
	build(l,mid,num<<1);build(mid+1,r,num<<1|1);
	se[num].sum = se[num << 1].sum * se[num << 1|1].sum;
}

void update(int k,int l,int r,int num){
	if(l == r){
		se[num].sum = a[k];
		return ;
	}
	int mid=l+r>>1;
	if(k <= mid)update(k,l,mid,num<<1);
	else update(k,mid+1,r,num<<1|1);
	se[num].sum = se[num << 1].sum * se[num << 1|1].sum;
}

signed main(){
	scanf("%d",&n);
	vector<int>b(n+1);
	-- n;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		a[i].a[0][0] = a[i].a[1][0] = b[i];
		a[i].a[0][1] = 0, a[i].a[1][1] = inf;
	}
	build(1,n,1);
	
	scanf("%d",&qu);
	while(qu --){
		int k,x;scanf("%d%d",&k,&x);
		a[k].a[0][0] = a[k].a[1][0] = x;
		update(k,1,n,1);
		printf("%lld\n",se[1].sum.a[1][0]*2);
	}

	return 0;
}

