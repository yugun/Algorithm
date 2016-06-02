#include <iostream>
#include <cstdio>
#include <cstring>

#define MAP_WIDTH	5
#define MAP_HEIGHT	12
#define MAX_SCORE	MAP_HEIGHT
#define GAME_REGION	5
#define NEGINF		-987654321

using namespace std;

int N;
int map[MAP_HEIGHT][MAP_WIDTH];
int temp[MAP_HEIGHT][MAP_WIDTH];
int cache[MAP_HEIGHT][MAP_WIDTH][MAX_SCORE];
const int SCORES[3] = { 0, 1, -1 };
const int dx[3] = { -1, 0, 1 };
FILE *fTemp = fopen("PLANE_temp2.txt", "w");

void boom(int y){
	for(int i = y-1; i >= y-GAME_REGION && i >= 0; i --)
		for(int j = 0; j < MAP_WIDTH; j ++)
			if(map[i][j] == 2)
				map[i][j] = 0;
}

int move(int y, int x, int prevScore){
//	fprintf(fTemp, "(%d, %d, %d)\n", y, x, prevScore);
	int curScore = prevScore + ((y == N)? 0 : SCORES[map[y][x]]);
	if(curScore == -1) return -1;
	if(y == 0) return curScore;

	int &ret = cache[y-1][x][prevScore];
	if(ret != NEGINF) return ret;
	
	int ret = -1;
	for(int i = 0; i < 3; i ++){
		if(x == 0 && dx[i] == -1) continue;
		if(x == MAP_WIDTH-1 && dx[i] == 1) continue;

		ret = max(ret, move(y-1, x+dx[i], curScore));
	}
	return ret;
}
void printMap(){
	for(int i = 0; i < MAP_HEIGHT; i ++){
		for(int j = 0; j < MAP_WIDTH; j ++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
}
void fprintMap(FILE *fp){
	for(int i = 0; i < N; i ++){
		for(int j = 0; j < MAP_WIDTH; j ++)
			fprintf(fp, "%d ", map[i][j]);
		fprintf(fp, "\n");
	}
}
/*
void printCache(){
	for(int i = 0; i < MAP_HEIGHT; i ++){
		for(int j = 0; j < MAP_WIDTH; j ++)
			printf("%10d ", cache[i][j]);
		printf("\n");
	}
}
void fprintCache(FILE *fp){
	for(int i = 0; i < MAP_HEIGHT; i ++){
		for(int j = 0; j < MAP_WIDTH; j ++)
			fprintf(fp, "%d ", cache[i][j]);
		fprintf(fp, "\n");
	}
}
*/
void clearCache(){
	for(int i = 0; i < MAP_HEIGHT; i ++)
		for(int j = 0; j < MAP_WIDTH; j ++)
			for(int k = 0; k < MAX_SCORE; k ++)
				cache[i][j][k] = NEGINF;
}

int main(){
	freopen("PLANE_in.txt", "r", stdin);
	//freopen("PLANE_out.txt", "w", stdout);
	FILE *fp = fopen("PLANE_out.txt", "w");
//	FILE *fp1 = fopen("diff1.txt", "w");
//	FILE *fp2 = fopen("diff2.txt", "w");

	int TC;
	scanf("%d", &TC);

	for(int test_cases = 1; test_cases <= TC; test_cases ++){
		scanf("%d", &N);
		for(int i = 0; i < N; i ++)
			for(int j = 0; j < MAP_WIDTH; j ++)
				scanf("%d", &map[i][j]);
		memcpy(temp, map, sizeof(map));

		clock_t start = clock();
		int ret = -1;
		for(int i = N; i >= GAME_REGION; i --){
			boom(i);
			clearCache();
			ret = max(ret, move(N, MAP_WIDTH/2, 0));
			memcpy(map, temp, sizeof(temp)); // recover boom(i)
		}
		clock_t end = clock();
		
		printf("#%d %d\n", test_cases, ret);
		printf("%lf\n", (double)(end-start)/CLOCKS_PER_SEC);
		fprintf(fp, "#%d %d\n", test_cases, ret);
	}
	return 0;
}
