#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		bool answer = true;

		int alphabetArray1[26] = { 0 };
		int alphabetArray2[26] = { 0 };

		for (int i = 0; i < s.size(); ++i)
		{
			++alphabetArray1[s[i] - 97];
		}
		for (int i = 0; i < t.size(); ++i)
		{
			++alphabetArray2[t[i] - 97];
		}

		for (int i = 0; i < (sizeof(alphabetArray1) / sizeof(*alphabetArray1)); ++i)
		{
			if (alphabetArray1[i] != alphabetArray2[i])
			{
				return false;
			}
		}
		return answer;
	}
};

//int main(int args, char* argv[]) {
//
//	cout << "Hell" << endl;
//
//
//
//
//}