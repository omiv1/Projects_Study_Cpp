#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int p = nums.size();
        int index;
        int l=0;
        while(l<=p)
        {
            index = (l+p)/2;
            if(nums[index] == target)
            {
                return index;
            } else
            {
                if(nums[index]>target)
                {
                    p = index-1;
                } else
                {
                    l = index+1;
                }
            }
            //cout<<l<<" "<<p<<endl;
            if(index < 0) return 0;
            if(target > nums[nums.size()-1]) return nums.size();

        }
        return l;
    }
};

int main() {
    Solution x;
    vector<int> tab = {1,3};
    cout<<x.searchInsert(tab,2);

}
