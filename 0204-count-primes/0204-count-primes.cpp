class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2)
            return 0;

        vector<bool> isPrime(n, true);

        isPrime[0] = false;
        isPrime[1] = false;

        // Mark even numbers greater than 2 as non-prime
        for (int i = 4; i < n; i += 2) {
            isPrime[i] = false;
        }

        // Initially: 2 + all odd numbers
        int count = n / 2;

        // Check only odd numbers
        for (int i = 3; i * i < n; i += 2) {

            if (isPrime[i]) {

                // Start from i*i because smaller multiples
                // have already been handled
                for (int j = i * i; j < n; j += 2 * i) {

                    if (isPrime[j]) {
                        isPrime[j] = false;
                        count--;
                    }
                }
            }
        }

        return count;
    }
};