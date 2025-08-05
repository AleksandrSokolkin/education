#include "collections_helper.h"
#include <iostream>



void makeStrWwithBracesImpl(std::vector<std::string>& result,
                            std::string currentBraces,
                            int openBracesRemain,
                            int closeBracesRemain)
{
    if (!openBracesRemain && !closeBracesRemain) {
        result.push_back(std::move(currentBraces));
        return;
    }

    if (openBracesRemain) {
        makeStrWwithBracesImpl(result,
                               currentBraces + '(',
                               openBracesRemain - 1,
                               closeBracesRemain);
    }

    if (openBracesRemain < closeBracesRemain) {
        makeStrWwithBracesImpl(result,
                               currentBraces + ')',
                               openBracesRemain,
                               closeBracesRemain - 1);
    }
}


std::vector<std::string> makeStrWwithBraces(int bracesPairsCount)
{
    std::vector<std::string> result;
    std::string currentBraces;
    makeStrWwithBracesImpl(result,
                           currentBraces,
                           bracesPairsCount,
                           bracesPairsCount);
    return result;
}



int main(int, char**)
{
    int bracesPairsCount = 0;
    std::cin >> bracesPairsCount;

    auto braces = makeStrWwithBraces(bracesPairsCount);
    print_collection(braces);

    return 0;
}


