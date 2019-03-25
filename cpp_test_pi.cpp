#include <iostream>


float calcPi(int i, float pi){
    float base = 2*i;
    float calc = 4 / (base * (base+1) * (base+2));
    bool add = true;

    // std::cout << calc;

    if (add == true) {
        return pi + calc;
    } else {
        return pi - calc;
    }
}

int main(){
    int num_of_calculations = 10;
    float pi = 3;
    for (int i = 1; i < num_of_calculations; i++) {
        pi = calcPi(i, pi);
        std::cout << pi << "\n";
    }
}
