#include <stdio.h>

void InsertSort(int a[], int count){

	int j , tmp;

	for (int i = 1; i < count; ++i)		//a[0]用于临时存储、哨兵
	{
		a[0] = -1;						//假定正整数排序

		if (a[i] < a[i-1])
		{
			a[0] = a[i];

			for (j = i-1;a[j]>a[0];j--)
			{
				a[j+1] = a[j];
			}
			
			a[j+1] = a[0];
		}
	}
}


// void InsertSort2(int a[], int count){

// 	int j , tmp;

// 	for (int i = 1; i < count; ++i)	
// 	{
// 		if (a[i] < a[i-1])		//默认a[0]一个元素是有序的！
// 		{
// 			tmp = a[i];

// 			for (j = i - 1 ;(printf("--->%d\n", j) && a[j]>tmp) ; j--)//事实上这里的确越界了，但a[-1]=0，于是跳出了循环
// 			{
// 				a[j+1] = a[j];
// 				//printf("--->%d\n", a[j]);
// 			}
// 			printf("a[%d] === %d\n", j, a[j]);
// 			a[j+1] = tmp;
// 		}
// 	}
// }

/* 注意InsertSrot2和InsertSort()的区别 */
//上面Sort2虽然也可以达到效果，但是越界了
void InsertSort2(int a[], int count){

	int j , tmp;

	for (int i = 1; i < count; ++i)	
	{
		if (a[i] < a[i-1])		//默认a[0]一个元素是有序的！
		{
			tmp = a[i];

			for (j = i - 1 ;j>-1 && a[j]>tmp; j--){
				a[j+1] = a[j];
				//printf("--->%d\n", a[j]);
			}

			a[j+1] = tmp;
		}
	}
}


int main(int argc, char const *argv[])
{
	int a[] = {-1, 5, 2, 4, 3, 6, 9 ,8, 7, 0 ,1};
	int b[] = {10, 12, 112, 210, 500, 4};
	InsertSort2(b, 6);

	for (int i = 0; i < 6; ++i)
	{
		printf("%d ",b[i]);
	}
	printf("\n");
	return 0;
}