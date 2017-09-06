#pragma once
#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
class generator
{
	public:
		generator(int sn);
    int(*generateGrid(int topLine[]))[10][10];
    void generate(int n);
    void printGrid(int Grid[10][10]);
  private:
    int  (*firstLine)[10];
};

