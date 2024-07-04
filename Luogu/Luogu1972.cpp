// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6+5;

int n,a[maxn],rt[maxn],lst[maxn];
struct segm{
	int ls,rs,val;
}se[maxn << 5];
int id=0;

void update(int pre,int &num,int x,int to,int l,int r){
	num = ++id;
	se[num]=se[pre];
	if(l == r)return se[num].val += to, void();
	int mid = l+r>>1;
	if(x <= mid)update(se[pre].ls,se[num].ls,x,to,l,mid);
	else update(se[pre].rs,se[num].rs,x,to,mid+1,r);
	se[num].val = se[se[num].ls].val + se[se[num].rs].val;
}

int query(int num,int to,int l,int r){
	if(l >= to)return se[num].val;
	int mid = l+r>>1;
	int s1=0;
	if(to<=mid)s1 += query(se[num].ls,to,l,mid);
	s1 += query(se[num].rs,to,mid+1,r);
	return s1;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		update(rt[i-1],rt[i],i,1,1,1e6);
		if(lst[a[i]]){
			update(rt[i],rt[i],lst[a[i]],-1,1,1e6);
		}
		lst[a[i]] = i;
	}
	
	int qu;scanf("%d",&qu);
	while(qu --){
		int l,r;scanf("%d%d",&l,&r);
		printf("%d\n",query(rt[r],l,1,1e6));
	}

	return 0;
}

