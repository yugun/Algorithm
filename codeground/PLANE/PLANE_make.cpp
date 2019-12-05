#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAP_WIDTH 5
using namespace std;

int main(){
	freopen("PLANE_in.txt", "w", stdout);
	srand(time(NULL));

	int TC = 10;
	printf("%d\n", TC);

	for(int i = 0; i < TC; i ++){
		int N = rand()%8 + 5;
		printf("%d\n", N);

		for(int j = 0; j < N; j ++){
			for(int k = 0; k < MAP_WIDTH; k ++)
				printf("%d ", rand()%3);
			printf("\n");
		}
	}

	return 0;
}
