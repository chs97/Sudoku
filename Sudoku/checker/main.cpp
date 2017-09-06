#include "lib/check.h"
#include <cstdio>
int main() {
  int grid[10][10];
  int cnt = 0;
  freopen("Sudoku.txt", "r", stdin);
  while (scanf("%d", &grid[0][0]) != EOF) {
    for (int i = 1; i < 9; i++)scanf("%d", &grid[0][i]);
    for (int i = 1; i < 9; i++)
      for (int j = 0; j < 9; j++)
        scanf("%d", &grid[i][j]);
    if (!checkSudoku(grid)) {
      printf("Check failt in %d\n", cnt);
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          printf("%d ", grid[i][j]);
        }
        printf("\n");
      }
      printf("\n");
    }
    cnt += checkSudoku(grid);
  }
  printf("%d\n", cnt);
}