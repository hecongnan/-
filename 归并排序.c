void MergeSort(int* arr, int* tem, int left, int right)
{
	if (right <= left+1)                  //当子数组只剩一个元素时停止划分
	{
		return;
	}
	int mid = left + (right - left) / 2;
	MergeSort(arr, tem, left, mid);      //划分出的左子数组
	MergeSort(arr, tem, mid, right);     //划分出的右子数组
    
    
    //后序遍历,归并过程发生在两个递归语句之后
	//左右子数组都有序后完成左右子数组的归并
	int ptr1 = left;								//ptr1指向左子数组的首元素
	int ptr2 = mid;									//ptr2指向右子数组的首元素
	int ptrtem = left;                              //ptrtem用于在tem数组中尾插数据
	while (ptr1 < mid && ptr2 < right)				//ptr1和ptr2其中一个遍历完子数组就停止循环
	{
		//将较小元素尾插进tem数组中
		if (arr[ptr1] > arr[ptr2])
		{
			tem[ptrtem] = arr[ptr2];
			++ptrtem;
			++ptr2;
		}
		else
		{
			tem[ptrtem] = arr[ptr1];
			++ptrtem;
			++ptr1;
		}
	}
	//将未被遍历完的子数组剩下的元素尾插到tem数组中
	while (ptr1 < mid)
	{
		tem[ptrtem] = arr[ptr1];
		++ptrtem;
		++ptr1;
	}
	while (ptr2 < right)
	{
		tem[ptrtem] = arr[ptr2];
		++ptrtem;
		++ptr2;
	}
 
	//将归并好的有序序列拷贝到原数组arr(相应下标位置)
	for (int i = left; i < right; ++i)
	{
		arr[i] = tem[i];
	}
}