// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int to(char x){
	if(x == 'K')return 13;
	if(x == 'Q')return 12;
	if(x == 'J')return 11;
	if(x == 'T')return 10;
	if(x == 'A')return 14;
	return x - '0';
}

int n,m;

void solve(){
	scanf("%d%d",&n,&m);
	vector<int>a, b;
	for(int i=1;i<=n;i++){
		char s[5];
		scanf("%s",s+1);
		a.pb(to(s[1]));
	}
	for(int i=1;i<=m;i++){
		char s[5];
		scanf("%s",s+1);
		b.pb(to(s[1]));
	}
	char t[5];scanf("%s",t+1);
	int pr = to(t[1]);
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int less = 0;
	for(int i=0;i<b.size();i++)if(b[i] < pr)++ less;
	
	if(a.size() == 1 || (less == 0 || a[0] >= pr)){
		cout << "Shou\n";
		return ;
	}
	int big = *prev(lower_bound(a.begin(), a.end(), pr));
	if(b.size() == 1 && b[0] > big){
		cout << "Shou\n";
		return ;
	}
	if(b.size() == 1 && b[0] < pr){
		cout << "Pang\n";
		return ;
	}
	
	if(less >= 2){
		cout << "Pang\n";
		return ;
	}
	
	if(a.back() > b.back() && a.size() > 3 && b[0] <= big && a[0] < pr && a[1] < pr){
		cout << "Pang\n";
		return ;
		int least = b[0];
		int tmp = 0;
		for(int i=0;i<a.size();i++)
			if(a[i] >= least && a[i] < pr)++ tmp;
		if(tmp == 1)cout << "Shou\n";
		else{
			if(a.back() > b.back() && a.size() > 3)cout << "Pang\n";
			else cout << "Shou\n";
		}
	}
	cout << "Shou\n";
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

