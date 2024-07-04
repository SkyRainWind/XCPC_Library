#include <stdio.h>

int f(int x){
	if(x<=1)return x;
	if(1<x && x<10)return 2*x-1;
	return 3*x-11;
}

int main(){
	int x;
	scanf("%d",&x);
	printf("%d\n",f(x));
	
	return 0;
}
