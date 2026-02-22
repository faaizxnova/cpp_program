#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class solution {
    public:
        unsigned int query = 0, n_var_length = 0, index = 0, v_index = 0;
        
        vector < vector <unsigned int> > arr;
        
        void getData() {
            cin >> query >> n_var_length;
            
            for(int i = 0; i < n_var_length; i ++) {
                unsigned  var_length; cin >> var_length;
                for(unsigned int j = 0; j < var_length; j ++ ) cin >> arr[i][j]; 
            }

            for(; query; --query) {
                cin >> index >> v_index;
                cout << arr[index][v_index];                
            }
        }
};

int main(void) {
    ios :: sync_with_stdio(false);
    solution obj;
    obj.getData();
    return 0;
}
