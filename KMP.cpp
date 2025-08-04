#include <bits/stdc++.h>
using namespace std;

// دالة لحساب lps = longest prefix which is also suffix
vector<int> computeLPS(const string &pattern) {
    int m = pattern.size();
    vector<int> lps(m);
    int len = 0; // طول الـ prefix اللي هو برضه suffix
    lps[0] = 0;  // أول واحد دايمًا صفر

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  // نرجع لورا في الـ lps
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// دالة البحث الأساسية
vector<int> KMP_Search(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = computeLPS(pattern);
    vector<int> occurrences;  // الأماكن اللي لاقينا فيها الـ pattern

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++, j++;
        }

        if (j == m) {
            occurrences.push_back(i - j);  // لقيناه في (i - j)
            j = lps[j - 1];  // نكمل ندور
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return occurrences;
}

int main() {
    string text = "ababcababcababc";
    string pattern = "ababc";

    vector<int> matches = KMP_Search(text, pattern);

    for (int pos : matches)
        cout << "Pattern found at index: " << pos << '\n';

    return 0;
}
