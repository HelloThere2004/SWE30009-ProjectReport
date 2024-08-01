#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    } 
    if (num <= 3) {
        return true;
    } 
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Function to sort array and remove non-prime numbers
std::vector<int> sortAndRemoveNonPrimes(const std::vector<int> &arr) {
    std::vector<int> result;
    
    // Copy prime numbers to result vector
    for (int num : arr) {
        if (isPrime(num)) {
            result.push_back(num);
        }
    }

    // Sort the result vector
    std::sort(result.begin(), result.end());
    return result;
}

int main() {
    std::vector<int> arr = {10, 15, 3, 7, 8, 23, 5, 17};

    std::vector<int> sortedPrimes = sortAndRemoveNonPrimes(arr);

    std::cout << "Sorted prime numbers: ";
    for (int num : sortedPrimes) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}