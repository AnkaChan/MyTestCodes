#include <string>
using namespace std; //Shame

class Solution {
	//Expand from center
public:
	static string longestPalindrome(string s) {
		int tail, head;

		int longestStrHead = 0, longestStrTail = 0;
		//try center on letters
		for (int i = 0; i < s.size(); ++i) {
			for (int j = 0; (j + i < s.size() && i - j >= 0); ++j) {
				tail = i + j;
				head = i - j;
				if (s[tail] != s[head]) {
					++head;
					--tail;
					break;
				}
			}
			if (tail - head > longestStrTail - longestStrHead) {
				longestStrTail = tail;
				longestStrHead = head;
			}
		}

		//try center between letters
		for (int i = 1; i < s.size(); ++i) {
			for (int j = 0; (j + i < s.size() && i - j - 1 >= 0); ++j) {
				tail = i + j;
				head = i - j - 1;
				if (s[tail] != s[head]) {
					++head;
					--tail;
					break;
				}
			}
			if (tail - head > longestStrTail - longestStrHead) {
				longestStrTail = tail;
				longestStrHead = head;
			}
		}
		string subStr = s.substr(longestStrHead, longestStrTail - longestStrHead + 1);
		return subStr;
	}
};

int main() {
	string s = "babad";

	Solution::longestPalindrome(s);
}