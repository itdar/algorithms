class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int resultLength = 0;
		for (int i = 0; i < s.length() - resultLength; ++i)
		{
			string buffer = "";
			bool isDone = false;
			for (int j = i; !isDone && j < s.length(); ++j)
			{
				if (!contains(buffer, s[j]))
				{
					buffer += string(1, s[j]);
				}
				else
				{
					isDone = true;
				}
			}
			if (buffer.length() > resultLength)
			{
				resultLength = buffer.length();
			}
		}
		return resultLength;
	}

	bool contains(string buffer, char character)
	{
		bool answer = false;
		for (int i = 0; !answer && i < buffer.length(); ++i)
		{
			if (buffer[i] == character)
			{
				answer = true;
			}
		}
		return answer;
	}

	//     string char2String(char character) {
	//         stringstream ss;
	//         string temp;
	//         ss << character;
	//         ss >> temp;

	//         return temp;
	//     }
};