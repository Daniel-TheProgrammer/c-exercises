/**
 * @file
 * @brief Finds the largest product in a series
 * @details
 * A brief overview
 * link to [problem statement](https://projecteuler.net/problem=8)
 */

#include <assert.h>   // for assert function
#include <inttypes.h> // for uint64_t, uint32_t data types
#include <stdbool.h>  // for bool data type
#include <math.h>     // for for sqrt function
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const char SERIES[] = "73167176531330624919225119674426574742355349194934\
96983520312774506326239578318016984801869478851843\
85861560789112949495459501737958331952853208805511\
12540698747158523863050715693290963295227443043557\
66896648950445244523161731856403098711121722383113\
62229893423380308135336276614282806444486645238749\
30358907296290491560440772390713810515859307960866\
70172427121883998797908792274921901699720888093776\
65727333001053367881220235421809751254540594752243\
52584907711670556013604839586446706324415722155397\
53697817977846174064955149290862569321978468622482\
83972241375657056057490261407972968652414535100474\
82166370484403199890008895243450658541227588666881\
16427171479924442928230863465674813919123162824586\
17866458359124566529476545682848912883142607690042\
24219022671055626321111109370544217506941658960408\
07198403850962455444362981230987879927244284909188\
84580156166097919133875499200524063689912560717606\
05886116467109405077541002256983155200055935729725\
71636269561882670428252483600823257530420752963450";

uint8_t getDigitFromChar(char ch) {
    uint8_t AsciiEquiv = (int) ch;
    return AsciiEquiv - 48;
}

uint16_t getIndexOfLastZeroInRange(uint16_t index, uint16_t numOfDigits) {
    uint8_t temp;
    for(uint16_t i = index + numOfDigits - 1; i >= index; i--) {
        temp = getDigitFromChar(SERIES[i]);
        if(temp == 0) {
            return i;
        }
    }
}

uint64_t getProductOfDigitsInRange(uint16_t index, uint16_t numOfDigits) {
    uint8_t temp;
    uint64_t productOfDigitsInRange = 1;
    for(uint16_t i = index; i < index + numOfDigits; i++) {
        temp = getDigitFromChar(SERIES[i]);
        productOfDigitsInRange *= temp;
    }

    return productOfDigitsInRange;
}

uint64_t getLargestProduct(uint16_t numOfDigits) {
    uint16_t index = 0;
    uint64_t largestProduct = 0;
    uint64_t temp;
    while(index + numOfDigits <= 1000) {
        temp = getProductOfDigitsInRange(index, numOfDigits);

        if(temp > largestProduct) {
            largestProduct = temp;
        }
        
        if(temp == 0) {
            index = getIndexOfLastZeroInRange(index, numOfDigits);
        }

        index++;
    }
    return largestProduct;
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
static void test() {
    // The following lines tests the program of correct behaviour
    assert(getLargestProduct(4) == 5832);
    printf("%ld\n", getLargestProduct(13));
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test(); // runs self-test implementation of the program
    return 0;
}