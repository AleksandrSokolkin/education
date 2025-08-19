/*
- Расстояние Хэмминга - это расстояние между двумя строками одинаковой длины.
    Оно показывает количество отличающихся символов.
    L("abcd", "abxy") = 2

- Расстояние Левенштейна - количество редакционных ошибок между двумя строками.
    За ошибки считаются следующие действия:
      * опечатка (замена одного символа другим)
      * лишний символ (удаление символа)
      * недостающий символ (добавление символа)
    Растояние показывает, сколько нужно совершить действий над первой строкой,
      чтобы получилась вторая строка
    L("abcde", "fdf") = 4  // 2 удаления и 2 замены
*/


#include <iostream>
#include <vector>



int levenstain(const std::string& str1, const std::string& str2)
{
    /*
        Расстояние между строками "string" и "master":
        - Допустим, что нам известны следующие расстояния:
            L("strin", "maste") -> L55
            L("strin", "master") -> L56
            L("string", "maste") -> L65
        тогда, чтобы найти расстояние Левенштейна для исходных строк нужно:
        1) сравнить символы 6 обеих строк
        2) ЕСЛИ РАВНЫ, то L66 = L55
        3) ЕСЛИ НЕ РАВНЫ, то L66 = min(L55, L56, L65) + 1
    */

    std::vector<std::vector<int>> dp(str1.size() + 1,
                                     std::vector<int>(str2.size() + 1, 0));

    // Инициализация производится нулевой строки и нулевого столбца
    for (int col = 0; col <= str2.size(); ++col) {
        dp[0][col] = col;
    }
    for (int row = 0; row <= str1.size(); ++row) {
        dp[row][0] = row;
    }

    for (int row = 1; row <= str1.size(); ++row) {
        for (int col = 1; col <= str2.size(); ++col) {
            if (str1[row - 1] == str2[col - 1]) {
                dp[row][col] = dp[row - 1][col - 1];
            } else {
                dp[row][col] = std::min({dp[row][col - 1],
                                         dp[row - 1][col - 1],
                                         dp[row - 1][col]
                                        }) + 1;
            }
        }
    }

    return dp[str1.size()][str2.size()];
}



int main(int, char**)
{

    std::string str1 = "POLYNOMIAL";
    std::string str2 = "EXPONENTIAL";
    std::cout << levenstain(str1, str2);
    return 0;
}
