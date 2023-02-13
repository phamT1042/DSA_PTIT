#include<bits/stdc++.h>
using namespace std;
vector<string> tong, hieu;
void khoiTao() {
    for (int i = 10; i <= 89; i++) {
        for (int j = 10; j <= 100 - i - 1; j++)
            tong.push_back(to_string(i) + " + " + to_string(j) + " = " + to_string(i + j));
    }
    for (int i = 20; i <= 99; i++) {
        for (int j = 10; j <= i - 10; j++)
            hieu.push_back(to_string(i) + " - " + to_string(j) + " = " + to_string(i - j));
    }
}
int main() {
    khoiTao();
    int t; cin >> t;
    cin.ignore();
    while (t--) {
        string s; getline(cin, s);
        if (s[3] == '*' || s[3] == '/') cout << "WRONG PROBLEM!";
        else {
            int flag;
            vector<int> check;
            if (s[0] != '?') check.push_back(0);
            if (s[1] != '?') check.push_back(1);
            if (s[5] != '?') check.push_back(5);
            if (s[6] != '?') check.push_back(6);
            if (s[10] != '?') check.push_back(10);
            if (s[11] != '?') check.push_back(11);
            if (s[3] == '+') {
                for (string x : tong) {
                    flag = 1;
                    for (int y : check) {
                        if (x[y] != s[y]) {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag) {cout << x; break;}
                }
                if (!flag) cout << "WRONG PROBLEM!";
            }
            else if (s[3] == '-') {
                for (string x : hieu) {
                    flag = 1;
                    for (int y : check) {
                        if (x[y] != s[y]) {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag) {cout << x; break;}
                }
                if (!flag) cout << "WRONG PROBLEM!";
            }
            else {
                set<string> endRes;
                for (string x : tong) {
                    flag = 1;
                    for (int y : check) {
                        if (x[y] != s[y]) {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag) {endRes.insert(x); break;}
                }
                for (string x : hieu) {
                    flag = 1;
                    for (int y : check) {
                        if (x[y] != s[y]) {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag) {endRes.insert(x); break;}
                }
                if (endRes.size()) {
                    cout << *endRes.begin();
                }
                else cout << "WRONG PROBLEM!"; 
            }
        }
        cout << endl;
    }
}