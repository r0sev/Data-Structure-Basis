void InOrderTraversal( BinTree BT )
{
	if ( BT ){
		InOrderTraversal( BT->leftChild );
		printf("%d", BT->data);		//访问结点操作- - -> 可更改
		InOrderTraversal( BT->rightChild );
	}
}
//以上是中序遍历二叉树的递归算法，先序，后序只需调换对应语句顺序即可



//中序非递归的算法--->借助'栈'
void InOrderTraversal( BinTree BT ){
	//初始化一个栈
	Stack st;
	InitStack( &st );

	if(BT)
		exit(0);			//空树，直接退出

	BinNode *p = BT;
	PUSH(&st, BT);

	//栈非空，这个条件可根据实际情况更改，此处使用前些天的链式栈结构
	while(st->top != st->base || p->rightChild != NULL) 
	//后一个条件是当根节点弹出后，栈已空而右子树还有的情形
	{
		POP(&st, p);
		//POP完还得放回去，，因为根节点后面还得用...
    	PUSH(&st, *p);
		while( p->leftChild )
        {
			//应该将结点整个入栈，不然不好操作，下面的e也应更改为Node类
            PUSH(&st, p->leftChild);           
			p = p->leftChild;
    	}
		POP(&st, p);
		//访问结点
		printf("%d", p->data);
		//遍历右子树
		while( p->rightChild )
		{
			PUSH(&st, p->rightChild);
			continue;
		}
	}
}


//非递归中序遍历 Versino2，浙大数据结构视频版本：
void InOrderTraversal( BinTree BT )
{
	BinTree T=BT;
	Stack S = CreateStack( MaxSize );
	while(T || !IsEmpty(S) )
	{
		while(T){
			PUSH(S,T);
			T = T->Left;
		}
		if(!IsEmpty(S)){
			T = POP(S);
			printf("%5d", T->data);
			T = T->Right;
		}
	}
}
//结论：比我自己写的简单多了，，，😂
