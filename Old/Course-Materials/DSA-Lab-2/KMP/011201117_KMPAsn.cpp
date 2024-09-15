#include <bits/stdc++.h>

using namespace std;

vector<int> countOccurrence(const string &text, const string &pattern) {
    int textLen = text.length();
    int patternLen = pattern.length();
    vector<int> lps(patternLen, 0);

    int j = 0;
    int i = 1;

    // generating prefix pattern
    while (i < patternLen) {
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

    // Finding occurrence 
    vector<int> occurrences;
    i = 0;
    j = 0;

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

void solve(int cse) {
    string A, B, text = "Case " + to_string(cse) + ": ";
    string space(text.length(), ' ');

    cin >> A >> B;
    auto occurrences = countOccurrence(A, B);

    cout << text;
    int occurred = occurrences.size() - 1;
    if (occurred < 0) {
        cout << "Not Found" << endl;
    } else {
        auto last = occurrences.back();
        occurrences.pop_back();

        cout << "Found at ";
        for (int index : occurrences) {
            cout << index << ", ";
        }
        cout << last << " position" << endl;
    }
    cout << space << occurred + 1 << " times" << endl;
}

int main() {
    int t, i = 0;
    cin >> t;
    while (i++ < t)
        solve(i);
    return 0;
}