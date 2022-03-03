# 英文文件单词词频统计（满分100分）

对一个英文文件中所有单词的词频进行统计，并将统计结果保存到文件中。

## 输入样例

命令行下输入：

```cmd
WordCount  paper.txt  result.txt
```

## 输出样例

result.txt   （要求行列对齐）

```text
   1  sfc                     7  4.17%
   2  aov                    6  3.57%
   3  method                 3  1.79%
   4  programming            3  1.79%
   5  ld                      3  1.79%
   6  structure                3  1.79%
   7  plc                     2  1.19%
   8  vertex                  2  1.19%
   9  proposed                2  1.19%
  10  one                    2  1.19%
  11  element                2  1.19%
  12  by                     2  1.19%
  13  transformation           2  1.19%
  14  algorithm               2  1.19%
  15  paper                  1  0.60%
  16  presents               1  0.60%
  17  transform              1  0.60%
  18  sequential             1  0.60%
  19  function               1  0.60%
total word count=68
```

## 要求

1. 单词表使用单链表（若用数组，得0分）
2. 链表空间在程序结束前要删除，不得造成内存泄漏（10分）
3. 按单词出现次数从高到低排序（20分）
4. 能正确统计不同单词及其出现的次数，忽略大小写 （50分）
5. 能过滤掉停用词（10分）
6. 能输出链表内容到输出文件，格式规范 （5分）
7. 能用命令行参数形式（5分）
