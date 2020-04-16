#include <iostream>
#include <string>
#include <vector>

#define MAX_STR_LEN		1000

using namespace std;

// focus on comp_unit
int get_compressed_length(string s, int comp_unit)
{
	string current, next, result;

	int orig_length = s.length();
	int remain = orig_length%comp_unit;

	// add padding
	for(int i = 0; i < comp_unit - remain; i++)
		s.append("#");

	int dup_count = 1;
	for(int i = 0; i < orig_length; i += comp_unit)
	{
		//cout << i << " " << i+comp_unit << endl;
		current = s.substr(i, comp_unit);
		next = s.substr(i+comp_unit, comp_unit);

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

	if(remain != 0)
	{
		for(int i = 0; i < comp_unit - remain; i++)
			result.pop_back();
	}

	return result.length();
}

int solution(string s) {
	int min_len = s.length();

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
		if(input.empty() || input.at(0) == '#')
			continue;

		cout << solution(input) << endl;
	}

	return 0;
}
