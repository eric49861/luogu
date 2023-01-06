# Static

感觉这里和Java中static关键字的作用是相似的。

被static修饰的变量和函数0生命周期是和程序一致的，并且static也会起到隔离的作用。

> static修饰变量

不管是修饰全局变量还是局部变量，他们都被存储在全局数据区，生命周期和整个程序的生命周期一致，并且被static修饰的全局变量只能在本文件中使用，不能在其它文件中使用。

虽然生命周期变了，但是作用域并没有变，局部变量也只能在它的作用域内使用。

被static修饰的变量如果没有初始化，会被自动初始化为0.

```c++
void func()
{
    static int a = 0;
    std::cout << a << " ";
}
int main(int argc, char **argv)
{
    for(int i = 0; i < 5; i++){
        func();
    }
    return 0;
}
//output:1 2 3 4 5
```

> static修饰函数

static修饰非成员函数和修饰成员函数是不一样的，修饰成员函数后面再说。

当static修饰非成员函数时，该函数不能在其他文件中使用，其他的使用基本没啥变化(可能目前我还没不知道)

```C++
int a = 10;
static void func()
{
    a = 5;//allow
}
```

> static修饰成员变量和成员函数

这里就涉及到面向对象的一些概念，在Java中static修饰的成员变量和函数是类加载时(每一个类会生成一个字节码文件)创建的，因此只创建一次，不同的对象**共享一个变量**,C++中为静态变量单独申请的存储空间。

被static修饰的成员函数不能访问非静态的变量，原因很简单，创建的时间点不一样静态成员函数生命周期长，调用静态成员函数时成员变量可能还没创建。

```c++
class Person
{
public:
    static int a;//can't initialize a here
    static const int b = 10;
public:
    void func();
    static void func1();
}
int Person::a = 5;
```

