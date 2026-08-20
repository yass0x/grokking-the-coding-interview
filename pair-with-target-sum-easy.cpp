# include <iostream>
#include <vector>
using namespace std;
class Solution
{
	public:

	static std::vector<int> search(const vector<int> &arr, int targetSum) {
	// TODO: Write your code here
	int leftIdx = 0;
	int rightIdx = arr.size() -1;
	 while (leftIdx < rightIdx)
	 {
		 if (arr[leftIdx] + arr[rightIdx] == targetSum)
		 {
			 return std::vector<int> (arr[leftIdx], arr[rightIdx]);
		 }
		 else if (arr[leftIdx] + arr[rightIdx] > targetSum)
		 {
			rightIdx --;
		 }
		 else
		 {
			 leftIdx ++;
		 }
	 }
	return std::vector<int> (-1, -1);
  }
};

int main ()
{
	Solution sol;

	std::cout << "OUTPUT: " << sol.search(vector<int>{1, 2, 3, 4, 6}, 6); << std::endl;


}
