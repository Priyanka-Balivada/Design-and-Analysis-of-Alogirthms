#include <iostream>
#include <cstring>
using namespace std;

int size_of_grid, b, a, count = 0;
int arr[256][256];

void mark(int x1, int y1, int x2,int y2, int x3, int y3)
{
	count++;
	arr[x1][y1] = count;
	arr[x2][y2] = count;
	arr[x3][y3] = count;
}

int tiling(int n, int x, int y)
{
	int row, col;
	if (n == 2) {
		count++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[x + i][y + j] == 0) {
					arr[x + i][y + j] = count;
				}
			}
		}
		return 0;
	}
	
	// finding hole 
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j] != 0)
				row = i, col = j;
		}
	}

	// 1st quadrant
	if (row < x + n / 2 && col < y + n / 2)
		mark(x + n / 2, y + (n / 2) - 1, x + n / 2,y + n / 2, x + n / 2 - 1, y + n / 2);

	// 3rd quadrant
	else if (row >= x + n / 2 && col < y + n / 2)
		mark(x + (n / 2) - 1, y + (n / 2), x + (n / 2),y + n / 2, x + (n / 2) - 1, y + (n / 2) - 1);

	// 2nd quadrant
	else if (row < x + n / 2 && col >= y + n / 2)
		mark(x + n / 2, y + (n / 2) - 1, x + n / 2,y + n / 2, x + n / 2 - 1, y + n / 2 - 1);

	// 4th quadrant
	else if (row >= x + n / 2 && col >= y + n / 2)
		mark(x + (n / 2) - 1, y + (n / 2), x + (n / 2),y + (n / 2) - 1, x + (n / 2) - 1,y + (n / 2) - 1);

	tiling(n / 2, x, y + n / 2);
	tiling(n / 2, x, y);
	tiling(n / 2, x + n / 2, y);
	tiling(n / 2, x + n / 2, y + n / 2);

	return 0;
}

int main()
{
	//3 6 7 12
	//2 4 5 8 9 10 11
	size_of_grid = 8;
	memset(arr, 0, sizeof(arr));
	
	a = 0, b = 0;
	arr[a][b] = -1;
	tiling(size_of_grid, 0, 0);
	
	// grid 
	for (int i = 0; i < size_of_grid; i++) {
		for (int j = 0; j < size_of_grid; j++)
			cout << arr[i][j] << " \t";
		cout << "\n\n";
	}
}

