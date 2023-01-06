# [剑指 Offer II 085. 生成匹配的括号](https://leetcode.cn/problems/IDBivT/)

> 题目描述

正整数 `n` 代表生成括号的对数，请设计一个函数，用于能够生成所有可能的并且 **有效的** 括号组合。

> 解题思路

回溯，在递归过程中只要左括号没有达到最大值，就一直追加，然后撤销，追加右括号，直到字符串的长度达到最大值。

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []

        def generate(curr: str, left: int, right: int):
            if len(curr) == 2 * n:
                ans.append(curr)
                return
            if left < n:
                curr = f'{curr}{"("}'
                generate(curr, left + 1, right)
                curr = curr[:len(curr) - 1]
            if right < left:
                curr = f'{curr}{")"}'
                generate(curr, left, right + 1)
                curr = curr[:len(curr) - 1]

        generate('', 0, 0)
        return ans
```

