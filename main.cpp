#include <iostream>
#include <vector>
using namespace std;

// O(n) time | O(n) space
bool helper(string &str, int i) {
    int j = str.length() - i - 1;
    return i >= j || str[i] == str[j] && helper(str, i + 1);// O(n) time | O(n) space
}

// O(n) time | O(n) space
bool isPalindromeWithHelperMethod(string str) {
    return helper(str, 0);// O(n) time | O(n) space
}

// O(n) time | O(n) space
bool isPalindromeArray(string str) {
    vector<char> reversedChars;// O(n) space
    for(int i = str.length() - 1; i >= 0; i--) {// O(n) time
        reversedChars.push_back(str[i]);
    }
    return str == string(reversedChars.begin(), reversedChars.end());
}

// O(n^2) time | O(n) space
bool isPalindromeReversed(string str) {
    string reversedString;// O(n) space
    for(int i = str.length() - 1; i >= 0; i--) {// O(n) time
        reversedString += str[i];// O(n) time NESTED
    }
    return str == reversedString;
}

// O(n) time | O(1) space
bool isPalindromePointers(string str) {
    int left = 0;
    int right = str.length() - 1;
    while(left < right) {// O(n) time
        if(str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string input = "abcdcba";
    cout << isPalindromePointers(input) << endl;
    cout << isPalindromeReversed(input) << endl;
    cout << isPalindromeArray(input) << endl;
    cout << isPalindromeWithHelperMethod(input) << endl;
    return 0;
}
