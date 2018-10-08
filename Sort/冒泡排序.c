#include <stdio.h>

/*
	冒泡排序
*/

void BubbleSort(int *a, int n)
{
		int j, tmp = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n - i - 1 ; ++j)
			{
				/* code */
				if ( *(a+j) > *(a+j+1))
				{
					tmp = *(a+j+1);
					*(a+j+1) =  *(a+j);
					*(a+j) = tmp;
				}
			}
		}
}

void BubbleSort2(int a[], int n)
{
		int j, tmp = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n - i - 1 ; ++j)
			{
				/* code */
				if ( a[j] > a[j+1])
				{
					tmp = a[j+1];
					a[j+1] =  a[j];
					a[j] = tmp;
				}
			}
		}
}


int main(int argc, char const *argv[])
{
	int a[] = {2,4,7,9,3,5,6,8,0,1};
//	BubbleSort(a,10);
	BubbleSort2(a, 10);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}