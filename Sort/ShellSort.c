/*
 * 希尔排序: NlogN的算法
 * 
 * 基于直接插入排序，加入间隔变量，模拟分组，间隔逐渐缩小， 直至为1，即最后一趟其实就是一个基本有序的
 * 序列了，相当于最后一次对一个基本有序序列进行直接插入排序
 */

void ShellSort(int a[], int count){

	int j , tmp , gap = count;

	do{
		gap = gap/3 + 1;

		for (int i = gap; i < count; ++i)	
		{ 
			if (a[i] < a[i - gap])
			{
				tmp = a[i];

				for (j = i - gap; j>= 0 && a[j]>a[0];j-=gap)
				{
					a[j+gap] = a[j];
				}
			
				a[j+gap] = tmp;
			}
		}

	}while(gap > 1);
	
}