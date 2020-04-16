#include <iostream>
#include <vector>

#define MIN_NM 3
#define MAX_NM 20

using namespace std;

int N, M;

void print_vector(vector<vector<int>> vector)
{
	for(int i = 0; i < vector.size(); i++)
	{
		for(int j = 0; j < vector[i].size(); j++)
			cout << vector[i][j] << " ";
		cout << endl;
	}
}

void rotate_clockwise(vector<vector<int>> &key)
{
	vector<vector<int>> copy = key;
	int M = key.size();

	cout << "rotate!" << endl;
	for(int i = 0; i < M; i++)
		for(int j = 0; j < M; j++)
			key[j][M-i-1] = copy[i][j];
			//key[i][j] = copy[j][M-i-1];
}

bool check_opened(vector<vector<int>> &key,
					vector<vector<int>> &lock,
					int cross_y,
					int cross_x)
{
	vector<vector<int>> sum = lock;

#if 0
	// cross_y 0 ~ M
	// cross_x 0 ~ M
	int sum_range_y = min(N, cross_y + M);
	int sum_range_x = min(N, cross_x + M);

	for(int y = cross_y; y < sum_range_y; y++)
	{
		for(int x = cross_x; x < sum_range_x; x++)
		{
			sum[y][x] += key[y-cross_y][x-cross_x];
		}
	}
#else
	for(int sum_y = 0; sum_y < N; sum_y++)
	{
		for(int sum_x = 0; sum_x < N; sum_x++)
		{
			if(cross_y > sum_y)
		}
	}
#endif
	print_vector(sum);
	cout << endl;

	for(int y = 0; y < N; y++)
		for(int x = 0; x < N; x++)
			if(sum[y][x] != 1)
				return false;

	return true;
}

bool match_lock_n_key(vector<vector<int>> sum)
{
	for(int y = 0; y < N; y++)
		for(int x = 0; x < N; x++)
			if(sum[y][x] != 1)
				return false;

	return true;
}

vector<vector<int>> sum_lock_n_key(int key_y, int key_x,
									vector<vector<int>> &key,
									vector<vector<int>> &lock)
{
	vector<vector<int>> sum = lock;

	for(int lock_y = 0; lock_y < N; lock_y++)
	{
		for(int lock_x = 0; lock_x < N; lock_x++)
		{
			sum[lock_y][lock_x] += key[key_y+lock_y][key_x+lock_x];
		}
	}

	return sum;
}

bool match_lock_n_key(vector<vector<int>> &key,
				vector<vector<int>> &lock)
{
	for(int key_y = 0; key_y < M; key_y++)
	{
		for(int key_x = 0; key_x < M; key_x++)
		{
			vector<vector<int>> sum = sum_lock_n_key(key_y, key_x, key, lock);

			if(__match_lock_n_key(sum))
				return true;
		}
	}

	return false;
}

bool solution(vector<vector<int>> &key,
				vector<vector<int>> &lock)
{
	bool answer = true;
	const int MAX_ROTATE = 4;
	int open_count = 0;

	for(int r = 0; r < MAX_ROTATE; r++)
	{
		if(r != 0)
			rotate_clockwise(key);

		if(match_lock_n_key(key, lock))
			return true;

		// set cross point
		for(int y = 0; y < M; y++)
			for(int x = 0; x < M; x++)
			{
				if(check_opened(key, lock, y, x))
					return true;
			}
	}

	return false;
}

int main(void)
{
	vector<vector<int>> key;
	vector<vector<int>> lock;

#if 0
	freopen("lock_n_key.in", "r", stdin);

	while(true)
	{
		char a = cin.get();
		if(a == '[')
		{
			cout << a;
			break;
		}

		cin.get();
	}
#else
	key =
	{
		{ 0, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	};

	lock =
	{
		{ 1, 1, 1, 1 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 1 },
		{ 1, 0, 1, 1 }
	};
#endif
	M = key.size();
	N = lock.size();

	cout << solution(key, lock) << endl;

	return 0;
}
