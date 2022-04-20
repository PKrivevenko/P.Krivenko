#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;

//Для удобства перегрузка оператора вывода
ostream & operator <<(ostream& os, vector<int> & v){
    for(const auto & it : v){
        os << it << " ";
    }
    return os;
}


int main() {
    int n;
    cin >> n;
    map<int, vector<int>>c;
    vector<int>k;
    for(int j = 0; j < n; ++j){
        int N, K;
        cin >> N >> K;
        vector<int>b;
        k.push_back(K);
        for(int i = 0; i < N; ++i){
                int temp;
                cin >> temp;
                b.push_back(temp);
        }
        c.insert(make_pair(K, b));

    }

    for(int i = 0; i < k.size(); i++){
        vector<int>l;
        for(int j = k[i]; j < c[k[i]].size() + 1; j++){
            vector<int>temp;
            std::copy(c[k[i]].begin() + j - k[i], c[k[i]].begin() + j , back_inserter(temp));
            std::sort(temp.begin(), temp.end());
            int maxel = temp[k[i] - 2];
            l.push_back(maxel);
            cout << maxel << " ";
        }
        cout << endl;

    };

    return 0;
}
