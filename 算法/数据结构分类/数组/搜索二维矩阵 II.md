## [240. 搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii/)

![Gitlab code coverage badge](https://img.shields.io/badge/难度-中等-yellow)

> 题目描述

编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

- 每行的元素从左到右升序排列。
- 每列的元素从上到下升序排列。

> 解题思路

这道题显然要用二分查找，但是我不知道该怎么同时利用两个方向的条件或者说不知道该怎么写。于是先写了一个效率较低版本的按行二分查找，如果第一个元素大于目标值，直接返回false

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        boolean ans = false;
        for(int i = 0; i < matrix.length; i++){
            if(matrix[i][0] > target){
                return false;
            }
            ans = binarySearch(matrix, target, i, 0, matrix[0].length-1);
            if(ans){
                break;
            }
        }
        return ans;
    }

    public boolean binarySearch(int[][] matrix, int target, int row, int startCol, int endCol){
        if(endCol < startCol){
            return false;
        }
        int mid = (endCol + startCol) / 2;
        if(matrix[row][mid] == target){
            return true;
        }else if(matrix[row][mid] > target){
            return binarySearch(matrix, target, row, startCol, mid-1);
        }else{
            return binarySearch(matrix, target, row, mid+1, endCol);
        }
    }
}
```

 上面的方法确实是一种方法。官方题解还给出一个就是Z字型查找，规则是从矩阵的右上角到左下角形成的矩阵，根据判别大小，变换右上角的坐标，与左下角再次形成一个新的矩阵。这里我的理解是左上角的元素恰好是该行和该列的中间元素(如果矩阵均匀，或者说差不多中间的位置)。

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) 	{
        int row = matrix.length;
        int col = matrix[0].length;
        int x = 0, y = col - 1;
        while(x < row && y >= 0 ){
            if(matrix[x][y] == target){
                return true;
            }else if(matrix[x][y] < target){
                x++;
            }else{
                y--;
            }
        }
        return false;
    }
}
```

总感觉以前做过类似的题，解题思路和这个很像。也是倒着来搜索。。。