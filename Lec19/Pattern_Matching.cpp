#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    int textLength = text.length();
    int patternLength = pattern.length();

    if (patternLength > textLength) {
        cout << "Pattern is longer than the string" << endl;
        return 0;
    }

    deque<char> window;
    deque<int> positions;

    for (int i = 0; i < patternLength; i++) {
        window.push_back(text[i]);
    }

    if (pattern == string(window.begin(), window.end())) {
        positions.push_back(0);
    }

    for (int i = patternLength; i < textLength; i++) {
        window.pop_front();
        
        window.push_back(text[i]);

        if (pattern == string(window.begin(), window.end())) {
            positions.push_back(i - patternLength + 1);
        }
    }

    if (positions.empty()) {
        cout << "Pattern not found" << endl;
    } else {
        for (int pos : positions) {
            cout <<"Pattern found at index " << pos << endl;
        }
        cout << endl;
    }

    return 0;
}
