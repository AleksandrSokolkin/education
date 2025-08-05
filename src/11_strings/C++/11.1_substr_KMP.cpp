#include "collections_helper.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int substr(const std::string& str, const std::string& tmp)
{
    int tmp_size = static_cast<int>(tmp.size());
    std::vector<int> prefix(tmp.size() + str.size(), 0);
    int k = 0;

    // Рассчитываем префикс функцию для строки-шаблона
    for (int i = 1; i < tmp.size(); ++i) {
        k = prefix[i - 1];
        while (k > 0 && tmp[i] != tmp[k]) {
            k = prefix[k - 1];
        }
        prefix[i] = k + static_cast<int>(tmp[i] == tmp[k]);
    }

    // Проверяем первые символы в шаблоне и в самой строке.
    // Заполняем префикс функцию
    if (str[0] == tmp[0]) {
        prefix[tmp_size] = 1;
    }

    // Рассчитываем префикс функцию для строки
    for (int i = 1; i < str.size(); ++i) {
        k = prefix[tmp_size + i - 1];
        if (k == tmp_size) {
            k = prefix[k - 1];
        }
        while (k > 0 && str[i] != tmp[k]) {
            k = prefix[k - 1];
        }
        prefix[tmp_size + i] = k + static_cast<int>(str[i] == tmp[k]);
    }


    // Находим первое совпадение и возращаем индекс
    auto it = std::ranges::find(prefix, tmp_size);
    if (it == prefix.end()) {
        return -1;
    }

    return static_cast<int>(std::distance(prefix.begin() + tmp_size, it)
                            - (tmp_size - 1));
}



int main(int, char**)
{
    std::string str = "abaabacabadababacababa";
    std::string tmp = "abacaba";

    std::cout << substr(str, tmp) << "\n";

    return 0;
}
