//i use GPT for the definition for every step to remind me this is how i usually learn in other language :D
#include <iostream>
//This includes the iostream library, which allows input and output operations (e.g., using cout for printing).

using namespace std;
//This allows us to use standard library functions without explicitly prefixing them with std::.

//problem 1
bool is_power_of_2_loop(int n) {
    if (n <= 0)
        return false;
    while (n != 1) {
        //as long as n is bigger then 1 loop diving by 2:
        if (n % 2 != 0)
            return false;
        //if n is not divisible by 2 (n % 2) return false (cuz power2 always divisible by2)
        n = n / 2;
    }
    return true;
}

bool is_power_of_2_no_loop(int n) {
    if (n <= 0)
        return false;
    int power = 1;
    //1 is2^0
    while (power < n) {
        if (power == n)
            return true;
        power *= 2;
        // 1-2-4-8
        if (power > n / 2)
            break;
        //so that it doesnt go more than the limit
    }
    return (power == n);
}

//problem 2
bool isPrime(int n) {
    if (n <= 1)
        return false;
    //1 is not a prime number. Negative numbers are not prime.

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;

    }
    return true;
}

//problem 3
int findGCD(int x, int y) {
    x = abs(x);
    y = abs(y);
    //we use abs for absolute value so that the number is positivbe and ensure it work with negative number
    if (x == 0 || y == 0) {
        return false;
    }
    while (x != y) {
        int temp = y;
        y = x;
        x = temp % y;
    }
    return y;
}

void reducingfraction (int num, int dem) {

}
int main() {
    // Test problem 1
    int testNumbers[] = {0,1,2,3,4,6,8,-2,256,255};
    bool expected[] = {false, true, true, false, true, false, true, false, true, false};
    // an array containing the 1 is true and 0 is false in the testnumber list
    bool pass = true;

    for (int i = 0; i < 10; i++) {
        bool resultLoop = is_power_of_2_loop(testNumbers[i]);
        bool resultNoLoop = is_power_of_2_no_loop(testNumbers[i]);
        if (resultLoop == expected[i] && resultNoLoop == expected[i]) {
        } else {
            pass = false; // If either one is incorrect, set pass to false
        }
    }
    //if all pass test is correct, otherwise is fail
    if (pass) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }

    // Test Problem 2
    int testPrimes[] = {-5,0,1,2,3,4,9,17,25,7919};
    bool expected2[] = {false, false, false, true, true, false, false, true, false, true};
    for (int i = 0; i < 10; i++) {
        bool result = isPrime(testPrimes[i]);
        if (result != expected2[i]) {
            //it take the prime with the test number and compare to the expected result true or false
        }
    }
    if (pass) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}