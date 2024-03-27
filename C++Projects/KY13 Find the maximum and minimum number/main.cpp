#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    int n;
    int x=0;
    while (cin>>n){
        int max_num=-1000001;
        int min_num=1000001;
        for (int i = 0; i < n; ++i) {
            cin>>x;
            max_num=max(max_num,x);
            min_num=min(min_num,x);
        }
        cout<<max_num<<" "<<min_num<<endl;
    }
    return 0;
}
