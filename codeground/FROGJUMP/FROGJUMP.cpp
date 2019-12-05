#include <iostream>
#include <cstring>
#include <cstdio>

#define num_of_stone 1000000

using namespace std;

const int INF = 987654321;
int N, K;
int stone[num_of_stone + 1];
int cache[num_of_stone + 1];

int frogjump(int cur){
	if(cur == stone[N])
		return 0;

	// on stone
	int &ret = cache[cur];
	if(ret != -1) return ret;

	ret = INF;
	for(int i = 0; i < N; i ++){
		if(cur == stone[i]){
			for(int jump = 1; jump <= K; jump ++)
				ret = min(ret, 1 + frogjump(cur + jump));
			return ret;
		}
		
		//else if(cur > stone[i])
			//break;
	}

	// not on stone
	return INF;	
}
int main(void) {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);
	for(test_case = 1; test_case <= TC; test_case++) {
		scanf("%d", &N);

		stone[0] = 0;
		for(int i = 1; i <= N; i ++)
			scanf("%d", &stone[i]);

		scanf("%d", &K);

		memset(cache, -1, sizeof(cache));

		int ret = frogjump(0);

		if(ret >= INF)
			ret = -1;
		
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		printf("%d\n", ret);

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
