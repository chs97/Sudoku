#include "lib/check.h"
#include<time.h>  
#include <cstdio>
#include <map>
int main(int argc, char* argv[]) {
  clock_t startTime, endTime;
  startTime = clock();
  map<string, int>M;
  int grid[10][10];
  int cnt = 0;
  int tot = 0;
  char *inputFile = "Sudoku.txt";
  if (argc == 2) inputFile = argv[1];
  freopen(inputFile, "r", stdin);
  while (scanf("%d", &grid[0][0]) != EOF) {
    string s = "";
    for (int i = 1; i < 9; i++)scanf("%d", &grid[0][i]);
    for (int i = 1; i < 9; i++)
      for (int j = 0; j < 9; j++)
        scanf("%d", &grid[i][j]);
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        s += (char)(grid[i][j] + '0');
    if (!M[s]) {
      M[s] = cnt;
    } else {
      tot++;
      cnt++;
      printf("This grid already exsit\n");
      printf("grid %d is equal to grid %d\n", cnt, M[s]);
      continue;
    }
    if (!checkSudoku(grid)) {
      tot++;
      printf("Check failt in %d\n", cnt);
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          printf("%d ", grid[i][j]);
        }
        printf("\n");
      }
      printf("\n");
    }
    cnt++;
  }
  endTime = clock();
  printf("Check Success %d Failt %d\n", cnt - tot, tot);
  printf("Totle Time : %lf s.", (double)(endTime - startTime) / CLOCKS_PER_SEC);
}