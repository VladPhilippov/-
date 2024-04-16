#include <iostream>
#include <string>
using namespace std;

bool checkForIcereamSandwich(string line) {
	if (line.length() > 2) {
		int theSamePairs = 0;
		int right = line.length() - 1;
		char prevLeft;
		char prevRight;
		for (int i = 0; i < line.length() / 2; i++) {
			if (line[i] == line[right]) {
				if (theSamePairs) {
					if (line[i] != line[i - 1]) {
						break;
					}
				}
				theSamePairs++;
				prevLeft = line[i];
				prevRight = line[right--];
			}
			else {
				if (theSamePairs > 0) {
					if (line[i] == prevLeft || line[right] == prevRight) {
						cout << "a";
						return false;
					}
					else {
						return true;
					}
				}
				else {
					return false;
				}
			}
		}
		if (line.length() % 2) {
			if (line[line.length() / 2 + 1] == line[line.length() / 2] && line[line.length() / 2] == line[0]) {
				return false;
			}
		}
		else {
			if (line.length() / 2 == theSamePairs) {
				return false;
			}
		}
		return true;
	}
	return false;
}

int main() {
	setlocale(LC_ALL, "UKR");
	string line;
	cout << "Enter line: "; cin >> line;
	if (checkForIcereamSandwich(line)) {
		cout << "Сендвич ёкарный бабай" << endl;
	}
	else {
		cout << "К сожалению, это не сендвич" << endl;
	}
	system("pause");
}
