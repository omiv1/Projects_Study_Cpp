#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main() {
    vector<int> vec;
    //vec.push_back(1);
    //vec.push_back(2);
    for (int i : vec)
    {
        //cout<<i<<" ";
    }
    cout<<endl;
    for(int i=1;i<24;i++)
    {
        cout<<i<<" ";
        if((i & (i - 1)) == 0)
        {
            cout<<endl;
        }
    }


}
