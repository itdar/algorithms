#include <vector>

using namespace std;

// Process
//1. Input left (begin number) and right (end number)
//2. Iterate from left to right (i)
// 2.1. Iterate every digit of number
//  2.1.1. Check if it's divisible or not
//   2.1.1.1. If not -> make flag false
// 2.2. If flag is true -> add to resultVector
//3. Return resultVector

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> resultVector;

        int residue = 0;
        for (int i = left; i <= right; ++i)
        {
            bool isValid = true;

            int number = i;
            int quotient = number / 10;
            int remainder = number % 10;

            while (number != 0 && isValid)
            {
                remainder = number % 10;

                if (remainder == 0 || i % remainder != 0)
                {
                    isValid = false;
                }

                number /= 10;
            }

            if (isValid)
            {
                resultVector.push_back(i);
            }
        }

        return resultVector;
    }
};