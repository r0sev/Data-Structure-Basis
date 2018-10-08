/*
 * 直接插入排序:
 * 将一个记录从无序序列中取出来，然后插入到已经排好序的有序表[默认第一个有序]中，从而
 * 得到一个新的、记录数加1 的有序表
 */

void InsertSort(int a[], int count){

	int j , tmp;

	for (int i = 2; i < count; ++i)		//a[0]用于临时存储、哨兵
	{
		a[0] = -1;						//假定正整数排序

		if (a[i] < a[i-1])
		{
			a[0] = a[i];

			for (j = i-1;a[j]>a[0];j--)
			{
				a[j+1] = a[j];
			}
			
			a[j+1] = tmp;
		}
	}
}