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

int n,qu;
char s[maxn];
struct mat{
	int a[5][5];
	mat(){memset(a,0x3f,sizeof a);}
}a[maxn];
struct segm{
	mat sum;
}se[maxn << 2];

mat operator * (mat a,mat b){
	mat c;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			for(int k=0;k<5;k++)
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

mat query(int x,int y,int l,int r,int num){
	if(x <= l && r <= y){
		return se[num].sum;
	}
	int mid=l+r>>1;
	if(y <= mid)return query(x,y,l,mid, num<<1);
	else if(x>mid)return query(x,y,mid+1,r,num<<1|1);
	return query(x,y,l,mid,num<<1) * query(x,y,mid+1,r,num<<1|1);
}

signed main(){
	scanf("%d%d",&n,&qu);
	scanf("%s",s + 1);
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=4;j++)a[i].a[j][j] = 0;
		if(s[i] == '2')a[i].a[0][0] = 1, a[i].a[0][1] = 0;
		if(s[i] == '0')a[i].a[1][1] = 1, a[i].a[1][2] = 0;
		if(s[i] == '1')a[i].a[2][2] = 1, a[i].a[2][3] = 0;
		if(s[i] == '7')a[i].a[3][3] = 1, a[i].a[3][4] = 0;
		if(s[i] == '6')a[i].a[3][3] = 1, a[i].a[4][4] = 1;
	}
	
	build(1,n,1); 
	while(qu --){
		int l,r;scanf("%d%d",&l,&r);
		mat v = query(l,r,1,n,1);
		printf("%d\n",v.a[0][4] >= INF ? -1 : v.a[0][4]);
	}

	return 0;
}

