#include <stdio.h>
#include <string.h>
#include <malloc.h>

int f(int a,int b){
	return a+ b;}
	
int g(int a,int b){return a - b;}

struct data{
	int x,y;
};

void change1(struct data t){	// !!!!
	t.x = 0;
}
void change2(struct data *t){
	t->x=10;
	t->y=10;
}

void testpp(){
	char a[3][3]={"123","456","789"};
	char (*test)[3]=a;
//	printf("%p\n%p\n",test,test+1);
//	printf("%p\n%p\n",a,a+1);
	char (*p)[3]=a;
	int i;
//	a	// ->a[0] -> a[0][0]
	char qq = **a;
//	printf("test %s\n",*p);
//	printf("%c\n",(*p)[1]);
	for(i=0;i<=1;i++){
//		printf("%s\n",*p);
		printf("%c\n",*(*p+1));
		p++; 
	}
	
	struct data t;t.x=1, t.y=2;
	change1(t);
	printf("\nsizeof %d\n",sizeof(struct data));
	printf("\n%d %d\n",t.x,t.y);
	change2(&t);
	printf("%d %d\n",t.x,t.y);
}

int swap(int *p,int *q){
	int t = *p;
	*p = *q;
	*q = t;
}

void mystrlen(char *s){
	int len = 0;
	while(s[len] != '\0') ++ len;
	printf("%d\n",len);
}

void Swap(int *p,int *q){
	int *t = p;
	p = q;
	q = t;
}

int ff(int a,int b){return a+b;}
int gg(int a,int b){return a-b;}

void testfp(){
	int (*p)(int,int);
	int a=2,b=3;
	if(0)p=ff;
	else p=gg;
	printf("%d\n",p(a,b));
}

int main(){
	testfp();return 0;
//	testpp();return 0;
//	int ii=2;
	// 1 0
//	while(i<=3)
//	while(0)
//	for(ii=0;23123;ii++){
//		puts("ok");
//	}return 0;
//	if(ii=1)//..
//	int ii=0;
//	for(ii=0;ii=0;ii)
//	int aa =2, b=3;
//	swap(&aa,&b);
//	printf("%d %d\n",aa,b);return 0;
//	char s[102];
//	scanf("%s",s);
//	mystrlen(s);return 0;
//	char s[9]={"China"};
//	s[5] = 'Q';
//	s[6] = 'Q';
//	s[7] = 'W';
//	printf("%s\n",s);
//	return 0;
//	int ar[]={1,2,3};
//	int a[3][3];
	// *(*(a+i)+j)
//	printf("111 %d\n",*(ar+1));	//ar[1]
//	double ar[] ={1,2,3,4,5};
//	printf("%p\n%p\n%p\n",ar,ar+1,ar+2);return 0;
//	int aa = 2, bb = 3;
//	swap(&aa ,&bb);
//	printf("%d %d\n",aa,bb);return 0;
//	char *str
//	str = "CHina";
// char str[] = "China";
//	printf("%s\n",str);

// 注意这样是错误的：char *a; scanf("%s",a); （内存不明）合理的：char a[10]; ... 

// 字符数组不要忘记 '\0' 
//char str[10] = "China";
//str[5] = 'q';str[6] = 'w';
//str[7] = '\0';
//printf("%d", strlen(str));

/*	函数指针
 
	int t;
	scanf("%d",&t);
	int (*pp)(int ,int);
	if(t == 0)pp= f;
	else pp = g;
	printf("%d\n",pp(2, 3)); 
	*/
	
	// 指针加法：每次地址 + sizeof (type) 其中type就是数组的类型，如int是4，int[3]是3*4
	// 比如 int *p=&a; p+1 -> 内存+4
	// 在二维数组中int[row][col]，因为每个指针的类型是int[col]，因此如果直接对 a +1, -1,则实际修改的只是a[i][0] 
	// 但是用 int*p = a这种形式，每次 p+1 加的是数组中的一个元素，因此可以遍历数组中的所有元素 
	// 注意 int *p = a 和 = *a 是一个东西(*a = a[0]) ，但是后者更优（因为前者是把行地址付给了int*，但是我们实际需要列地址即后面的)
	// int p[], p[3] == *(p+3)
	// int (*p)[3] p 是一个指针，指向一个具有3个元素的数组，注意和二维数组中的第一维很像！ 
	int a[3][3],i,j;
//	int *p = *(a+1);	// 这句话的意思：a+1是行指针，指向a[1] （这个a[1]也是个数组！） ，*了之后取出来指向的东西，即a[1]。注意a[1]也是个指针！（这个是列指针）付给了p 
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
//			scanf("%d", p + (i*3 + j));
			a[i][j] = i *3 + j;
//	int p[3];
//	p &p[0]
//	a[0] &a[0][0]
	int (*q)[3] = a + 1;	// q 是一个指针，指向一个具有 3 个元素的数组
	// 辨析一下：a 表示指向第0行的指针，是行指针
	// a[0] == *a， 表示指向第0行第一个元素的指针，是列指针
	// a + 1 -> 指向了第1行第0个元素 a[0] + 1 -> 指向了第0行第1个元素
	// 注意q指向的是数组，所以应该是行指针，因此用a赋值（也可以a+1 
	printf("%d\n",*(*a +1));	// *(a[0]+1) a[0][1]
//	printf("%p\n%p\n%p\n",a+1,a[0]+1,*a+1); 
//	printf("* %d\n",*(*q + 1));
	printf("* %d\n",(*q)[1]);
//	i = 1, j =2 ;
//	printf("%d\n", p[1]);
	
	char *pst[3] = {"hello"};
	pst[0] = "hello";
	pst[1] = "ysn";
	printf("%s\n",*(pst + 1));	// 带 * 是因为pst是一个数组，也就是指向第一个元素的指针，（每个元素是一个char* 即字符串） 
 
//	char *base = "testit";
//	char (*pstr)[10] = NULL;
//	*pstr = base;
//	printf("%s\n", *pstr);
	
// 指针 +1 增加的字节数取决于基类型 
//	int *p = a;
//	printf("%p\n%p\n", p + 3, &a[1][0]);
//double ap = 1, aq = 2;
//double *p = &ap;
//printf("%p\n",p);
//++ p;
//printf("%p\n",p);

// 指向指针的指针
	testpp(); 
	
	return 0;
}
