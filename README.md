# Sudoku Generator && Sudoku Checker

数独生成器和check

## Getting Started

在windows下命令行，进入BIN文件夹，运行 Sudoku.exe -h 即可看到生成器的help
```
    Usage:
      Sudoku.exe -option <argument>
    Options:
      -c <number> [required] 生成的数量.\n");
      -o <filepath> [default Sudoku.txt] 输出文件的路径. \n");
      -s <sn> [default 031502205] 学号.");
```
在windows下命令行，进入BIN文件夹，运行 checker.exe <arguments>
arguments: filepath , 待检查的文件路径
example：
    checker.exe _soduku.txt
    checker.exe

### visual studio

打开Sudoku的Sudoku.sln 即可加载所创建的解决方案`Soduku`

## Running the tests

在VS中运行单元测试。
进行测试的方法有：
```
check: checkDiff, checkSudoku, checkString2Int
generator: 构造函数
```
