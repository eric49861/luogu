## [560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/)

![Gitlab code coverage badge](https://img.shields.io/badge/难度-中等-yellow)

> 题目描述

给你一个整数数组 `nums` 和一个整数 `k` ，请你统计并返回 *该数组中和为 `k` 的连续子数组的个数* 。

> 解题思路

枚举

```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        int ans = 0;
        int n = nums.length;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j >= 0; j--){
                sum += nums[j];
                if(sum == k){
                    ans++;
                }
            }
        }
        return ans;
    }
}
```

前缀和+hashMap优化

```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0, pre = 0;
        HashMap <Integer, Integer> mp = new HashMap<>();
        mp.put(0, 1);
        for (int i = 0; i < nums.length; i++) {
            pre += nums[i];
            if (mp.containsKey(pre - k)) {
                count += mp.get(pre - k);
            }
            mp.put(pre, mp.getOrDefault(pre, 0) + 1);
        }
        return count;
    }
}
```

