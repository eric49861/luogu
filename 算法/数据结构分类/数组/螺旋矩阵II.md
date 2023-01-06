## [59. 螺旋矩阵 II](https://leetcode.cn/problems/spiral-matrix-ii/)

![Gitlab code coverage badge](https://img.shields.io/badge/难度-中等-yellow)

> 题目描述

给你一个正整数 `n` ，生成一个包含 `1` 到 `n2` 所有元素，且元素按顺时针顺序螺旋排列的 `n x n` 正方形矩阵 `matrix` 。

> 解题思路

按层模拟

```java
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        int top = 0, bottom = n-1, left = 0, right = n-1;
        int num = 1;
        while(left <= right){
            if(left == right){
                matrix[left][right] = n*n;
                break;
            }
            //从左向右
            for(int i = left; i < right; i++){
                matrix[left][i] = num;
                num++;
            }
            //从上到下
            for(int i = top; i < bottom; i++){
                matrix[i][right] = num;
                num++;
            }
            //从右向左
            for(int i = right; i > left; i--){
                matrix[bottom][i] = num;
                num++;
            }
            //从下到上
            for(int i = bottom; i > top; i--){
                matrix[i][left] = num;
                num++;
            }
            //到下一层
            left++;
            right--;
            top++;
            bottom--;
        }
        return matrix;
    }
}
```



```java
class Solution {
    public int[][] generateMatrix(int n) {
        int num = 1;
        int[][] matrix = new int[n][n];
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                matrix[top][column] = num;
                num++;
            }
            for (int row = top + 1; row <= bottom; row++) {
                matrix[row][right] = num;
                num++;
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    matrix[bottom][column] = num;
                    num++;
                }
                for (int row = bottom; row > top; row--) {
                    matrix[row][left] = num;
                    num++;
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return matrix;
    }
}
```

模拟

```java
class Solution {
    public int[][] generateMatrix(int n) {
        int maxNum = n * n;
        int curNum = 1;
        int[][] matrix = new int[n][n];
        int row = 0, column = 0;
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 右下左上
        int directionIndex = 0;
        while (curNum <= maxNum) {
            matrix[row][column] = curNum;
            curNum++;
            int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || matrix[nextRow][nextColumn] != 0) {
                directionIndex = (directionIndex + 1) % 4; // 顺时针旋转至下一个方向
            }
            row = row + directions[directionIndex][0];
            column = column + directions[directionIndex][1];
        }
        return matrix;
    }
}
```

