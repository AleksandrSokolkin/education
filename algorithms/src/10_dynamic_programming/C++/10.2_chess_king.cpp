#include "collections_helper.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <format>


/*
король находится на клетке (1,1). Может делать либо шаг вправо, либо шаг вниз.
Сколько способов у него есть, чтобы добраться до клетка (n, m)
*/


int chess_king(int n, int m)
{
	std::vector<std::vector<int>> K{ static_cast<uint64_t>(n + 1)};
	for (auto& vec : K) {
		vec.resize(m + 1, 0);
	}

	
	K[1][1] = 1;


	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			K[i][j] += K[i - 1][j] + K[i][j - 1];
			std::cout << K[i][j] << '\t';
		}
		std::cout << std::endl;
	}

	return K[n][m];
}




int main(int, char**)
{
	int n = 20;
	int m = 10;

	auto result = chess_king(n, m);
	std::cout << std::format("There is {} ways from (1,1) to ({},{})\n", result, n, m);

	return 0;
}
