#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target)
                {
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
        return answer;
    };
};

int main(int argc, char const *argv[])
{
    Solution s;
    int a[] = {2, 7, 11, 15}, target = 9;
    vector<int> nums, r;
    for (int i = 0; i < 4; i++)
    {
        nums.push_back(a[i]);
    }
    r = s.twoSum(nums, target);
    cout << "[ ";
    for (int i = 0; i < 2; i++)
    {
        cout << r[i] << ' ';
    }
    cout << "]" << endl;
    return 0;
}
