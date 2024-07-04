// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 3e5+5;

int notpm[maxn],pm[maxn],pcnt,least[maxn];

void xxs(){
	notpm[1] = 1;
	for(int i=2;i<=maxn-5;i++){
		if(!notpm[i]){
			pm[++ pcnt] = i;
			least[i] = i;
		}
		for(int j=1;j<=pcnt && 1ll*i*pm[j] <= maxn-5;j++){
			notpm[i*pm[j]] = 1;
			least[i*pm[j]] = pm[j];
			if(i%pm[j] == 0)break;
		}
	}
}
int n,a[maxn];
set<int>_divs[maxn], out[maxn];
vector<int>divs[maxn];
queue<pii>Q;
int have[maxn], dis[maxn], pre[maxn], vis[maxn];

void _out(int _fm, int _to){
	vector<int>ans;
	ans.push_back(_to);
	int fm = a[_fm], to = a[_to];
	while(to != fm){
		to = pre[to];
		if(to == fm)break;
		ans.push_back(have[to]);
	}
	ans.push_back(_fm);
	reverse(ans.begin(), ans.end());
	printf("%d\n",ans.size());
	for(int u : ans)printf("%d ",u);puts("");
	exit(0);
}

signed main(){
//	freopen("CF1775D.in","r",stdin);
	memset(dis,0x3f,sizeof dis);
	xxs();
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		have[a[i]] = i;
		int j = a[i], lst = least[j];
		while(j != 1){
			while(j != 1 && j%least[j] == 0){
				j /= least[j];
				if(least[j] != lst)divs[a[i]].push_back(lst);
				lst = least[j];
			}
		}
		if(lst)divs[a[i]].push_back(lst);
	}
	
	for(int i=1;i<=pcnt;i++){
		for(int j=pm[i];j<=maxn-5;j+=pm[i]){
			if(have[j])out[pm[i]].insert(j);
		}
	}
	
	int s, t;scanf("%d%d",&s,&t);
	if(s == t)return printf("1\n%d\n",s), 0;
	if(a[s] == 1 || a[t] == 1)return puts("-1"), 0;
	if(a[s] == a[t]){
		printf("2\n%d %d\n",s,t);
		return 0;
	}
	Q.push(mpr(0, a[s]));dis[a[s]] = 0;
	
	for(int v : divs[a[s]])
		out[v].erase(a[s]);
	while(!Q.empty()){
		pii u = Q.front();Q.pop();
		int now = u.second;if(vis[now])continue;
		vis[now] = 1;
		for(int v : divs[now]){
			vector<int>tmp;
			for(int vv : out[v]){
				if(dis[vv] > dis[now] + 1){
					tmp.push_back(vv);
					dis[vv] = dis[now] + 1;
					pre[vv] = now;
					if(vv == a[t]){
						_out(s,t);
					}
					Q.push(mpr(dis[vv], vv));
				}
			}
			for(int nn : tmp)
				for(int v : divs[nn])
					out[v].erase(nn);
		}
	}
	puts("-1");

	return 0;
}

