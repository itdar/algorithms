#include <string>
#include <vector>
#include <iostream>
#include <sstream>

// ó������
//1. ���ڿ� s �Է¹޴´�.
//2. ���ڿ�����/2 �� ������ڿ��迭 �����д�.
//3. 1���� s length/2 ���� �ݺ��Ѵ�. (i)
// 3.1. ����(j)���� j+(i-1) �� length ���� ���� ������ �ݺ��Ѵ�. (j+=i)
//  3.1.1. i ��ŭ�� substring �� ���� ���� ��Ʈ���� ���ؼ�
//   3.1.1.1. ������ -> ���� ����, �ϳ� �����.
//   3.1.1.2. �ٸ��� -> ������ ������ڿ��迭 i ��°�� �ش� substring �ִ´�. (count 0 �̸� ���ڸ�, > 0 �̸� ���ڵ�)
//

using namespace std;

int solution(string s) {
	if (s.length() == 1)
		return 1;

	int answer = 0;
	int substringRange = s.length() / 2;
	// 2.
	vector<string> resultString;
	for (int i = 0; i < substringRange; ++i) {
		resultString.push_back("");
	}
	// 3.
	for (int i = 0; i + 1 <= substringRange; ++i) {
		int count = 1;
		string nextString;
		int j = 0;
		while (j + (i + 1) <= s.length()) {
			string currentStr = s.substr(j, i + 1);
			nextString = s.substr(j + (i + 1), i + 1);
			cout << " " << "currentStr : " << currentStr << " " << "nextString : " << nextString << endl;
			if (currentStr == nextString) {
				++count;
			}
			else {
				if (count == 1) {
					resultString[i] += currentStr;
				}
				else {
					stringstream ss;
					ss << count;
					resultString[i] += ss.str();
					resultString[i] += currentStr;

					count = 1;
				}
			}
			j += (i + 1);
		}
		//j -= i;
		while (j < s.length()) {
			resultString[i] += s[j];
			++j;
		}
	}

	// 4.
	int smallestLength = resultString[0].length();
	for (int i = 1; i < resultString.size(); ++i) {
		if (smallestLength > resultString[i].length()) {
			smallestLength = resultString[i].length();
		}
	}

	return smallestLength;
}

//int main() {
//	//string test1 = "aabbaccc";
//	string test1 = "a";
//	string test2 = "ababcdcdababcdcd";
//	string test3 = "abcabcdede";
//	string test4 = "abcabcabcabcdededededede";
//	string test5 = "xababcdcdababcdcd";
//
//	cout << "this : " << test1 << endl;
//	cout << solution(test1) << endl;
//
//	
//	return 0;
//}