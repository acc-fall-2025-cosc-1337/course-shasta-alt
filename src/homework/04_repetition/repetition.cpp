#include "repetition.h"
#include <vector>

int get_factorial(int n)
{
    // Assume caller validated 1 <= n <= 9
    int result = 1;

    // Range-based for loop over a generated sequence 1..n
    std::vector<int> seq;
    seq.reserve(n);
    for (int i = 1; i <= n; ++i) {
        seq.push_back(i);
    }
    for (int v : seq) {
        result *= v;
    }
    return result;
}

int sum_odd_numbers(int n)
{
    // Assume caller validated 1 <= n < 100
    int sum = 0;
    int current = 1;

    // While loop adding odd numbers up to n
    while (current <= n) {
        sum += current;
        current += 2;
    }
    return sum;
}
