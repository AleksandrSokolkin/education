#include "collections_helper.h"
#include <iostream>
#include <vector>
#include <ranges>
#include <format>


double solve_bagpack(const std::vector<std::pair<size_t,
					 double>>& treasures,
					 size_t capacity)
{
	std::vector<std::vector<double>> dp(treasures.size() + 1,
										std::vector<double>(capacity + 1));

	for (auto i : std::ranges::views::iota(1ull, treasures.size() + 1)) {
		auto& [weight, value] = treasures[i - 1];
		for (auto j : std::ranges::views::iota(1ull, weight)) {
			dp[i][j] = dp[i - 1][j];
		}
		for (auto j : std::ranges::views::iota(weight, capacity + 1)) {
			dp[i][j] = std::max(dp[i - 1][j], value + dp[i - 1][j - weight]);
		}
	}
	return dp[treasures.size()][capacity];
}



int main(int, char**)
{
	size_t treasures_count = 0;
	std::cout << "Enter treasures count: ";
	std::cin >> treasures_count;

	std::vector<std::pair<size_t, double>> treasures;
	treasures.reserve(treasures_count);
	for (auto i : std::ranges::views::iota(0ull, treasures_count)) {
		size_t weight = 0;
		double value = 0.;
		std::cout << std::format("Enter WEIGHT and VALUE of treasure[{}]: ", i);
		std::cin >> weight >> value;
		treasures.emplace_back(weight, value);
	}

	size_t capacity = 0;
	std::cout << "Enter bag capacity: ";
	std::cin >> capacity;


	auto result = solve_bagpack(treasures, capacity);
	std::cout << "Maximum bag cost is " << result << std::endl;

	return 0;
}
