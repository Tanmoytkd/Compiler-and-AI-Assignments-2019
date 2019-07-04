#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

map<char, int> mp;

int getnum(string s) {
	int num = 0;
	for(int i=0; i<s.length(); i++) {
		char ch = s[i];
		num *= 10;
		num += mp[ch];
	}
	return num;
}

string domain = "TWOFUR";
string s1, s2, s3;
int solved = 0;

void decode(int digit) {
	if(digit >=10) {
		if(!solved) {
			if(getnum(s1)+getnum(s2)==getnum(s3)) {
				for(int i=0; i<domain.length(); i++) {
					char ch = domain[i];
					if(mp[ch]==-1) return;
				}
				char firstDigit = s3[0];
				if(mp[firstDigit]==0) return;
				cout << s1 << " + " << s2 << " = " << s3 << endl;
				printf("%d + %d = %d\n\n", getnum(s1), getnum(s2), getnum(s3));
				solved = 0;
			}
		}
		return;
	}

	for(int pos=0; pos<domain.length(); pos++) {
		char ch = domain[pos];
		if(mp[ch]==-1) {
			mp[ch] = digit;
			if(!solved) decode(digit+1);
			mp[ch]=-1;
		}
	}
	if(!solved) decode(digit+1);
}

/* Print duplicates present in the passed string */
string printDistinct(string str)
{
	//cout << str << endl;
	int count[NO_OF_CHARS];
	memset(count, 0, sizeof count);

	int i;
	for(int i=0; i<str.length(); i++) {
		char ch = str[i];
		count[ch]++;
	}

	string res = "";
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		if (count[ch] >= 1) {
			//cout << ch << endl;
			res += ch;
		}
	}
	//cout << res << endl;
	return res;
}

string getDomain(string s1, string s2, string s3) {
	return printDistinct(s1+s2+s3);
}

string upper(string s) {
    string ret = "";
    for(int i=0; i<s.length(); i++) {
        ret += toupper(s[i]);
    }
    return ret;
}

int main() {
	s1 = "WRONG";
	s2 = "WRONG";
	s3 = "RIGHT";

	cout << "Enter the first string: ";
	cin  >> s1;
	cout << "Enter the second string: ";
	cin  >> s2;
	cout << "Enter the third string: ";
	cin  >> s3;

	s1 = upper(s1);
	s2 = upper(s2);
	s3 = upper(s3);

	domain = getDomain(s1, s2, s3);
	for(int i=0; i<domain.length(); i++) {
		mp[domain[i]] = -1;
	}
	decode(0);

	return 0;
}
