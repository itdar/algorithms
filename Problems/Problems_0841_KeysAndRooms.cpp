#include <vector>

using namespace std;

class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		bool result = false;

		//if (rooms != nullptr)
		{
			vector<int> roomEnterCount;
			for (int i = 0; i < rooms.size() - 1; ++i) {
				roomEnterCount.push_back(0);
			}

			for (int i = 0; i < rooms.size(); ++i) {
				for (int j = 0; j < rooms[i].size(); ++j) {
					++roomEnterCount[rooms[i][j] - 1];
				}
			}

			bool cannotReached = false;
			for (int i = 0; i < roomEnterCount.size(); ++i) {
				if (roomEnterCount[i] < 1) {
					cannotReached = true;
				}
			}
			if (!cannotReached) {
				result = true;
			}

			return result;
		}
	}
};