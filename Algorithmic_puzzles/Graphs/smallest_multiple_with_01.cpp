#include <bits/stdc++.h>
using namespace std;



int string_mod(string top, int n)
{
	int r = 0;
	for(int i = 0; i < top.size(); ++i)
	{
		r = r*10 + (top[i] - '0');
		r%=n;
		//why does this work? (x*y)%n = x%n * y%n and (x+y)%n = x%n + y%n
	}
	return r;
}

string solve(int A)
{
	queue<string> q;
	q.push("1");

	unordered_set<int> mod_values;

	while(!q.empty())
	{
		string top = q.front();
		q.pop();

		int mod = string_mod(top, A);

		if(mod == 0) return top;

//We do not push string with same mod value as it is redundant

		if(mod_values.find(mod)==mod_values.end())
		{
			q.push(top + "0");
			q.push(top + "1");
			mod_values.insert(mod);
		}
	}

}


int main()
{
	int n;
	cin >> n;

	std::cout << solve(n) << "\n";
}