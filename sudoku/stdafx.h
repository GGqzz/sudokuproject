// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include<stdlib.h>
#include<cstring>
#include<time.h>
#include <vector>  
using namespace std;
#include <stdio.h>
#include <tchar.h>


class sudoku {
	int sudokuarr[9][9];//存放数独的数组；
	int count;
public:
	sudoku() {
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				this->sudokuarr[i][j] = 0;
			}
		}
		count = 0;
	}
	void getsudoku();//生成数独终盘；
	int judgerow(int row, int col);//对行进行判断；
	int judgecol(int row, int col);//对列进行判断；
	int judgeblock(int row, int col);//对3*3方块进行判断；
	void getrand();
	void setzero(int row);
	void execute(int n);
	int judge(int row, int col);
};
// TODO: 在此处引用程序需要的其他头文件
