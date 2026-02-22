#include <stdio.h>

typedef int* Intptr;

class Solution {
    public:
        Intptr num_1, num_2;

        Solution(int* a, int* b) {
            this->num_1 = a;
            this->num_2 = b;
        }

        void update() {
            int val_num_1 = *num_1;
            int val_num_2 = *num_2;
            *num_1 = val_num_1 + val_num_2;
            *num_2 = val_num_1 - val_num_2;
            if (*num_2 < 0)
                *num_2 = -*num_2;
        }
};

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    scanf("%d %d", &a, &b);
    Solution sol(pa, pb);
    sol.update();
    printf("%d\n%d", a, b);
    

    return 0;
}