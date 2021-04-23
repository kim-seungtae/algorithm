#include <iostream>
#include <map>
#include <string>
//생태학
//입력 정렬해서 vector로도 풀수있음
using namespace std;
map<string, double> m;

int main() {
	string s;
    double cnt = 0;
	while (1) {
		getline(cin, s);
		if (cin.eof() == true) {
			break;
		}
        ++cnt;
        if (m.count(s)) m[s] += 1;
        else m[s] = 1;

	}
    for (auto i : m) printf("%s %.4lf\n", i.first.c_str(), i.second * 100 / cnt);
    return 0;
}