## Karatsuba乘法

> 算法简介(from baidu)

Karatsuba乘法是一种快速乘法。此算法在1960年由Anatolii Alexeevitch Karatsuba 提出，并于1962年得以发表。 [1] 此算法主要用于两个大数相乘。普通乘法的复杂度是$n^2$，而Karatsuba算法的复杂度仅为 $3n^{log3}≈3n^{1.585}$（log3是以2为底的）

> 算法实现

唯一要注意的地方是，两数相乘后的结果是否会超出数值类型的范围，要做调整。

go语言中int64的范围

`Range: -9223372036854775808 through 9223372036854775807`

```go
/*
 * 计算num1和num2的位数并返回较大的
 */
func maxlen(num1, num2 int64) int64{
	if num1 == 0 && num2 == 0{
		return 1
	}
	var ans1 int64 = 0
	var ans2 int64 = 0
	for num1 != 0{
		num1 /= 10
		ans1++
	}
	for num2 != 0{
		num2 /= 10
		ans2++
	}
	if ans1 > ans2{
		return ans1
	}
	return ans2
}

// Karatsuba Karatsuba乘法
func Karatsuba(num1, num2 int64) int64{
	n := maxlen(num1, num2)
	if n == 1 {
		return num1* num2
	}
	a, b := num1 / int64(math.Pow10(int(n/2))), num1 % int64(math.Pow10(int(n/2)))
	c, d := num2 / int64(math.Pow10(int(n/2))), num2 % int64(math.Pow10(int(n/2)))
	ac := Karatsuba(a, c)
	bd := Karatsuba(b, d)
	adbc := Karatsuba(a+b, c+d) - ac - bd
	return ac * int64(math.Pow10(int(n/2*2))) + adbc * int64(math.Pow10(int(n/2))) + bd
}
```

