#include <iostream>
#include <string>
#include <vector>

#define MAX_STR_LEN		1000

using namespace std;

// focus on comp_unit
int get_compressed_length(string s, int comp_unit)
{
	string current, next, result;
	int length = s.length();
	int remain = length % comp_unit;
	int last = length - ((remain==0)?comp_unit:remain);

	int dup_count = 1;
	for(int i = 0; i < last; i += comp_unit)
	{
		current = s.substr(i, comp_unit);

		if(i == last - comp_unit && remain != 0)
		{
			next = s.substr(i+comp_unit, remain);
		}
		else
		{
			next = s.substr(i+comp_unit, comp_unit);
		}

		if(current.compare(next))
		{
			if(dup_count != 1)
				result.append(to_string(dup_count));
			result.append(current);

			if(i == last - comp_unit)
				result.append(next);

			dup_count = 1;
			continue;
		}
		else if(i == last - comp_unit)
		{
			result.append(to_string(dup_count+1));
			result.append(current);
			continue;
		}

		dup_count++;
	}

	cout << result << endl;
	return result.length();
}

int solution(string s) {
	int min_len = 987654321;

	for(int comp_unit = 1; comp_unit <= s.length()/2; comp_unit++)
	{
		min_len = min(min_len, get_compressed_length(s, comp_unit));
	}

	return min_len;
}

int main(void)
{
	string input;
	freopen("cmp_str.in", "r", stdin);

	while(getline(cin, input))
	{
		if(input.at(0) == '#')
			continue;
		cout << solution(input) << endl;
	}

	return 0;
}
