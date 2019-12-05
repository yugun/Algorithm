#include <cstdio>
#include <iostream>

#define MAX_N 100
using namespace std;

int N;
int x1[MAX_N], y1[MAX_N], x2[MAX_N], y2[MAX_N];

double getBattery(int x, int y){
	int ret = 987654321;
	
	ret = min(ret,  

}

int main(int argc, char** argv) {
	freopen("BATTERY_in.txt", "r", stdin);
	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);
	for(test_case = 1; test_case <= TC; test_case++) {
		scanf("%d", &N);
		for(int i = 0; i < N; i ++)
			scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);

		int ret = 0;
		for(int i = 0; i < N; i ++)

				


		printf("Case #%d\n", test_case);

	}

	return 0;
}
