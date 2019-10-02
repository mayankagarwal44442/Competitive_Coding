#include <bits/stdc++.h>
using namespace std;

//ver2

//Approach: Unlike v1, we dont store strings. We just store mod values. But we also need to rebuild the solution and for that 
//we store parents and the digits used to bring to that

//Complexity - O(n)

string solve(int A)
{
	if(A==0) return "0";
	if(A==1) return "1";

	queue<int> q;
	bool visited[A]; //visited array
	int parent[A]; //to store parents
	int digit[A]; //to store which digit was used to come to the child. 
	
	q.push(1);
	visited[1] = true;
	parent[1] = -1;
	digit[1] = 1;  // 1


	while(!q.empty())
	{
		int top = q.front();
		q.pop();

		if(top == 0) break;

		int mod1 = (top*10)%A;
		int mod2 = (mod1 + 1)%A;   //since you are appending 1 instead of 0

		if(!visited[mod1])
		{
			visited[mod1] = true;
			parent[mod1] = top;
			digit[mod1] = 0;
			q.push(mod1);
		}

		if(!visited[mod2])
		{
			visited[mod2] = true;
			parent[mod2] = top;
			digit[mod2] = 1;
			q.push(mod2);
		}

	}

	int i = 0;
	string res = "";
	while(i!=1)
	{
		
		if(digit[i]) res += "1";
		else res += "0";
		i = parent[i];
	}
	res = res + "1";
	reverse(res.begin(),res.end());
	return res;


}


/*ver1
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
*/

int main()
{
	int n;
	cin >> n;

	std::cout << solve(n) << "\n";
}

