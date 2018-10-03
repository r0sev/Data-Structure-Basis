#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

//线索存储标志位,Link表示指向孩子,Thread表示线索
typedef enum {Link, Thread} PointerTag;			//默认0 和 1
typedef struct ThreadBiNode
{
	ElemType data;
	//int ltag, rtag;
	PointerTag ltag, rtag;
	struct ThreadBiNode *lchild, *rchild;
}ThreadBiNode, *ThreadBiTree;

/*
 * 思路：先创建一棵正常的树，然后线索化
 * 线索化后遍历会更加简单
 */
//创建二叉树，约定按照先序遍历输入数据
void CreateThreadBiTree(ThreadBiTree *T){
	ElemType c;
	scanf("%c", &c);
	if(' ' == c )
		*T = NULL;
	else{
		*T = (ThreadBiNode *)malloc(sizeof(ThreadBiNode));
		(*T)->data = c;
		(*T)->ltag = Link;
		(*T)->rtag = Link;

		CreateThreadBiTree(&(*T)->lchild);
		CreateThreadBiTree(&(*T)->rchild);
	}
}

//下面函数需要一个全局变量
ThreadBiTree preNode;		//注意这是一个指针变量!

//中序遍历线索化的过程
void InOrderThreading(ThreadBiTree T){
	
	if(T){
		InOrderThreading(T->lchild);		//递归左孩子线索化
		
		//处理结点
		if( !T->lchild ){
			T->ltag = Thread;
			T->lchild = preNode;			//这里使用了全局变量preNode
		}
		if( !preNode->rchild )
		{
			preNode->rtag = Thread;
			preNode->rchild = T;
		}
		preNode = T;			//preNode 改而指向T --- 当前访问的结点

		InOrderThreading(T->rchild);		//递归右孩子线索化
	}

}

void InThreading(ThreadBiTree *p, ThreadBiTree T){
	*p = (ThreadBiTree)malloc(sizeof(ThreadBiNode));	
	//为preNode占个位，防止InOrderThreading过程中访问preNode出错
	(*p)->ltag = Link;		//因为lchild--->T(root)故为Link
	(*p)->rtag = Thread;	//因为rchild--->指向中序最后一个结点，故为Thread
	(*p)->rchild = *p;

	if(!T)					//若T为空树
		(*p)->lchild = *p;
	else{
		(*p)->lchild = T;
		preNode = *p;
		InOrderThreading( T );
		//处理中序结束前的最后一个结点
		preNode->rchild = *p;
		preNode->rtag = Thread;
		(*p)->rchild = preNode;
	}
}

//visit()
void visit(ElemType c)
{
	printf("%c", c);
}


//重头戏来了，线索二叉树的应用，做了这么多就是为了这个函数做铺垫
//中序遍历线索二叉树，非递归
void InOrderTraverse( ThreadBiTree T )
{
	ThreadBiTree p;
	p = T->lchild;		//这里的T其实指的是指向该树的根 的一个指针!

	while( p != T )
	{
		while(p->ltag == Link)	//一直往左遍历，知道找到中序逻辑的第一个节点
		{
			p = p->lchild;
		}	//此时p->ltag == Thread了 即已经到了第一个节点
		visit(p->data);

		//在此以后直接一直访问rchild即可中序遍历完所有的结点
		while(p->rtag == Thread && p->rchild!= T)
		{
			p = p->rchild;
			visit(p->data);
		}
		//收尾处理一下p, 令p指向头结点
		p = p->rchild;
	}
}

int main()
{
	ThreadBiTree P, T = NULL;
	CreateThreadBiTree( &T );

	InThreading( &P, T );
	printf("中序遍历序列：");
	InOrderTraverse( P );		//传入头结点而不是根节点

	printf("\n");
	return 0;
}


