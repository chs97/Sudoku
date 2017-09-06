#include "check.h"
bool checkdiff(int arr[], int size) {
  bool in[20] = {0};
  for (int i = 0; i < size; i++)in[arr[i]] = true;
  for (int i = 1; i <= size; i++)if (!in[i])return false;
  return true;
}
bool checkSudoku(int grid[10][10]) {
  int xx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
  int yy[] = { 1, -1, 0, 1, -1, 1, -1, 0 };
  int temp[10];
  int cnt = 0;
  bool isSudoku = true;
  for (int i = 0; i < 9; i++) {
    cnt = 0;
    for (int j = 0; j < 9; j++) {
      temp[cnt++] = grid[j][i];
    }
    if (!checkdiff(temp, 9)) return false;
  }
  for (int i = 0; i < 9; i++) if (!checkdiff(grid[i], 9)) return false;
  for (int i = 1; i < 9; i += 3) {
    for (int j = 1; j < 9; j += 3) {
      cnt = 0;
      temp[cnt++] = grid[i][j];
      for (int k = 0; k < 8; k++) {
        temp[cnt++] = grid[i + xx[k]][j + yy[k]];
      }
      if (!checkdiff(temp, 9)) return false;
    }
  }
	return true;
}
int string2Int(string s) {
  bool flag = true;
  int result = 0;
  for (int i = 0, l = s.length(); i < l && flag; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      result *= 10;
      result += s[i] - '0';
    }
    else flag = false;
  }
  return flag ? result : -1;
}
