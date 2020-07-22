#include <iostream>
#include <iomanip>
//#include <cmath>

using namespace std;
bool aug = false;
int rows;
int cols;
int columns;





int main()
{
	cout << "Hello this is only for finding the inverse of a matrix, should it exist, only (n x n)!" << endl;
	cout << "Please enter the number of rows, and thus columns that you would like to have:" << endl;
	cout << "Remember it is an n x n matrix, so only one input is needed." << endl;
	cin >> rows;
	cols = rows;
	cout << "Your matrix has " << rows << " rows, and " << cols << " columns!" << endl;
	columns = cols * 2;
	double number[rows][columns];
	for(int i = 0; i <rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			cout << "For row " << i+1 << " please enter the number in place " << j+1 << endl;
			cin >> number[i][j];
		}
		for(int j = cols;j<columns;j++)
		{
			int placer = j - cols;
			//cout << placer << endl;
			if(placer == i)
			{
				number[i][j] = 1;
			}
			else
			{
				number[i][j] = 0;
			}
		}
	}
	cout << "Here is your inputted matrix:" << endl;
	for(int i = 0; i <rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				if(j == cols)
				{
					cout << " || " << number[i][j];
				}
				else if(j == cols - 1)
				{
					cout << "    " << number[i][j] << endl;
				}
				else
				{
					cout << "    " << number[i][j];
				}
			}
		}
	double determinant;
	if(rows > 3)
	{
		cout << "This program can only determine the determinant for a 2x2 and 3x3 matrix, higher than that," << endl;
		cout << "the program will just compute an inverse, be careful at those higher levels, there may actually be no inverse." << endl;
	}
	if(rows == 2)
	{
		determinant = (number[0][0] * number[1][1]) - (number[0][1] * number[1][0]);
		if(determinant == 0)
		{
			cout << "There is no inverse matrix, the determinant = 0" << endl;
			return 0;
		}
	}
	else if(rows == 3)
	{
		determinant = (number[0][0] * ((number[1][1] * number[2][2]) - (number[1][2] * number[2][1])));
		determinant = determinant - (number[0][1] * ((number[1][0] * number[2][2]) - (number[1][2] * number[2][0])));
		determinant = determinant + (number[0][2] * ((number[1][0] * number[2][1]) - (number[1][1] * number[2][0])));
		if(determinant == 0)
		{
			cout << "There is no inverse matrix, the determinant = 0." << endl;
			return 0;
		}
	}



	int totnums[rows];
	for(int i = 0; i< rows; i++)
	{
		int counter1 = 0;
		for(int j = 0; j<cols; j++)
		{
			if(number[i][j] == 0)
			{
				counter1 = counter1 + 1;
			}
			else
			{
				break;
			}
		}
		totnums[i] = counter1;
	}
	int countere = 0;
	int counter2;
	bool truth = true;
	while(truth == true)
	{
		counter2 = 0;
		for(int i = 0; i<rows-1; i++)
		{
			if(totnums[i] > totnums[i+1])
			{
				counter2 = counter2 + 1;
				double temp1[cols];
				double temp2[cols];
				int temp3, temp4;
				for(int j = 0; j<cols;j++)
				{
					temp1[j] = number[i][j];
					temp2[j] = number[i+1][j];
					temp3 = totnums[i];
					temp4 = totnums[i+1];
				}
				for(int t = 0; t<cols;t++)
				{
					number[i][t] = temp2[t];
					number[i+1][t] = temp1[t];
					totnums[i] = temp4;
					totnums[i+1] = temp3;
				}

			}
		}
		if(counter2 > 0)
		{
			truth = true;
		}
		else
		{
			truth = false;
		}
		countere = countere+1;
	}
		int place;
			for(int i = 0; i<rows;i++)
			{
				for(int j = 0; j< cols; j++)
				{
					if(number[i][j] != 0)
					{
						place = j;
						break;
					}
				}
				int size = rows - 1;
				size = size - i;
				double tempop1[size][columns];
				double tempop2[columns];
				double tempop3[columns];
				for(int t = 0;t<size;t++)
				{
					for(int r = 0;r<columns;r++)
					{
						tempop1[t][r] = number[t+i+1][r];
					}
				}
				for(int t=0;t<columns;t++)
				{
					tempop2[t] = number[i][t];
				}
				double mult1,mult2,mult3;
				mult1 = tempop2[place];
				for(int y=0;y<size;y++)
				{
					mult2 = tempop1[y][place]; //This should be mult1(x) + mult2 = 0
					mult3 = -1 * mult2;
					mult3 = mult3 / mult1;
					for(int g = 0; g<columns;g++) // this might need to be from g=place, if this is the case you need to change parts above
					{
						tempop3[g] = tempop2[g] * mult3;
					}
					for(int v = 0; v<columns;v++)
					{
						tempop1[y][v] = tempop1[y][v] + tempop3[v];
					}
				}
				for(int g=0;g<size;g++)
				{
					for(int b=0;b<columns;b++)
					{
						number[g+i+1][b] = tempop1[g][b];
					}
				}
			}
		int place2;
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				if(number[i][j] != 0)
				{
					place2 = j;
					break;
				}
			}
			double temporar[columns];
			for(int h = 0; h < columns; h++)
			{
				temporar[h] = number[i][h];
			}
			double divisor = temporar[place2];
			if(divisor == 0)
			{
				break;
			}
			for(int u = 0; u < columns; u++)
			{
				double tnum = temporar[u];
				tnum = tnum / divisor;
				temporar[u] = tnum;
			}
			for(int t = 0; t<columns;t++)
			{
				number[i][t] = temporar[t];
			}
		}
		for(int i = 0; i <rows; i++)
				{
					for(int j = 0; j < columns; j++)
					{
						if(number[i][j] <0.00000000000000000000005 && number[i][j] > -0.00000000000000000000005)
						{
							number[i][j] = 0;
						}
					}
				}
		int place3;
			for(int i = rows-1;i>0;i--)
			{
				int counterer=0;
					for(int j = 0; j<cols;j++)
					{
						if(number[i][j] != 0)
						{
							place3 = j;
							break;
						}
						else
						{
							counterer = counterer + 1;
						}
					}
					if(counterer != cols)
					{
				double temparr1[i][columns];
				double temparr2[columns];
				for(int t=0; t<i;t++)
				{
					for(int h = 0; h < columns; h++)
					{
						temparr1[t][h] = number[t][h];
					}
				}
				for(int r = 0; r<columns;r++)
				{
					temparr2[r] = number[i][r];
				}
				for(int e=0;e<i;e++)
				{
					double temparr3[columns];
					double num1,num2,num3;
					num1 = temparr2[place3];
					num2 = temparr1[e][place3];
					num3 = -num2/num1;
					for(int r = 0; r<columns;r++)
					{
						temparr3[r] = num3 * temparr2[r];
					}
					for(int w = 0; w<columns; w++)
					{
						temparr1[e][w] = temparr1[e][w] + temparr3[w];
					}

				}
				for(int t=0;t<i;t++)
				{
					for(int a =0; a<columns;a++)
					{
						number[t][a]= temparr1[t][a];
					}
				}
					}
			}
			cout << "Here is your inverse matrix:" << endl;
			cout << "The '|' just simply shows a seperation from place in the matrix:" << endl;
			for(int i = 0; i <rows; i++)
			{
				for(int j = cols; j < columns; j++)
				{
					if(j == columns - 1)
					{
						cout << "  |  " << number[i][j] << endl;
					}
					else if(j == cols)
					{
						cout << number[i][j];
					}
					else
					{
						cout << "  |  " << number[i][j];
					}
				}
			}
			cout << "If there is a bunch of 'nan', that means the matrix was not invertible." << endl;
}
