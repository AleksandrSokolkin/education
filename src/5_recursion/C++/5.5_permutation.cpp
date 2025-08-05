#include "collections_helper.h"
#include <iostream>
#include <vector>



void permutation(std::vector<std::vector<int>>& result, std::vector<int>& nums, std::vector<int>& current, std::vector<bool>& used)
{
	if (current.size() == nums.size()) {
		result.push_back(current);
		return;
	}

	for (int i = 0; i < nums.size(); ++i) {
		if (used[i]) {
			continue;
		}

		current.push_back(nums[i]);
		used[i] = true;
		permutation(result, nums, current, used);
		current.pop_back();
		used[i] = false;
	}
}


std::vector<std::vector<int>> permutation(std::vector<int>& nums)
{
	std::vector<std::vector<int>> result;
	int size = 1;
	for (int i = 2; i <= nums.size(); ++i) {
		size *= i;
	}
	result.reserve(size);
	std::vector<int> current;
	current.reserve(nums.size());
	std::vector<bool> used(nums.size(), false);

	permutation(result, nums, current, used);

	return result;
}



static const int SIZE = 4;


int main(int, char**)
{
	std::vector<int> vec;
	vec.reserve(SIZE);
	random_init(std::back_inserter(vec), SIZE);

	auto res = permutation(vec);


	print_collection(vec);
	std::cout << "\n";
	for (auto& v : res) {
		print_collection(v);
	}

	return 0;
}