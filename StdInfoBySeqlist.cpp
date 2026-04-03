#include <bits/stdc++.h>
using namespace std;
#define max 100
typedef struct{
    int stdNo;
    char stdName[20];
    float stdScore;
}ElemType;
typedef struct{
	ElemType data[max];
	int last;
}SeqList;
/*在顺序表L中第i个数据元素之前插入一个元素e。 插入前表长n=L->last+1，
i的合法取值范围是 1≤i≤L->last+2  */
int InsList(SeqList *L,int i,ElemType e)
{ 
	if(i<1||i>L->last+2){
		cout<<"错误"<<endl;
		return 0;
	}
	if(L->last>=max-1){
		cout<<"顺序表满了"<<endl;
		return 0;
	}
	for(int k=L->last+1;k>=i;k--){
		L->data[k]=L->data[k-1];
	}
	L->data[i-1]=e;
	L->last++;
	return 1;
}

int  DelList(SeqList *L,int i,ElemType *e)
/*在顺序表L中删除第i个数据元素，并用指针参数e返回其值。i的合法取值为1≤i≤L.last+1 */    
{ 
	if(i<1||i>L->last+1){
		return 0;
	}
	*e=L->data[i-1];
	for(int k=i-1;k<L->last+1;k++){
		L->data[k]=L->data[k+1];
	}
	L->last--;
	return 1;
}
bool NameIsEqual(char a[], char b[]){
	return strcmp(a,b)==0;
}
int  LocateByName(SeqList L, char nam[])
{	
	for(int i=0;i<L.last+1;i++){
		if(NameIsEqual(nam,L.data[i].stdName)){
			return i+1;
		}
	}
	return -1;
}
int main()
{
	SeqList *l;
	int p,q,r;
	int i;
	ElemType oneStd;
	char qName[50];
	l=(SeqList*)malloc(sizeof(SeqList));
	printf("请输入学生人数:");
	scanf("%d",&r);
	l->last = r-1;
	printf("请输入学生学号、姓名、成绩:\n");
	for(i=0; i<=l->last; i++)
	{
		printf("第%d个学生：\n",i+1);
        printf("学号：\n");
		scanf("%d",&l->data[i].stdNo);
		printf("姓名：\n");
		scanf("%s",l->data[i].stdName);
		printf("成绩：\n");
		scanf("%f",&l->data[i].stdScore);
		
	}
    //以下代码段实现通过学生姓名查找学生信息 
    printf("请输入查找的学生姓名:\n");
    scanf("%s",qName);
	p=LocateByName(*l,qName);
	if(p == -1)
		printf("在线性表没有该元素!\n");
	else{
		printf("该元素在线性表的位置:%d 这个学生信息如下：\n",p);
		printf("学号：%d, 姓名：%s, 成绩：%.1f  \n",l->data[p-1].stdNo,l->data[p-1].stdName,l->data[p-1].stdScore);
	}
    // return 0; #去掉这行第一个'#'将不执行后面的代码
	
	//以下代码段实现在第几个位置插入学生 
	printf("请输入要插入的位置:\n");
	scanf("%d",&p);
	printf("请输入要插入的学生信息:\n");
	printf("学号：\n");
	scanf("%d",&oneStd.stdNo);
	printf("姓名：\n");
	scanf("%s",oneStd.stdName);
	printf("成绩：\n");
	scanf("%f",&oneStd.stdScore);
	InsList(l,p,oneStd);
	//return 0; #去掉这行第一个'#'将不执行后面的代码

	
	//以下代码实现删除第几个学生的信息
	printf("请输入将要删除的学生姓名\n");
	scanf("%s",qName);
	DelList(l,LocateByName(*l,qName),&oneStd);
	
	
	//return 0; #去掉这行第一个'#'将不执行后面的代码
	 
	//以下代码段实现打印所有学生的信息 
	printf("现有以下学生：\n");
	printf("学号，姓名，成绩\n"); 
	for(i=0; i<=l->last; i++)
	{
		printf("%i, %s, %.1f  \n",l->data[i].stdNo,l->data[i].stdName,l->data[i].stdScore);
	}
	printf("当前的学生数为%d\n",(*l).last+1);
	
	return 0;
}
