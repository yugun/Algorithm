#include <iostream>
#include <string>
#include <vector>
#include <stack>

#define MIN_LENGTH 2
#define MAX_LENGTH 1000

using namespace std;

int is_balanced_bracket(string p)
{
	int count = 0;
	for(int i = 0; i < p.length(); i++)
	{
		count += (p.at(i) == '(')?1:-1;
	}

	if(count == 0)
		return 1;

	return 0;
}

int is_correct_bracket(string p)
{
	stack<char> s;

	for(int i = 0; i < p.length(); i++)
	{
		if(p.at(i) == '(')
			s.push('(');
		else if(p.at(i) == ')')
		{
			// ')' before '('
			if(s.empty())
				return 0;

			s.pop();
		}
	}

	// '(' is more than ')'
	if(!s.empty())
		return 0;

	return 1;
}

void divide(string w, string &u, string &v)
{
	string temp;

	for(int i = 2; i < w.length(); i += 2)
	{
		temp = w.substr(0, i);
		if(is_balanced_bracket(temp))
		{
			u = temp;
			v = w.substr(i);

			return;
		}
	}

}

string solution(string w)
{
	string u, v;

	divide(w, u, v);

	cout << "w: " << w << endl;
	cout << "u: " << u << endl;
	cout << "v: " << v << endl;
	cout << endl;

	return "";
	//return w;
}

int main(void)
{
	string input;
	freopen("bracket_convert.in", "r", stdin);

	while(getline(cin, input))
	{
		cout << solution(input) << endl;
	}

	return 0;
}
