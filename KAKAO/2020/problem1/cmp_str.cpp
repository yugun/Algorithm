#include <iostream>
#include <string>
#include <vector>

#define MAX_STR_LEN		1000

using namespace std;

// focus on comp_unit
int get_compressed_length(string s, int comp_unit)
{
	string current;
	string next;
	string result;
	int str_index;

	int remain = s.length() % comp_unit;
	int last = s.length() - comp_unit - ((remain == 0)? comp_unit : remain);

	int dup_count = 1; // at least one dup!

	// only process comp_unit length
	for(int str_index = 0; str_index < last; str_index += comp_unit)
	{
		current = s.substr(str_index, comp_unit);
		next = s.substr(str_index + comp_unit, comp_unit);

		// different with next!
		if(current.compare(next))
		{
			if(dup_count != 1)
				result.append(to_string(dup_count));

			result.append(current);
			dup_count = 1;
			continue;
		}

		dup_count++;
	}

	// add leftover
	if(remain != 0 || next.compare(s.substr(str_index + comp_unit, remain)))
	{
		result.append(next);
	}
	else
	{
		result.append(to_string(dup_count+1));
		result.append(next);
	}

	cout << result << endl;

	return result.length();
}

int solution(string s) {
	int min_len = 987654321;

	for(int comp_unit = 1; comp_unit < s.length()/2; comp_unit++)
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
		cout << solution(input) << endl;
	}

	return 0;
}
