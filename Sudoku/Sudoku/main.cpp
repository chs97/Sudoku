#pragma once
#include<time.h>  
#include <map>
#include <cstring>

#include "lib/check.h"
#include "lib/generator.h"
#include "lib/check.h"


int main(int argc, char* argv[]) {
  map<string, string> params;
  params["-s"] = "05";
  params["-o"] = "Sudoku.txt";
  bool isHelp = false;
  for (int i = 1; i < argc; i+= 2) {
    if (strcmp("-h", argv[i]) == 0) {
      isHelp = true;
      continue;
    }
    if (i >= argc) break;
    params[argv[i]] = argv[i + 1];
  }
  if (isHelp) {
    printf("Sudoku generator help\n");
    printf("Usage:\n");
    printf("  Sudoku.exe -option <argument>\n");
    printf("Options:\n");
    printf("  -c <number> [required] The number of generated.\n");
    printf("  -o <filepath> [default Sudoku.txt] The output file path. \n");
    printf("  -s <sn> [default 031502205] Student number.");
    exit(0);
  }
  int num = string2Int(params["-c"]);
  if (!(num > 0 && num <= 1000000)) {
    printf("parameter error.\n");
    printf("the number must be large than 0 and less than 10000.");
    exit(1);
  }
  clock_t startTime, endTime;
  startTime = clock();
  freopen(params["-o"].c_str(), "w", stdout);
  generator gn(5);
  gn.generate(num);
  fclose(stdout);
  freopen("CON", "w", stdout);
  endTime = clock();
  cout << "Generated completed." << endl;
  cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}