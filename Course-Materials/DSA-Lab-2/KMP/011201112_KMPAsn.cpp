#include <iostream>
#include <vector>

using namespace std;

vector<int> computeLPS(const string &pattern) {
    int len = pattern.length();
    vector<int> lps(len, 0);
    int j = 0;

    for (int i = 1; i < len; ) {
        if (pattern[i] == pattern[j]) {
            lps[i] = j + 1;
            j++;
            i++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<int> findOccurrences(const string &text, const string &pattern) {
    int textLen = text.length();
    int patternLen = pattern.length();
    vector<int> lps = computeLPS(pattern);

    vector<int> occurrences;
    int i = 0;  // Index for text
    int j = 0;  // Index for pattern

    while (i < textLen) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == patternLen) {
                occurrences.push_back(i - j);
                j = lps[j - 1];
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return occurrences;
}

int main() {
    int n, i = 0;
    cin >> n;
    while(i++ < n) {
        string str1, str2, caseText = "Case " + to_string(i) + ": ";
        string caseSpace(caseText.length(), ' ');

        cin >> str1 >> str2;
        vector<int> occurrenceIndices = findOccurrences(str1, str2);

        cout << caseText;
        int occurred = occurrenceIndices.size() - 1;
        if (occurrenceIndices.empty()) {
            cout << "Not Found" << endl;
        } else {
            cout << "Found at ";
            auto last = occurrenceIndices.back();
            occurrenceIndices.pop_back();
            for (int index : occurrenceIndices) {
                cout << index << ", ";
            }
            cout << last << " position" << endl;
        }
        cout << caseSpace << occurred + 1 << " times" << endl;
    }

    return 0;
}
