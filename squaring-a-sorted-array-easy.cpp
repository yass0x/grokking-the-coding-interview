using namespace std;
#include <iostream> 
#include <vector>

class Solution {
public:

  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);
    // TODO: Write your code here
    int leftIdx = 0;
    int rightIdx = n-1;
    int i = n-1;
    while (leftIdx < rightIdx)
    {
        if(arr[leftIdx] * arr[leftIdx] > arr[rightIdx] * arr[rightIdx])
        {
            squares[i] = arr[leftIdx] * arr[leftIdx];
            i--;
            leftIdx++;
        }
        else if(arr[leftIdx] * arr[leftIdx] < arr[rightIdx] * arr[rightIdx])
        {
            squares[i] = arr[rightIdx] * arr[rightIdx];
            i--;
            rightIdx--;            
        }
        else
        {
            squares[i] = arr[rightIdx] * arr[rightIdx];
            squares[i-1] = arr[leftIdx] * arr[leftIdx];
            i -=2;
            rightIdx--;
            leftIdx++;              
        }
    }
    squares[0] = arr[rightIdx] * arr[rightIdx];
    
    return squares;
  }
};

int main() {
    Solution sol;

    std::vector<int> input1 = { -2, -1, 0, 2, 3 };
    std::vector<int> result1 = sol.makeSquares(input1);
    for (int num : result1)
        std::cout << num << " ";
    std::cout << std::endl;

    std::vector<int> input2 = {-3, -2, -1  };
    std::vector<int> result2 = sol.makeSquares(input2);
    for (int num : result2)
        std::cout << num << " ";
    std::cout << std::endl;


    return 0;
}
