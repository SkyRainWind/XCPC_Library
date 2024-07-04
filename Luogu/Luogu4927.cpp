// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;
#define int __int128

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5, mod = 998244353;

int n,m,a[maxn];
struct segm{
	int l;	// l = \sum len^2
	int len;	// 当前区间长度 
	int sum,val,lazy;	// sum 区间和 , val \sum sum[l..r]*len 对子树的点求和 
	int res;	// 当前点子树中的点对应的区间和的平方的和（期望的分子） 
}se[maxn << 2];
// S^2 -> (S+len*v)^2-S^2 = 2*S*len*v + len^2*v^2，其中 S 为区间和 
// 维护 \sum len^2 (常量) \sum S*len 

int pw(int x,int y){
	if(!y)return 1;if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int read(){
    char ch=getchar();int h=0,t=1;
    while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
    if(ch=='-') t=-1,ch=getchar();
    while(ch>='0'&&ch<='9') h=h*10+ch-'0',ch=getchar();
    return h*t;
}
void print(int x){if(x>9)print(x/10);putchar(x%10+'0');}
int sq(int x){return 1ll*x*x;}
void pushup(int num,int l,int r){
	se[num].l = se[num<<1].l + se[num<<1|1].l + sq(r-l+1);
	se[num].sum = se[num << 1].sum + se[num << 1|1].sum;
	se[num].val = se[num << 1].val + se[num << 1|1].val + (r-l+1) * se[num].sum;
	se[num].res = se[num << 1].res + se[num << 1|1].res + sq(se[num].sum);
}

void build(int x,int y,int num){
	se[num].len = y-x+1;
	if(x == y){
		se[num].l = 1;
		se[num].sum = se[num].val = a[x];
		se[num].res = sq(a[x]);
		return ;
	}
	int mid = x+y>>1;
	build(x,mid,num <<1);build(mid+1,y,num<<1|1);
	pushup(num,x,y);
}

void add(int num,int v){	// 对区间能进行整体操作 
	se[num].lazy += v;
	se[num].res += 2*se[num].val*v + se[num].l*v*v;
	se[num].sum += se[num].len * v;
	se[num].val += se[num].l * v;
}

void pushdown(int num,int l,int r){
	if(!se[num].lazy)return ;
	add(num<<1,se[num].lazy);
	add(num<<1|1,se[num].lazy);
	
	se[num].lazy = 0;
}

void upd(int x,int y,int v,int l,int r,int num){
	if(x<=l && r<=y){
		add(num, v);
		return ;
	}
	pushdown(num,l,r);
	int mid=l+r>>1;
	if(y<=mid)upd(x,y,v,l,mid,num<<1);
	else if(x>mid)upd(x,y,v,mid+1,r,num<<1|1);
	else upd(x,y,v,l,mid,num<<1), upd(x,y,v,mid+1,r,num<<1|1);
	pushup(num,l,r);
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,n,1);
	while(m --){
		int op=read(),l,r,v;
		if(op == 2){
			int fz = se[1].res / __gcd(se[1].res,se[1].sum);
			int fm = se[1].sum / __gcd(se[1].res,se[1].sum);
			print(fz%mod*pw(fm,mod-2)%mod);puts("");
		}else{
			l=read(),r=read(),v=read();
			upd(l,r,v,1,n,1);
		}
	}

	return 0;
}

