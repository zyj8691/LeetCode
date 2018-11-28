/**
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include<iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int>result;
		for (unsigned int i = 0; i < nums.size(); i++){
			for (unsigned int j = i + 1; j < nums.size(); j++){
				if (nums[i] + nums[j] == target){
					result.push_back(i);
					result.push_back(j);
					return result;
				}

			}
		}
		return result;
	}
	vector<int> twoSum_2(vector<int>& nums, int target){
		vector<int>result;
		unordered_map<int, int>record;
		for (unsigned int i = 0; i < nums.size(); i++){
			if (record.find(target - nums[i]) != record.end()){
				result.push_back(record[target - nums[i]]);
				result.push_back(i);
				return result;
			}
			else{
				record[nums[i]] = i;
			}
		}
		return result;
	}
};


int main(){
	vector<int>nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);

	Solution s;
	vector<int>result;
	result=s.twoSum_2(nums, 9);
	if (result.size()!=0)
		cout << result[0] << " " << result[1] << endl;
}