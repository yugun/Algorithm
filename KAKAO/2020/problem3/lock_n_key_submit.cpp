#include <iostream>
#include <vector>

#define MIN_NM 3
#define MAX_NM 20

using namespace std;

void rotate_clockwise(vector<vector<int>> &key)
{
	vector<vector<int>> copy = key;
	int M = key.size();

	for(int i = 0; i < M; i++)
		for(int j = 0; j < M; j++)
			key[j][M-i-1] = copy[i][j];
}

bool check_opened(vector<vector<int>> &key,
					vector<vector<int>> &lock,
					int cross_y,
					int cross_x)
{
	vector<vector<int>> sum = lock;
	int N = lock.size();
	int M = key.size();

	int sum_range_y = min(N, cross_y + M);
	int sum_range_x = min(N, cross_x + M);

	for(int y = cross_y; y < sum_range_y; y++)
		for(int x = cross_x; x < sum_range_x; x++)
			sum[y][x] += key[y-cross_y][x-cross_x];

	for(int y = 0; y < N; y++)
		for(int x = 0; x < N; x++)
			if(sum[y][x] != 1)
				return false;

	return true;
}

bool solution(vector<vector<int>> key,
				vector<vector<int>> lock)
{
	bool answer = true;
	const int MAX_ROTATE = 4;
	int N = lock.size();

	for(int i = 0 ; i < MAX_ROTATE; i++)
	{
		// set cross point
		for(int y = 0; y < N; y++)
			for(int x = 0; x < N; x++)
				if(check_opened(key, lock, y, x))
					return true;

		rotate_clockwise(key);
	}

	return false;
}
