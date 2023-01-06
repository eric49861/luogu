# this

我的理解this应该是实现面向对象的一个重要的概念，和Java中的this，Python中的self中的概念是相同的。

在C++中调用对象的非静态成员函数时，编译器会自动帮我们传入一个变量this指针。

但是常函数和普通的成员函数中的this是不一样的。

> 普通成员函数中的this

![2](D:\学习笔记\C++\imgs\2.png)

这里的this被解释为Student *const类型

> 常函数中的this

![1](D:\学习笔记\C++\imgs\1.png)

这里的this被解释为const Student *const类型

