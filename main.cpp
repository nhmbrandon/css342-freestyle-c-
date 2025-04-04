[1:50 AM, 4/4/2025] Brandon: //i use GPT for the definition for every step to remind me this is how i usually learn in other language :D
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
       …
[3:05 PM, 4/4/2025] Brandon: //i use GPT for the definition for every step to remind me this is how i usually learn in other language :D
#include <iostream>
//This includes the iostream library, which allows input and output operations (e.g., using cout for printing).

using namespace std;
//This allows us to use standard library functions without explicitly prefixing them with std::.

//problem 1
bool is_power_of_2_loop(int n) {
    if (n <= 0)
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
        return false;
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
//reducing given fraction to minimum terms
// 2/4 -> 1/2
// 4/2 -> 2/1
// 6/8 -> 3/4
// 30/45 -> 2/3
// 6/6 -> 1/1
// 1/0 -> dnf
// -6/8 -> 3/-4


class fraction {
public:
    int numerator;
    int denominator;

    fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator){}

        std::string to_string() {
            return std::to_string(numerator) + "/" + std::to_string(denominator);

        }

        bool operator==(fraction &other) {
            return this->numerator == other.numerator &&
                this->denominator == other.denominator;
    }
};

fraction reduce (fraction input) {
    if (input.denominator == 0) return input;

    int gcd = input.numerator;
    int temp = input.denominator;

    while (temp != 0) {
        int remainder = gcd % temp;
        gcd = temp;
        temp = remainder;
    }

    gcd = abs(gcd);
    if (gcd == 0) return input;

    input.numerator /= gcd;
    input.denominator /= gcd;

    if (input.denominator < 0) {
        input.numerator *= -1;
        input.denominator *= -1;
    }

    return input;
}

void test() {
    fraction inputs[7] = {
        fraction(1,2),   // Should stay 1/2
        fraction(2,4),   // Should become 1/2
        fraction(4,2),    // Should become 2/1
        fraction(6,8),    // Should become 3/4
        fraction(30,45),  // Should become 2/3
        fraction(-6,8),   // Should become -3/4
        fraction(6,-14)   // Should become -3/7
    };

    fraction outputs[7] = {
        fraction(1,2),
        fraction(1,2),
        fraction(2,1),
        fraction(3,4),
        fraction(2,3),
        fraction(-3,4),
        fraction(-3,7)
    };
    cout << "Problem 3 Tests:" << endl;
        for (int i = 0; i < 7; i++) {
            fraction reduced = reduce(inputs[i]); // Reduce ONCE
            if (reduced == outputs[i]) {
                cout << "PASS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
        }
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
        // Test problem 3
        test();

        return 0;
    }