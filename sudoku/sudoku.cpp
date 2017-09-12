// sudokuproject.cpp: 定义控制台应用程序的入口点。
//


#include "stdafx.h"

int randomarr[9] = { 0 };
int sudoku::judgerow(int row, int col)
{
	int t = sudokuarr[row][col];
	for (int i = 0; i < col; i++)
	{

		if (t == sudokuarr[row][i])
		{
			return 0;
		}
	}
	return 1;
}
int sudoku::judgecol(int row, int col)
{
	int t = sudokuarr[row][col];
	for (int i = 0; i < row; i++)
	{

		if (t == sudokuarr[i][col])
		{
			return 0;
		}
	}
	return 1;
}
int sudoku::judgeblock(int row, int col)
{
	/*
	用一个一维数组存放九宫格的数
	如果九宫格的某个值对应的数组下标的数组元素有值，且不为
	0，那么就表示九宫格存在重复得恶数字
	*/
	int startRow = row / 3 * 3;
	int startCol = col / 3 * 3;
	int temp[10];
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			if (temp[sudokuarr[startRow + i][startCol + j]] == sudokuarr[startRow + i][startCol + j] && sudokuarr[startRow + i][startCol + j] != 0)
				return 0;
			else
				temp[sudokuarr[startRow + i][startCol + j]] = sudokuarr[startRow + i][startCol + j];
		}
	}
	return 1;
}

void sudoku::getrand()
{
	int randomrang[] = { 1,2,3,4,5,6,7,8,9 };
	random_shuffle(randomrang, randomrang + 9);
	for (int i = 0; i < 9; i++)
	{
		randomarr[i] = randomrang[i];
		//cout << randomrang[i] << " ";
	}
	count++;
	//cout << endl;
}
void sudoku::setzero(int row)
{
	for (int j = 0; j < 9; j++)
	{
		sudokuarr[row][j] = 0;
	}
}
int sudoku::judge(int row, int col)
{
	for (int i = 0; i < 9; i++)
	{
		sudokuarr[row][col] = randomarr[i];
		if (judgeblock(row, col) && judgecol(row, col) && judgerow(row, col))
		{
			return 1;
		}
	}
	return 0;
}
void sudoku::getsudoku()//生成数独终盘；
{

	int maxcount = 100;
	int row = 0;
	int col = 0;
	for (row = 0; row < 9; row++)
	{
		if (row == 0)
		{
			getrand();
			count = 0;
			for (int i = 0; i < 9; i++)
			{
				sudokuarr[row][i] = randomarr[i];
			}
		}
		else
		{
			getrand();
			for (col = 0; col < 9; col++)
			{
				if (count < maxcount)
				{
					if (!judge(row, col))
					{
						setzero(row);
						row--;
						col = 8;
						getrand();
					}
					//cout << count << " " << row << " " << col << endl;
				}
				else
				{
					row = -1;
					col = 8;
					for (int i = 0; i < 9; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							sudokuarr[i][j] = 0;
						}
					}
					count = 0;
				}
			}
		}
	}
}

void sudoku::execute(int n)
{
	ofstream mycout;
	mycout.open("../BIN/sudoku.txt");
	for (int k = 0; k < n; k++)
	{
		getsudoku();
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				mycout << sudokuarr[i][j] << " ";
			}
			mycout << endl;

		}
		mycout << endl;
	}
}
int main()
{
	int n;
	cin >> n;
	sudoku sudo;
	sudo.execute(n);
	/*for (int i = 0; i < n; i++)
	{
	sudo.getsudoku();
	sudo.print();
	cout << "This is No." << i+1 << " sudoku" << endl;

	}*/
	return 0;
}

