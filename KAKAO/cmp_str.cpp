#include <iostream>
#include <string>
#include <vector>

#define MAX_STR_LEN		1000

using namespace std;

// focus on comp_unit
int get_compressed_length(string s, int comp_unit)
{
	string before;
	string current;
	string result;
	int str_index;

	int dup_count = 1;
	before = s.substr(0, comp_unit);
	cout << s << endl;
	for(str_index = comp_unit; str_index <= s.length() - comp_unit; str_index += comp_unit)
	{
		current = s.substr(str_index, comp_unit);

		// different with before!
		if(current.compare(before) || str_index == s.length() - comp_unit /* last */)
		{
			if(dup_count != 1)
			{
				char count_buf[5];
				sprintf(count_buf, "%d", dup_count);
				result.append(count_buf);
			}
			result.append(before);

			before = current;
			dup_count = 1;
			continue;
		}

		dup_count++;
	}

	// add leftover
	result.append(s.substr(str_index));

	cout << comp_unit << " " << result << endl;
	return result.length();
}

int solution(string s) {
	int min_len = 987654321;

	for(int comp_unit = 1; comp_unit < s.length()/2; comp_unit++)
	{
		min_len = min(min_len, get_compressed_length(s, comp_unit));
		cout << endl;
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
