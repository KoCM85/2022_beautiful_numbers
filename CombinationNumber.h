#ifndef COMBINATIONNUMBER_H

#define COMBINATIONNUMBER_H

/*  Info for this task
    https://habr.com/ru/post/274689/
    https://www.cyberforum.ru/combinatorics/thread1972212.html
    http://www.ega-math.narod.ru/Quant/Tickets.htm
    https://ru.stackoverflow.com/questions/1354392/%D0%9F%D0%BE%D1%81%D1%87%D0%B8%D1%82%D0%B0%D1%82%D1%8C-%D0%BA%D0%BE%D0%BB%D0%B8%D1%87%D0%B5%D1%81%D1%82%D0%B2%D0%BE-%D0%BA%D1%80%D0%B0%D1%81%D0%B8%D0%B2%D1%8B%D1%85-%D1%87%D0%B8%D1%81%D0%B5%D0%BB
*/

// First algorithm for finding beautiful numbers
class CombinationNumber {
public:
    CombinationNumber() = default;
    CombinationNumber(const CombinationNumber&) = default;
    CombinationNumber(CombinationNumber&&) = default;

    CombinationNumber& operator=(const CombinationNumber&) = default;
    CombinationNumber& operator=(CombinationNumber&&) = default;

    ~CombinationNumber() = default;


    /* Counts possible combinations of a number
        Find the number of representations of N as a sum of exactly K values not greater than M, including zeros and order-sensitive (1 + 4 and 4 + 1 are different representations).
        number - number at which possible combinations are counted
        parts_num - quantity of digits in number
        number_sys - numeration system
    */
    unsigned long long CountCombinations(const unsigned number, const unsigned parts_num, const unsigned number_sys);

    /* Calculates quantity of beautiful numbers
        parts_num - quantity of digits in number
        number_sys - numeration system
    */
    unsigned long long CountBeautyNumbers(const unsigned parts_num, const unsigned number_sys);

private:
    /* Calculates the binomial coefficient "choose{n, k}"
        n - first number for binomial coefficient
        k - second number for binomial coefficient
    */
    unsigned long long BinomialCoefficient(const unsigned n, const unsigned k);
};


// Second algorithm for finding beautiful numbers
class CombinationNumber_1 {
public:
    CombinationNumber_1() = default;
    CombinationNumber_1(const CombinationNumber_1&) = default;
    CombinationNumber_1(CombinationNumber_1&&) = default;

    CombinationNumber_1& operator=(const CombinationNumber_1&) = default;
    CombinationNumber_1& operator=(CombinationNumber_1&&) = default;

    ~CombinationNumber_1() = default;

    /* Calculates quantity of beautiful numbers
    parts_num - quantity of digits in number
    number_sys - numeration system
    */
    unsigned long long CountBeautyNumbers(unsigned parts_num, unsigned number_sys);
};

// Third algorithm for finding beautiful numbers
class CombinationNumber_2 {
public:
    CombinationNumber_2() = default;
    CombinationNumber_2(const CombinationNumber_2&) = default;
    CombinationNumber_2(CombinationNumber_2&&) = default;

    CombinationNumber_2& operator=(const CombinationNumber_2&) = default;
    CombinationNumber_2& operator=(CombinationNumber_2&&) = default;

    ~CombinationNumber_2() = default;

    /* Calculates quantity of beautiful numbers
    parts_num - quantity of digits in number
    number_sys - numeration system
    */
    unsigned long long CountBeautyNumbers(unsigned parts_num, unsigned number_sys);
};

#endif // COMBINATIONNUMBER_H