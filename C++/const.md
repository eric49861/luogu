# const

不管修饰啥，其实很容易理解，只要弄清楚const到底修饰的变量类型是啥，啥就是不可变的。

> 修饰变量

表示变量不可变，所以const修饰的常量必须被初始化

const修饰的常量会被维护在一个符号表中，和宏定义不同的是，const修饰的变量会进行类型检查，但是宏定义只是单纯的替换，不会做类型检查。

const修饰的全局变量被解释为文件局部变量，意思是不能在其他文件中引用该变量，需要加extern关键字进行显式声明。

```C++
const int a = 10;
a = 5;//error
```

> 修饰指针

两种形式.

下面这种形式表示`*a`不可变，所以`a`是可变的，所以不必在创建时初始化指针的指向，理解起来和修饰变量好像是相同的效果，只不过这个是指针变量。

```C++
int k = 10;
int p = 0;
const int *a = &k;
//int const *a;
a = &p;//OK
*a = p;//not allow
```

下面的这种形式，修饰的是地址本身不可变，但是该地址指向的内存的值是可变的，所以在创建时必须进行初始化指针的指向。

```C++
int k = 0;
int *const a = &k;
*a = 100;//OK
int p = 10;
a = &p;//not allow
```

> const在函数中的形参或者返回值

没啥特殊的，修饰形参，就是为了防止在函数中，形参被修改

当形参为复杂数据类型时，使用引用可以减小程序的开销，避免创建临时对象

```c++
void func(const Type &t)
{}
```

> const修饰函数

const修饰函数时只能修饰类中的成员函数，const修饰的成员函数不能修改类中的数据成员，所以不能在const成员函数中调用非const成员函数，因为非const成员函数可以修改类的成员数据。

```c++
class People
{
public:
    const int age;
    int p;
public:
    People();
    void func() const;
};

People::People():age(10) {}

void People::func() const {
    this->p = 11;//not allow
}
```

const修饰的成员变量必须在空参构造器中初始化。