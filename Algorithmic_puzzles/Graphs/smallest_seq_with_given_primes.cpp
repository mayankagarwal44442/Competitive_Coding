#include <set>
#include <vector>
#include <iostream>

class Solution
{
public:
    std::vector<int> solve(int,int,int,int);
};

std::vector<int> Solution::solve(int A, int B, int C, int D) {
    std::set<int> numbers;  
    //using sets for two reason - no duplicates and sorted.
    std::vector<int> sol;
    //solution vector

    numbers.insert(A);
    numbers.insert(B);
    numbers.insert(C);

    int count = 0;
    
//note that we have to find out first k numbers who have A,B or C as prime factors. That implies all the 
//number's factors are some multiple of A,B,C. Thus produce all combination of multiples.  
//But, 3*k multiplication has to be done, because correct order can only be guaranteed if 
//all multiples are inserted for them.
    while(count < D)
    {
        int smallest_ele = *numbers.begin();
        numbers.insert(smallest_ele*A);
        numbers.insert(smallest_ele*B);
        numbers.insert(smallest_ele*C);
        sol.push_back(smallest_ele);
        numbers.erase(numbers.begin());
        count++;
    }

    return sol;
}


int main()
{
    Solution s;
    std::vector<int> sol = s.solve(3,11,7,20);
    for(int ele:sol) std::cout << ele << " "; std::cout << "\n";
}