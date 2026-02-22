#include <iostream>
#include <string>

template <typename T>

void exeption_handling() {
    int num, deno;
    std ::cout << "Enter : ";
    std ::cin >> num >> deno;
    try {
        if (deno == 0) {
            throw std ::runtime_error("Division by zero!");
        } else {
            std ::cout << num / deno;
        }
    } catch (std ::runtime_error error) {
        std ::cout << "Error : " << error.what();
    }
}

int ret_static() {
    static int num = 0;
    return num ++;
}
int main(void) {
    std ::ios ::sync_with_stdio(false);
    // std :: cout << ret_static();
    // std :: cout << ret_static();
    // std :: cout << ret_static();
    std :: cout << sizeof(nullptr);
    return 0;
}