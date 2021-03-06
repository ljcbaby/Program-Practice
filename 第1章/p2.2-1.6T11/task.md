# 表达式解释（满分100分）

程序设计中经常使用表达式，现在需要编写程序，设计算法，利用栈，计算合法表达式结果并输出。

本题中表达式由运算符`+`、`-`、`*`、`/`、`(`、`)`和正整型常量操作数复合而成，输入表达式以`#`结束。

## 操作提示

设立操作数、运算符两个栈，先将`#`加入运算符栈，读入`c`（`c`为操作符或完整操作数，如`+`或`20`，下同），只要`c`不等于`#`或运算符栈顶元素不等于`#`，则重复执行下面的循环。`c`为操作数时直接入操作数栈，再读入`c`继续循环，否则查表比较运算符栈中栈顶运算符与`c`的优先级和结合性，有大于、等于、小于三种情况，大于时从操作数栈退出操作数，从运算符栈退出一个运算符，进行相应运算后将结果入操作数栈，继续循环；等于时必定是左、右括号，操作数栈退出第一个运算符，再读入`c`，继续循环；小于时将`c`加入运算符栈，读入`c`，继续循环。循环结束后，操作数栈中只有一个栈顶元素，它就是表达式的计算结果。

## 样例输入

```text
((2+3)*6/8+9*20)#
```

## 样例输出

```text
183
```

## 要求

1. 栈要求用动态申请空间的连续线性表或链表（若用数组这种形式的连续线性表，满分90分）
2. 动态空间在程序结束前要释放，不得造成内存泄漏（10分）
3. 能实现正整数四则混合运算（80分）
4. 能实现带括号的正整数四则混合运算（90分）
