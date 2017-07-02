#include <iostream>
#include "fstream"
#include "sstream"
#include <cmath>
using namespace std;

int main() {
    int case_num;
    ifstream ifs("../data/P2_large.in");

    string s;
    getline(ifs, s);
    stringstream ss;
    ss << s;
    ss >> case_num;
    std::cout << case_num << endl;

    int case_end;
    getline(ifs, s);
    stringstream ss2;
    ss2 << s;
    cout << ss2.str() << endl;
    ss2 >> case_end;

    int case_idx = 0;
    long double min_candidate = 0;
    long double max_candidate = 10e15;
    long long prev_file_num = 0;
    int prev_file_per = 0;
    while (!ifs.eof() || case_idx >= case_num) {


        getline(ifs, s);
        if (s.find(' ') != string::npos) {
            stringstream ss3;
            ss3 << s;
            ss3 >> prev_file_per;
            ss3 >> prev_file_num;
            max_candidate = std::min((long double)(prev_file_num) / prev_file_per * 100,max_candidate);
            min_candidate = std::max((long double)(prev_file_num) / (prev_file_per+1) * 100,min_candidate);
        } else {
            int tmp;
            stringstream ss3;
            ss3 << s;
            ss3 >> tmp;
            if (tmp == case_end) {
                case_idx ++;
                long long max_cnd = std::floor(max_candidate);
                long long min_cnd = std::ceil(min_candidate);
                if (prev_file_per == 100)
                    cout << "Case #" << case_idx << ":" << prev_file_num << endl;
                else if (max_cnd - min_cnd <= 1)
                    cout << "Case #" << case_idx << ":" << max_cnd << endl;
                else
                    cout << "Case #" << case_idx << ":" <<  -1 << endl;
            }

            min_candidate = 0;
            max_candidate = 10e15;
        }
    }
    return 0;

}