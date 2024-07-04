#include<bits/stdc++.h>
using namespace std;
int inp(){
    char c = getchar();
    while(c <'0' || c > '9')
        c = getchar();
    int sum = 0;
    while(c >= '0' && c <= '9'){
        sum = sum * 10 + c - '0';
        c = getchar();
    }
    return sum;
}

int a[1000010];
std::unordered_map<int, bool> have;

mt19937 mrand(random_device{}()); 
int rnd(int x) { return mrand() % x;}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	vector<int>a(n*2);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]); 
	   	vector<int>cnt(2222,0);
    	for(int i=1;i<=n;i++){
    		for(int j=0;j<=30;j++)if(((a[i]^k)>>j)&1)++cnt[j];
		}
		int f=0;
		for(int i=1;i<=n;i++)if(a[i]==k)f=1;
		for(int i=0;i<=30;i++){
			printf("%d ",cnt[i]);
			if((cnt[i]==0||cnt[i]==n/2||cnt[i]==n)&&(n%2==0));else f=0;
		}
	if(f)puts("shoule be bob");

	return 0;
}
