### 实现 strStr()

> 题目描述

实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

说明：

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。

> 解题思路

求字符串前缀

```go
func strStr(haystack string, needle string) int {
    if needle == ""{
        return 0
    }
    var s string = needle + "+" + haystack
    var ans int = prefixFunction(s, len(needle))
    return ans
}
//求前缀
func prefixFunction(s string, k int) int{
    n := len(s)
    var dp []int = make([]int, n)
    for i := 1; i < n; i++{
        j := dp[i-1]
        for j > 0 && s[i] != s[j]{
            j = dp[j-1]
        }
        if s[i] == s[j]{
            j++
        }
        dp[i] = j
        if dp[i] == k{
            return i - 2*k
        }
    }
    return -1
}
```

优化上述代码

```go
func strStr(haystack, needle string) int {
    n, m := len(haystack), len(needle)
    if m == 0 {
        return 0
    }
    dp := make([]int, m)
    for i, j := 1, 0; i < m; i++ {
        for j > 0 && needle[i] != needle[j] {
            j = dp[j-1]
        }
        if needle[i] == needle[j] {
            j++
        }
        dp[i] = j
    }
    for i, j := 0, 0; i < n; i++ {
        for j > 0 && haystack[i] != needle[j] {
            j = dp[j-1]
        }
        if haystack[i] == needle[j] {
            j++
        }
        if j == m {
            return i - m + 1
        }
    }
    return -1
}
```

