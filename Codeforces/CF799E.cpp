// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <queue>
#include <set>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5 + 5;

struct node{int val, id;}nd[maxn];
bool operator < (node a,node b){return a.val > b.val;}
node pq[maxn],pq2[maxn],pq3[maxn],pq4[maxn];
// pq ����ϲ�� pq2 A pq3 B pq4 AB 
int s2[maxn], s3[maxn], s4[maxn], s5[maxn];
// ǰ׺�� 
int n,m,k,vis[maxn],pc1,pc2,pc3,pc4,pc5;
priority_queue<int>r1;
priority_queue<int,vector<int>,greater<int> >r2;	// �Զ��� 

void upd(int s,LL &res){	// ע�� res ��ֻ������ A ��B AB����ϲ�� ������� 
	// ȥ������ѡ���� A �͵� B �ĵ�(k-s)�����Զ����У���Ϊʵ����ѡ�ĸ�������1����˴𰸵Ķѣ�����ѣ���size��Ҫ+1 
	LL mx=-1;
	if(!r1.empty())mx = r1.top();
	node cur1 = pq2[k-s], cur2 = pq3[k-s];
	if(cur1.val > cur2.val)swap(cur1, cur2);
	if(r1.empty()){	// ����һ��ʼ�����AB��ϲ����s��͵�A��B�ֱ��(k-s)�������ǡ����m���������ʱ�𰸶�sizeΪ0����Ҫ�����ˣ� 
		res -= cur1.val; res -= cur2.val;
		vector<int>tmp;
		tmp.push_back(cur1.val);
		tmp.push_back(cur2.val);
		if(!r2.empty())tmp.push_back(r2.top()), r2.pop();
		if(!r2.empty())tmp.push_back(r2.top()), r2.pop();
		sort(tmp.begin(), tmp.end());
		// ���ø����ѣ�С���ѣ��е�2��Ԫ�أ���Ϊ�����ǵ�A ��B �ĵ�(k-s)���С���Ѷ�2��Ԫ��С 
		
		res += tmp[0];	// ��Ϊ �𰸶�size Ҫ��1��ѡ��С�� 
		r1.push(tmp[0]);r2.push(tmp[1]);r2.push(tmp[2]);r2.push(tmp[3]); 
		return ;
	}
	
	// ʣ�µ����������Ժÿ��ǣ�ע��𰸶Ѻ͸�����ÿ�ζ�Ҫsize+1 
	// res ������Ϊ���������˵�ǰ׺���к��е�ǰ�� (k-s) ���������Ҫɾȥ 
	if(cur2.val <= mx){	// delete mx
		r1.pop();r1.push(cur1.val);r1.push(cur2.val);r2.push(mx);
		res = res - mx;
	}else if(cur1.val <= mx){
		r1.push(cur1.val);r2.push(cur2.val);
		res = res - cur2.val;
	}else{
		int tp = r2.top();r2.pop();
		r2.push(cur1.val), r2.push(cur2.val);
		r1.push(tp);
		res = res + tp - cur1.val - cur2.val;
	}
}

signed main(){
//	freopen("CF799E.in","r",stdin);
//	freopen("CF799E-my.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&nd[i].val), nd[i].id = i;
	sort(nd+1,nd+n+1);
	reverse(nd+1,nd+n+1);
	
	int tt;scanf("%lld",&tt);
	while(tt--){int v;scanf("%lld",&v);vis[v] ++;}
	scanf("%lld",&tt);
	while(tt--){int v;scanf("%lld",&v);vis[v] += 2;}
	for(int i=1;i<=n;i++){
		if(vis[nd[i].id] == 1){pq2[++pc2] = nd[i];s2[pc2] = s2[pc2-1] + nd[i].val;} 
		else if(vis[nd[i].id] == 2){pq3[++pc3] = nd[i];s3[pc3] = s3[pc3-1] + nd[i].val;}
		else if(vis[nd[i].id] == 3){pq4[++pc4] = nd[i];s4[pc4] = s4[pc4-1] + nd[i].val;}
		else pq[++pc1]=nd[i];
	}
		
	LL ans = 1e18, ff=0, res;
	for(int s=0;s<=min(pc4, k);s++){	// ö�ٶ�ϲ�����м��� 
		if(s + 2 * (k-s) > m)continue;	// ������ϲ��>=k���Ѿ��� m �� 
		if(n-(pc4-s) < m)continue;		// ��Ϊ�ն���ʣ�¶�ϲ���Ĳ�ѡ�ˣ������������ʱ����´𰸣�������ѡ�Ĳ��� m����Ҳ���� 
		if(k-s > pc2 || k-s > pc3)continue;
		
		int rest = m - s - 2*(k-s);
		if(++ ff == 1){	// ��һ����������֮��ÿ�θ��´� 
			vector<int>tmp;
			for(int i=1;i<=pc1;i++)tmp.push_back(pq[i].val);
			for(int i=k-s+1;i<=pc2;i++)tmp.push_back(pq2[i].val);
			for(int i=k-s+1;i<=pc3;i++)tmp.push_back(pq3[i].val);
			sort(tmp.begin(),tmp.end());
			int rr = 0;
			LL sum = 0;
			for(int u : tmp){
				if(++rr <= rest)r1.push(u), sum += u;
				else r2.push(u);
			}
			res = s2[k-s] + s3[k-s] + sum;
			ans = min(ans, s4[s] + res);	// ��Ϊ��ϲ�������ն��Ĳ��ĵģ�����ÿ�θ���ֻ��Ҫά�� ��A ��B ��AB ����ϲ���Ĵ� 
			upd(s, res);
			continue;
		}
		
		ans = min(ans, res + s4[s]);
		upd(s, res);
	}
	
	// ���������AB��ϲ�������� >= k����ʱʣ�µ������������ѡ���϶�ȡ��С�� 
	for(int i=1;i<=n;i++)
		if(vis[nd[i].id] <= 2){
			++pc5;
			s5[pc5] = s5[pc5-1] + nd[i].val;
		}
	for(int s=k;s<=min(pc4,m);s++){
		// s ��2��ϲ�� ʣ�����ѡ
		if(m-s <= pc5){
			int tmp = s4[s];
			ans = min(ans, tmp + s5[m-s]); 
		}
	}
	printf("%lld\n",ans==(LL)1e18 ? -1 : ans);
//	cerr<<ans<<'\n';

	return 0;
}

