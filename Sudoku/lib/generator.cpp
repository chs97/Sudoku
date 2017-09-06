#include "generator.h"

generator::generator(int sn) {
  firstLine = new int[50000][10];
  int line[10];
  int cnt = 0;
  line[cnt ++ ] = sn;
  for (int i = 1; i <= 9; i++) {
    if (i != sn) line[cnt++] = i;
  }
  int tot = 0;
  while (next_permutation(line + 1, line + 9)) {
    for (int i = 0; i < 9; i++) firstLine[tot][i] = line[i];
    tot++;
  }
}
 int (*generator::generateGrid(int topLine[]))[10][10] {
  int (*result)[10][10] = new int [40][10][10];
  int grid[10][10];
  for (int i = 0; i < 9; i++)grid[0][i] = topLine[i];
  for (int i = 1; i < 3; i++) {
    for (int j = 0; j < 9; j++) {
     grid[i][j] = grid[i - 1][(j + 3) % 9];
    }
  }
  for (int i = 3; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      grid[i][j] = grid[i - 3][(j % 3 == 0 ? j + 2 : j - 1)];
    }
  }
  int order[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
  /*while (next_permutation(grid.begin() + 3, grid.begin() + 6)) {
    while (next_permutation(grid.begin() + 6, grid.begin() + 9)) {
      result.push_back(grid);
    }
  }*/
  int tot = 0;
  while (next_permutation(order + 3, order + 6)) {
    while (next_permutation(order + 6, order + 9)) {
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          result[tot][i][j] = grid[order[i]][j];
        }
      }
      tot++;
    }
  }
  return result;
}
void generator::generate(int n) {
  int cnt = 0;
  for (int i = 0; cnt != n; i++) {
    int(*p)[10][10];
    p = generateGrid(firstLine[i]);
    for (int j = 0; j < 25 && cnt != n; j++) {
      printGrid(p[j]);
      cnt++;
    }
  }
}
void generator::printGrid(int Grid[10][10]) {
  char map[200];
  int cnt = 0;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      map[cnt++] = (char)(Grid[i][j] + '0');
      map[cnt++] = ' ';
    }
    map[cnt++] = '\n';
  }
  map[cnt] = '\0';
  puts(map);
}
//void generator::printgrid(int grid[10][10]) {
//    char map[200];
//    int cnt = 0;
//    for (int i = 0; i < 9; i++) {
//      for (int j = 0; j < 9; j++) {
//        putchar((char)(grid[i][j] + '0'));
//        putchar(' ');
//      }
//      putchar('\n');
//    }
//    putchar('\n');
//  }