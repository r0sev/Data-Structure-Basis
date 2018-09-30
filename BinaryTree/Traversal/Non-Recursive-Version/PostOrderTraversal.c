//非递归后序遍历 ，浙大数据结构视频版本：
/*
给数的结点增加一个访问次数（visit）属性
遍历左子树，依次入栈
到底后出栈一个元素，判断访问次数是否为2
若不是，则访问次数为1，访问次数+1，再次入栈，T指向右子树(访问右子树),进入下次循环
若是，则输出，T指向空(左右子树都访问了),进入下次循环
 */

void PostOrderTraversal( BinTree BT )
{
	BinTree T=BT;
	Stack S = CreateStack( MaxSize );
	while(T || !IsEmpty(S) )
	{
		while(T){
			T->visit++;				//visit initial to 0
			PUSH(S,T);
			T = T->Left;
		}
		if(!IsEmpty(S)){
			T = POP(S);
			if(T->visit == 2){
				printf("%5d", T->data);
				T=NULL;				//这一步很关键！
			}else{
				T->visit++;
				PUSH(S,T);			//访问次数不等于2，二次入栈
				T = T->Right;
			}
		}
	}
}
