> 题目描述

一种 Playfair 密码变种加密方法如下：首先选择一个密钥单词（称为 pair ）（字母不重复，且都为小写字母），然后与字母表中其他字母一起填入至一个 5x5 的方阵中，填入方法如下：

1. 首先按行填入密钥串。
2. 紧接其后，按字母序按行填入不在密钥串中的字母。
3. 由于方阵中只有 25 个位置，最后剩下的那个字母则不需变换。

如果密钥为 youandme，则该方阵如下：

y o u a n

d m e b c

f g h i j

k l p q r

s t v w x

在加密一对字母时，如 am，在方阵中找到以这两个字母为顶点的矩形：

y o u a n

d m e b c

f g h i j

k l p q r

s t v w x

这对字母的加密字母为该矩形的另一对顶点，如本例中为 ob。

请设计程序，使用上述方法对输入串进行加密，并输出加密后的串。

另外有如下规定：

1. 一对一对取字母，如果最后只剩下一个字母，则不变换，直接放入加密串中；
2. 如果一对字母中的两个字母相同，则不变换，直接放入加密串中；
3. 如果一对字母中有一个字母不在正方形中，则不变换，直接放入加密串中；
4. 如果字母对出现在方阵中的同一行或同一列，如 df 或 hi，则只需简单对调这两个字母，即变换为 fd 或 ih ；
5. 如果在正方形中能够找到以字母对为顶点的矩形，假如字母对为 am，则该矩形的另一对顶点字母中，与 a 同行的字母应在前面，在上例中应是 ob；同样若待变换的字母对为 ta，则变换后的字母对应为 wo；
6. 本程序中输入串均为小写字母，并不含标点、空格或其它字符。

解密方法与加密相同，即对加密后的字符串再加密，将得到原始串。

> 解题思路

根据题目要求模拟即可，这里不需要使用二维数组，可以直接使用二维数组在一维数组中的索引关系进行转换即可。

```python
import os
import sys

# 请在此输入您的代码

pair = input()
s = input()
square = list(pair)

step = 0
while len(square) < 25:
    tmp = chr(ord('a') + step)
    if tmp not in list(pair):
        square.append(tmp)
    step += 1

i = 0
ans = ""
while i < len(s):
    if i == len(s) - 1:
        ans = f'{ans}{s[i]}'
        break
    if (s[i] not in square) | (s[i + 1] not in square) | (s[i] == s[i + 1]):
        ans = f'{ans}{s[i]}{s[i+1]}'
    else:
        index_1_row, index_1_col = (int(square.index(s[i]) / 5), square.index(s[i]) % 5)
        index_2_row, index_2_col = (int(square.index(s[i + 1]) / 5), square.index(s[i + 1]) % 5)
        if (index_1_row == index_2_row) | (index_1_col == index_2_col):
            ans = f'{ans}{s[i+1]}{s[i]}'
        else:
            ans = f'{ans}{square[index_1_row * 5 + index_2_col]}{square[index_2_row * 5 + index_1_col]}'
    i += 2

print(ans)
```

