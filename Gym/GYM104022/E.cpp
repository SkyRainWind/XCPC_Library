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

map<string,int>bs;

void solve(){
	vector<int>a;
	a.resize(6);
	for(int i=1;i<=4;i++){
		string s;
		cin >> s;
		a[i]=(bs[s]);
	}
	if(a[1]==a[3]||a[2]==a[4])return cout<<"None\n", void();
	if(a[1]==a[2]||a[1]==a[4]||a[2]==a[3]||a[3]==a[4]){
		if(a[1]==a[2]||a[3]==a[4])cout<<"Cis\n";
		else cout<<"Trans\n";
		return ;
	}
	int t1,t2;
	if(a[1]>a[3])t1=1;else t1=3;
	if(a[2]>a[4])t2=2;else t2=4;
	if((t1==1&&t2==2)||(t1==3&&t2==4))cout<<"Zasamman\n";
	else cout<<"Entgegen\n";
}

signed main(){
	bs["-F"]=1;
	bs["-Cl"]=2;
	bs["-Br"]=3;
	bs["-I"]=4;
	bs["-CH3"]=5;
	bs["-CH2CH3"]=6;
	bs["-CH2CH2CH3"]=7;
	bs["-H"]=8;
	
	ios::sync_with_stdio(false);
	int te;cin>>te;
	while(te--)solve();

	return 0;
}

