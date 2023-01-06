## 删除链表的倒数第N个节点

> 题目描述

给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。

> 解题思路

双指针，遍历一趟链表

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    var newHead *ListNode = &ListNode{}
    newHead.Next = head
    var p1 *ListNode = newHead;
    var p2 *ListNode = head;
    var k int = 0
    for p2 != nil && k < n-1{
        p2 = p2.Next
        k++
    }
    for p2.Next != nil{
        p1 = p1.Next
        p2 = p2.Next
    }
    p1.Next = p1.Next.Next
    return newHead.Next
}
```

