#include <iostream>

#include "CombinationNumber.h"

int main(int argc, char* argv[]) {
    const unsigned parts_num = 4;
    const unsigned number_sys = 6;
    unsigned algo_res_1;
    unsigned algo_res_2;
    unsigned algo_res_3;

    CombinationNumber beaty_number;
    CombinationNumber_1 beaty_number_1;
    CombinationNumber_2 beaty_number_2;

    algo_res_1 = beaty_number.CountBeautyNumbers(parts_num, number_sys);
    algo_res_2 = beaty_number_1.CountBeautyNumbers(parts_num, number_sys);
    algo_res_3 = beaty_number_2.CountBeautyNumbers(parts_num, number_sys);

    std::cout << "Algo 1: " << algo_res_1 << '\n';

    try {
        std::cout << "Algo 2: " << algo_res_2 << '\n';
    }
    catch (std::runtime_error& except) {
        std::cout << except.what() << "\n";
    }

    std::cout << "Algo 3: " << algo_res_3 << '\n';

    if (algo_res_1 == algo_res_2 && algo_res_1 == algo_res_3)
        std::cout << "results equal \n";
    else
        std::cout << "results not equal \n";

    std::cout << '\n';

    std::cout << beaty_number.CountCombinations(2, 8, 3) << '\n';   // 36
    std::cout << beaty_number.CountCombinations(3, 8, 4) << '\n';   // 120
    std::cout << beaty_number.CountCombinations(4, 8, 5) << '\n';   // 330
    std::cout << beaty_number.CountCombinations(5, 8, 6) << '\n';   // 792
    std::cout << beaty_number.CountCombinations(6, 8, 7) << '\n';   // 1716
    std::cout << beaty_number.CountCombinations(7, 8, 8) << '\n';   // 3432
    std::cout << beaty_number.CountCombinations(8, 8, 9) << '\n';   // 6435
    std::cout << beaty_number.CountCombinations(9, 8, 10) << '\n';  // 11440
    std::cout << beaty_number.CountCombinations(10, 8, 11) << '\n'; // 19448
    std::cout << beaty_number.CountCombinations(11, 8, 12) << '\n'; // 31824
    std::cout << beaty_number.CountCombinations(12, 8, 13) << '\n'; // 50388

    return 0;
}