## [剑指 Offer 30. 包含min函数的栈](https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof/)

![Gitlab code coverage badge](https://img.shields.io/badge/难度-简单-green)

> 题目描述

定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

> 解题思路

内部维护两个线性表，作为栈的底层数据结构。一个用于存放栈的元素，另一个用于记录当前栈的最小值。同时维护两个尾指针，降低每次调用的时间复杂度。（这里实际上也没有必要，ArrayList底层数据结构是数组，都已经提供了，我这里只是为了模拟）

按照一下规则进行设计：

- push操作直接将元素添加到线性表的尾部，同时比较与最小值栈的栈顶元素

  如果比最小值栈的栈顶元素小，则将该数依次入这两个栈，同时更新两个尾指针

- pop操作：这里pop操作没有返回值，所以可以直接将尾指针指向的元素移除，同时比较与最小值栈的栈顶元素是否相同，

  如果相同，则同时移除。否则只操作原栈

- top操作直接返回栈顶元素

- min操作返回最小值栈的栈顶元素

```java
class MinStack {
    private final ArrayList<Integer> stack = new ArrayList<>();
    private final ArrayList<Integer> minStack = new ArrayList<>();
    int top = -1;
    int last = -1;
    /** initialize your data structure here. */
    public MinStack() {

    }
    
    public void push(int x) {
        if(minStack.isEmpty() || x <= minStack.get(last)){
            minStack.add(x);
            last++;
        }
        stack.add(x);
        top++;
    }
    
    public void pop() {
        int v = stack.get(top);
        if(v == minStack.get(last)){
            minStack.remove(last--);
        }
        stack.remove(top--);
    }
    
    public int top() {
        return stack.get(top);
    }
    
    public int min() {
        return minStack.get(last);
    }
}
```

