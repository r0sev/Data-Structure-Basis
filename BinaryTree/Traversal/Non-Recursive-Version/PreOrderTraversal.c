//非递归先序遍历 ，浙大数据结构视频版本：
void PreOrderTraversal( BinTree BT )
{
	BinTree T=BT;
	Stack S = CreateStack( MaxSize );
	while(T || !IsEmpty(S) )
	{
		while(T){
			PUSH(S,T);
			printf("%5d", T->Data);
			T = T->Left;
		}
		if(!IsEmpty(S)){
			T = POP(S);
			T = T->Right;
		}
	}
}

//其实就是将printf移到了while循环里
