// Writen by Nguyen Thanh Trung

#include <bits/stdc++.h>
using namespace std;

char tmp[1011];

int main() {
    string program = "";
    while (gets(tmp)) {
        if (program != "") program += "\n";
        program += tmp;
    }
    for(int i = 0; i < program.length(); ++i) {
        switch (program[i]) {
            case 'H': cout << "Hello, World!" << endl; break;
            case 'Q': cout << program << endl; break;
            case '9':
                for(int i = 99; i >= 1; --i) {
                    cout << i << " bottle" << (i > 1 ? "s " : " ") << "of beer on the wall," << endl;
                    cout << i << " bottle" << (i > 1 ? "s " : " ") << "of beer." << endl;
                    cout << "Take one down, pass it around," << endl;
                    if (i == 1) {
                        cout << "No bottles of beer on the wall." << endl;
                    }
                    else if (i == 2) {
                        cout << "1 bottle of beer on the wall." << endl;
                    }
                    else {
                        cout << (i-1) << " bottles of beer on the wall." << endl;
                    }
                    if (i > 1) cout << endl;
                }
                break;
            default:
                break;
        }
    }
}
