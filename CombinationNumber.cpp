#include <stdexcept>
#include <vector>
#include <cmath>

#include "CombinationNumber.h"


// CombinationNumber
unsigned long long CombinationNumber::CountCombinations(const unsigned number, const unsigned parts_num, const unsigned number_sys) {
    int coef = -1;
    unsigned long long sum = 0;

    for (unsigned i = 0, e = number / number_sys; i <= e; ++i) {
        coef *= -1;
        sum += coef * BinomialCoefficient(parts_num, i) * BinomialCoefficient(number - i * number_sys + parts_num - 1, parts_num - 1);
    }

    return sum;
}

unsigned long long CombinationNumber::CountBeautyNumbers(const unsigned parts_num, const unsigned number_sys) {
    unsigned long long result = 0;
    unsigned long long count;
    const unsigned half_num = parts_num / 2;
    const unsigned max_num = number_sys - 1;
    const unsigned max_sum = max_num * half_num;

    if (parts_num < 2 || !number_sys)
        throw std::runtime_error("Wrong data");

    for (unsigned i = 0; i <= max_sum; ++i) {
        count = CountCombinations(i, half_num, number_sys);
        result += count * count;
    }

    if (parts_num % 2) {
        result *= number_sys;
    }

    return result;
}

unsigned long long CombinationNumber::BinomialCoefficient(const unsigned n, const unsigned k) {
    unsigned long long result;

    if (k == 0 || n == k)
        result = 1;
    else if (k > n)
        result = 0;
    else if (k == 1)
        result = n;
    else {
        result = 1;

        for (unsigned i = 1; i <= k; ++i) {
            result *= (n - (k - i));
            result /= i;
        }
    }

    return result;
}


// CombinationNumber_1
unsigned long long CombinationNumber_1::CountBeautyNumbers(unsigned parts_num, unsigned number_sys) {
    bool is_multiple = true;

    if (parts_num < 2 || !number_sys)
        throw std::runtime_error("Wrong data");

    if (parts_num % 2) {
        --parts_num;
        is_multiple = false;
    }

    auto lambda = [](unsigned parts_num_, unsigned k, unsigned number_sys, auto&& lambda) {
        if (parts_num_ == 1)
            return static_cast<unsigned long long>(k < number_sys);

        unsigned long long combinations = 0;

        for (unsigned i = 0; i < number_sys; ++i)
            combinations += lambda(parts_num_ - 1, k - i, number_sys, lambda);

        return combinations;
    };

    unsigned long long result = 0;

    for (unsigned int k = 0; k <= (number_sys - 1) * parts_num / 2; ++k) {
        auto combinations = lambda(parts_num / 2, k, number_sys, lambda);
        result += combinations * combinations;
    }

    if (!is_multiple)
        result *= number_sys;

    return result;
}


// CombinationNumber_2
unsigned long long CombinationNumber_2::CountBeautyNumbers(unsigned parts_num, unsigned number_sys) {
    unsigned long long result = 0;
    const unsigned half = parts_num / 2;
    const unsigned max_num = number_sys - 1;
    const unsigned max_sum = half * max_num;
    const size_t data_size = max_sum + 1;
    std::vector<unsigned long long> data(data_size);

    if (parts_num < 2 || !number_sys)
        throw std::runtime_error("Wrong data");

    auto calc_data = [&data, &number_sys](unsigned parts_num, unsigned index, auto&& lambda) {
        if (!parts_num) {
            ++data[index];

            return;
        }
        else {
            for (unsigned i = 0; i < number_sys; ++i) {
                lambda(parts_num - 1, index + i, lambda);
            }
        }
    };

    calc_data(half, 0, calc_data);

    for (unsigned i = 0; i < data.size(); ++i) {
        result += data[i] * data[i];
    }

    if (parts_num % 2)
        result *= number_sys;

    return result;
}