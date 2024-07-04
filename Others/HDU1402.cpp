// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=5e5+5;

namespace fft{
	const double pi = acos(-1.0);
	struct complex{
		double x,y;
		complex(double x=0,double y=0):x(x),y(y){}
	}a[maxn],b[maxn];
	complex operator + (complex a,complex b){return complex(a.x+b.x,a.y+b.y);}
	complex operator - (complex a,complex b){return complex(a.x-b.x,a.y-b.y);}
	complex operator * (complex a,complex b){return complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
	
	int r[maxn],lim;
	
	void dft(complex *a,int op){
		for(int i=0;i<lim;i++)if(i<r[i])swap(a[i],a[r[i]]);
		for(int mid=1;mid<lim;mid<<=1){
			complex wn(cos(pi/mid), op*sin(pi/mid));
			for(int r=mid<<1,j=0;j<lim;j+=r){
				complex w(1,0);
				for(int k=0;k<mid;k++,w=w*wn){
					complex x=a[j+k],y=w*a[j+mid+k];
					a[j+k]=x+y;
					a[j+mid+k]=x-y;
				}
			}
		}
	}
	
	vector<int>fft(vector<int>f,vector<int>g){	// f[0] g[0] ´ú±íµÍÎ»  
		for(int i=0;i<=lim;i++)a[i].x=a[i].y=b[i].x=b[i].y=0;
		
		int n=f.size(),m=g.size();
		--n, --m;
		int len=0;
		lim=1;
		while(lim<=n+m)lim<<=1,++len;
		for(int i=0;i<=lim;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(len-1));
		for(int i=0;i<=n;i++)a[i].x=f[i];
		for(int i=0;i<=m;i++)b[i].x=g[i];
		
		dft(a,1);dft(b,1);
		for(int i=0;i<=lim;i++)a[i]=a[i]*b[i];
		dft(a,-1);
		
		vector<int>res;
		for(int i=0;i<=n+m;i++)res.pb((int)(a[i].x/lim+0.5));
		return res;
	}
}

char s[maxn],t[maxn];
vector<int>f,g;
signed main(){
	while(scanf("%s",s+1) != EOF){
		f.clear(),g.clear();
		scanf("%s",t+1);
		int n=strlen(s+1), m=strlen(t+1);
		for(int i=n;i>=1;i--)f.pb(s[i]-'0');
		for(int i=m;i>=1;i--)g.pb(t[i]-'0');
		vector<int>res = fft::fft(f,g);
		int jw = 0;
		for(int i=0;i<res.size();i++){
			res[i] += jw;
			jw = 0;
			if(res[i]>=10)jw=res[i]/10,res[i]%=10;
		}
		while(jw){
			res.pb(jw%10);
			jw /= 10;
		}
		int f=0;
		for(int i=res.size()-1;i>=0;i--)if(f||res[i])f=1,printf("%d",res[i]);
		if(!f)printf("0");
		puts("");
	}

	return 0;
}

