# 二叉搜索树中第K小的元素

> 题目描述

给定一个二叉搜索树的根节点 `root` ，和一个整数 `k` ，请你设计一个算法查找其中第 `k` 个最小元素（从 1 开始计数）。

> 解题思路

1. 中序遍历
2. 记录子树节点数量

这里使用第二种算法

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 type MyBst struct {
	root    *TreeNode
	nodeNum map[*TreeNode]int // 统计以每个结点为根结点的子树的结点数，并存储在哈希表中
}

// 统计以 node 为根结点的子树的结点数
func (t *MyBst) countNodeNum(node *TreeNode) int {
	if node == nil {
		return 0
	}
	t.nodeNum[node] = 1 + t.countNodeNum(node.Left) + t.countNodeNum(node.Right)
	return t.nodeNum[node]
}

// 返回二叉搜索树中第 k 小的元素
func (t *MyBst) kthSmallest(k int) int {
	node := t.root
	for {
		leftNodeNum := t.nodeNum[node.Left]
		if leftNodeNum < k-1 {
			node = node.Right
			k -= leftNodeNum + 1
		} else if leftNodeNum == k-1 {
			return node.Val
		} else {
			node = node.Left
		}
	}
}

func kthSmallest(root *TreeNode, k int) int {
	t := &MyBst{root, map[*TreeNode]int{}}
	t.countNodeNum(root)
	return t.kthSmallest(k)
}
```

