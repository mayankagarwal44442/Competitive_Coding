#include <bits/stdc++.h>
using namespace std;


std::vector<pair<int,int>> dir = {{1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}}; 

bool dfs(int x, int y, int A, int B, bool ** traversable)
{
	traversable = bool(*traversable)[B+1];
	if(x == A && y == B) return true;

	bool res = false;

	for(int i = 0; i < 8; ++i)
	{
		int new_x = x + dir[i].first;
		int new_y = y + dir[i].second;

		if(new_x >= 0 && new_y >=0 && new_x <= A && new_y <= B && traversable[new_x][new_y])
		{
			traversable[new_x][new_y] = false;
			res = res | dfs(new_x, new_y, A, B, traversable);
			if(res) break;
		}
	}
	return res;
}

std::string solve(int A, int B, int C, int D, std::vector<int> &E, std::vector<int> &F)
{
	bool traversable[A+1][B+1];
	memset(traversable, true, sizeof(traversable));

	for(int i = 0; i < C; ++i)
	{
		for(int j = std::max(0,E[i]-D); j <= std::min(A, E[i]+D); ++j)
		{
			for(int k = std::max(0,F[i]-D); k <= std::min(B, F[i]+D); ++k)
			{
				if(traversable[j][k] && (sqrt(pow(j-E[i],2) + pow(k-F[i],2))<=D))
				{
					traversable[j][k] = false;
				}
			}
		}
	}

	//traversable can be used as visited matrix.

	if(dfs(0,0,A,B,traversable)) return "YES";
	return "NO";	

}


int main()
{
	int x,y,n,r;
	std::cin >> x >> y >> n >> r;

	std::vector<int> A(n);
	std::vector<int> B(n);

	for(int i = 0; i < n; ++i) std::cin >> A[i];
	for(int i = 0; i < n; ++i) std::cin >> B[i];


	std::cout << solve(x,y,n,r,A,B) << "\n";
}