#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define MAX_N 1000

int N;
char room[MAX_N][MAX_N];
int check[MAX_N][MAX_N];
void reflect(int y, int x, int dir){
	if(y < 0 || y > N || x < 0 || x > N)
		return;

	if(room[y][x] == '0')
		switch(dir){
			case 0:	reflect(y+1, x, dir); break;
			case 1:	reflect(y-1, x, dir); break;
			case 2: reflect(y, x+1, dir); break;
			case 3: reflect(y, x-1, dir); break;
		}
		
	else if(room[y][x] == '1'){ // Mirror /
		check[y][x] = 1;
		switch(dir){
			case 0: reflect(y, x-1, 3); break;
			case 1: reflect(y, x+1, 2); break;
			case 2:	reflect(y-1, x, 1); break;
			case 3:	reflect(y+1, x, 0); break;
		}
	}
	else if(room[y][x] == '2'){ // Mirror reverse /
		check[y][x] = 1;
		switch(dir){
			case 0: reflect(y, x+1, 2); break;
			case 1: reflect(y, x-1, 3); break;
			case 2: reflect(y+1, x, 0); break;
			case 3: reflect(y-1, x, 1); break;
		}
	}
}
int main(){
	freopen("MIRROR_in.txt", "r", stdin);

	int TC, test_case;

	scanf("%d", &TC);
	for(test_case = 1; test_case <= TC; test_case ++){
		scanf("%d", &N);

		for(int i = 0; i < N; i ++)
			for(int j = 0; j < N; j ++)
				scanf(" %c", &room[i][j]);
		
		memset(check, 0, sizeof(check));
		reflect(0, 0, 2);
		
		int sum = 0;
		for(int i = 0; i < N; i ++)
			for(int j = 0; j < N; j ++)
				sum += check[i][j];

		printf("Case #%d\n", test_case);
		printf("%d\n", sum);
	}

	return 0;
}
