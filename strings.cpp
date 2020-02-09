#include<iostream>
#include<string.h>

using namespace std;

void repeatingChar(char* str) {
	int H[26] = {0};
	for(int i = 0; str[i] != '\0'; i++)
		H[str[i] - 97] += 1;
	for(int i = 0; i < 26; i++)
		if(H[i] > 1)
			cout << (char)(i+97) << "\n";
}

void repeatingCharBitwise(char* str) {
	long int H = 0, x = 0;
	for(int i = 0; str[i] != '\0'; i++) {
		x = 1;
		x = x << (str[i] - 97);
		if((H & x) > 0) {
			cout << str[i] << "\n";
		} else {
			H = (H | x);
		}
	}
}

bool isAnagram(char* str1, char* str2) {
	int H[26] = {0};
	for(int i = 0; str1[i] != '\0'; i++)
		H[str1[i] - 97] += 1;
	for(int i = 0; str2[i] != '\0'; i++) {
		H[str2[i] - 97] -= 1;
		if(H[str2[i] - 97] < 0)
			return false;
	}
	return true;
}

void printPermutations(char* str, int k) {
	static char res[10];
	static int flag[10] = {0};

	if(str[k] == '\0') {
		res[k] = '\0';
		cout << res << "\n";
	} else {
		for(int i = 0; str[i] != '\0'; i++) {
			if(flag[i] == 0) {
				res[k] = str[i];
				flag[i] = 1;
				printPermutations(str, k+1);
				flag[i] = 0;
			}
		}
	}
}

void printSubsequence(string input, string output) {
	if(input.length() == 0) {
		cout << output << endl;
		return;
	}
	printSubsequence(input.substr(1), output);
	printSubsequence(input.substr(1), output + input[0]);
}

void swap(char* x, char* y) {
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void printPermutationsSwap(char s[], int l, int h) {
	if(l == h)
		cout << s << endl;
	else {
		for(int i = l; i <= h; i++) {
			swap(s[i], s[l]);
			printPermutationsSwap(s, l+1, h);
			swap(s[i], s[l]);
		}
	}
}

int main() {
	char str[] = "abc";
	string s = "abc";
	printPermutationsSwap(str, 0, 2);

}