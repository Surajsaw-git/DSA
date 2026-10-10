/*
790. Count of Prime Numbers till N
You are given an integer n. You need to find out the number of prime numbers in the range [1, n] (inclusive). Return the number of prime numbers in the range.

A prime number is a number which has no divisors except, 1 and itself.

Example 1:
Input: n = 6

Output: 3

Explanation: Prime numbers in the range [1, 6] are 2, 3, 5.

Example 2:
Input: n = 10

Output: 4

Explanation: Prime numbers in the range [1, 10] are 2, 3, 5, 7.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        vector<bool> isPrime(n, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int primecount = 0;

        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                primecount++;
            }
        }

        return primecount;
    }
};

int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    Solution P;

    int result = P.countPrimes(n);

    cout << "Number of prime numbers: " << result << endl;

    return 0;
}
