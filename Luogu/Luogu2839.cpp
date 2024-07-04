// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 20000+5;

int n;
pii a[maxn];
struct iv{
	int sum, pre, suf;
};
iv operator + (iv a, iv b){
	iv c;
	c.sum = a.sum + b.sum;
	c.pre = max(a.pre, a.sum + b.pre);
	c.suf = max(b.suf, b.sum + a.suf);
	return c;
}

struct segm{
	iv val;
	int ls, rs;
}se[maxn << 5];
int rt[maxn];

int clk;

void upd(int num){
	se[num].val = se[se[num].ls].val + se[se[num].rs].val;
}

void build(int l,int r,int &num){
	num = ++ clk;
	if(l == r){se[num].val=iv{1,1,1};return ;}
	int mid = l+r>>1;
	build(l,mid,se[num].ls);
	build(mid+1,r,se[num].rs);
	se[num].val = iv{r-l+1,r-l+1,r-l+1};
}

void update(int pre,int &num,int l,int r,int to){
	num = ++clk;
	se[num].ls = se[pre].ls, se[num].rs = se[pre].rs;
	if(l == r){
		se[num].val = iv{-1,0,0};
		return ;
	}
	int mid = l+r>>1;
	if(to <= mid)update(se[pre].ls,se[num].ls,l,mid,to);
	else update(se[pre].rs,se[num].rs,mid+1,r,to);
	se[num].val = se[se[num].ls].val + se[se[num].rs].val;
}

iv query(int l,int r,int ql,int qr,int num){
	if(ql <= l && r <= qr){
		return se[num].val;
	}
	int mid = l+r>>1;
	if(qr <= mid)return query(l,mid,ql,qr,se[num].ls);
	else if(ql > mid)return query(mid+1,r,ql,qr,se[num].rs);
	else return query(l,mid,ql,qr,se[num].ls) + query(mid+1,r,ql,qr,se[num].rs);
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].first), a[i].second = i;
	build(1,n,rt[1]);
	sort(a+1,a+n+1,[&](pii a,pii b){
		return a.first < b.first;
	});
	for(int i=2;i<=n;i++)
		update(rt[i-1],rt[i],1,n,a[i-1].second);

	int qu;scanf("%d",&qu);
	int lst = 0;
	while(qu --){
		vector<int>c(4);
		for(int i=0;i<4;i++)scanf("%d",&c[i]), c[i] = (c[i] + lst)%n + 1;
		sort(c.begin(), c.end());

		int l=1, r=n, ans;
		while(l <= r){
			int mid = l+r>>1;
			iv s1 = query(1,n,c[0],c[1]-1,rt[mid]);
			iv s2 = query(1,n,c[1],c[2],rt[mid]);
			iv s3 = query(1,n,c[2]+1,c[3],rt[mid]);

			if(s1.suf + s2.sum + s3.pre >= 0)ans = mid, l = mid+1;
			else r = mid-1;
		}
		printf("%d\n",lst = a[ans].first);
	}

	return 0;
}
