#include <iostream>

int fi(int num);
int count = 0;

int main(){
    int n = 0;
    std::cout << "Enter the index of Fibonacci number:" << std::endl;
    std::cin >> n;
    std::cout << "The Fibonacci number is:" << std::endl;
    std::cout << fi(n) << std::endl;

    std::cout << "The time complexity is: " << count << std::endl;
    return 0;
}

int fi(int n) {
    count++;
    if (n == 1 || n == 2) {
        return 1;
    } else{
        return (fi(n -1) + fi(n -2));
    }
}
