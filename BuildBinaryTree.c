#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BinTreeNode{
	ElemType data;
	struct BinTreeNode *lchild;
	struct BinTreeNode *rchild;
}BinTNode, *BiTree;

//创建一棵二叉树，约定用户遵照'前序遍历'的方式输入数据
//叶子结点约定且必须用空格代替如 AB D  CE   #
CreateBinTree(BiTree *T)
{
	ElemType c;

	scanf("%c", &c);
	if( ' '== c ){
		*T = NULL;
	}else{
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreateBinTree(&(*T)->lchild);
		CreateBinTree(&(*T)->rchild);
	}
}

//访问二叉树结点的具体操作
visit(char c, int level){
	printf("%c 位于第 %d层\n", c, level);
}

// 遍历二叉树 并打印结点所在层数
PreOrderTraverse(BiTree T, int level){

	if (T)
	{
		visit(T->data, level);
		PreOrderTraverse(T->lchild, level+1);
		PreOrderTraverse(T->rchild, level+1);
	}
}

int main(){
	int level = 1;		//root in 1st level
	BiTree T = NULL;

	CreateBiTree(&T);
	PreOrderTraverse(T, level);

	return 0;
}

