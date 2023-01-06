## MergeSort

> 算法简介

**MergeSort** 即归并排序，是分治算法思想的典型应用，其核心思想是将数组分成若干小的部分，然后通过归并的操作将两个数组归并成一个有序，这样能使数组的局部有序。

> 算法实现

1. 分治(partition),递归的将数组分成若干部分
2. 从下往上进行归并
3. 将辅助数组的内容复制到原数组中

```go
// MergeSort 归并排序
func MergeSort(array []int, tmp []int, start, end int) {
	if end-start < 1 {
		return
	}
	mid := (end+start)>>1
	MergeSort(array, tmp, start, mid)
	MergeSort(array, tmp, mid+1, end)
	i := start
	j := mid + 1
	for index := start; index <= end; index++ {
		if j > end || (i <= mid && array[i] < array[j]){
			tmp[index] = array[i]
			i++
		}else{
			tmp[index] = array[j]
			j++
		}
	}
	for m := start; m <= end; m++{
		array[m] = tmp[m]
	}
}
```

