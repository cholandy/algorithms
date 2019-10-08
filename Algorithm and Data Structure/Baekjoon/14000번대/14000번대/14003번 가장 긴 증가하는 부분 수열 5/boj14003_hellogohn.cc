#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
 
vector<int> vt;
vector<int> vt_index;
vector<int> num_vec;
vector<int> before_vector;
vector<int>::iterator iter; 
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, data;
 
    cin >> n;
    before_vector.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> data;
        num_vec.push_back(data);
        if (i == 0) {
            vt.push_back(data);
            before_vector.at(i) = -1;
            vt_index.push_back(i); 
        }
 
        if (vt.back() < data) {
            vt.push_back(data);
            before_vector.at(i) = vt_index.back();
            vt_index.push_back(i);
        }
        else {
            iter = lower_bound(vt.begin(), vt.end(), data);
            *iter = data;
            int now_index = iter - vt.begin();
            if (now_index > 0)
                before_vector.at(i) = vt_index.at(now_index -1);
            else
                before_vector.at(i) = -1;
            vt_index.at(now_index) = i;
        }
    }
     
    cout << vt.size() << endl;
 
    int print_index = vt_index.back();
    vector<int> ans_vec;
    while (print_index != -1) {
        ans_vec.push_back(num_vec.at(print_index) );
        print_index = before_vector.at(print_index);
    }
 
    sort(ans_vec.begin(), ans_vec.end());
 
    for (int ans_idx = 0; ans_idx < ans_vec.size(); ans_idx++)
        cout << ans_vec.at(ans_idx) << " ";
 
    return 0;
 
}
