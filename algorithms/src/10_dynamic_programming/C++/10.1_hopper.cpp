#include "collections_helper.h"
#include <iostream>
#include <vector>


// Кузнечик находится на позиции 1
// Ему нужно допрыгать до позиции N (вводит пользователь)

// прыгать можно либо на 1, либо на 2
// Каждая позиция имеет свою цену
// Найти минимальную стоимость пути до N-й позиции.

//   -----------------------------
//   1        ...        N
//   p1       ...        pN




int minimum_cost(int endPosition, std::vector<int>& prices)
{
	std::vector<int> costs(prices.size(), 0);
	costs[0] = prices[0];
	costs[1] = prices[1];

	for (int i = 2; i <= endPosition; ++i) {
		costs[i] = std::min(costs[i - 1], costs[i - 2]) + prices[i];
	}

	return costs[endPosition];
}



int main(int, char**)
{
	std::cout << "Enter end position for hopper [1, 100]:\n> ";
	
	int endPosition = 0;
	std::cin >> endPosition;

	if (endPosition < 1 || endPosition > 100) {
		std::cerr << "Wrong value for end position!\n";
		return 1;
	}

	std::vector<int> prices;
	prices.reserve(endPosition + 1);
	random_init(std::back_inserter(prices), endPosition + 1);
	prices[0] = prices[1] + 1;
	std::cout << "\nRandom prices:\n";
	print_collection(prices);

	std::cout << "Minimum cost way = " << minimum_cost(endPosition, prices) << "\n";

	return 0;
}
