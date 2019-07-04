#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> patterns;
    patterns.insert("CSE");
    patterns.insert("EEE");
    patterns.insert("PHY");
    patterns.insert("MAT");
    patterns.insert("GEB");
    patterns.insert("STA");
    patterns.insert("SOC");
    patterns.insert("SCW");
    patterns.insert("BMB");
    patterns.insert("IPE");

    string s;
    cout << "Please enter a dept. name: ";
    cin >> s;

    if(patterns.find(s)!=patterns.end()) {
        cout << "Match Found!!!" << endl;
    } else {
        cout << "Match not found!!!" << endl;
    }
}
