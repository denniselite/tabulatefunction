//
//  main.cpp
//  Function
//
//  Created by Denis Podlesnykh on 19.01.16.
//  Copyright © 2016 Denis Podlesnykh. All rights reserved.
//

#include <iostream>
#include <vector>


class varDeclare
{
public:
    double a, b, delta, stepState;
    int param;
};

int n;
std::vector<varDeclare> varDeclares;
std::vector<double> currentState;

void calculate(int i) {
    double step = varDeclares[i].stepState;
    while (step <= varDeclares[i].b) {
        double y = 0;
        for (std::vector<double>::iterator it = currentState.begin(); it != currentState.end(); ++it) {
            y += *it;
            std::cout << *it << " ";
        }
        std::cout << "f(x)=" << y << "\n";
        step += varDeclares[i].delta;
        varDeclares[i].stepState = step;
        currentState[i] = step * varDeclares[i].param;
        if (step <= varDeclares[i].b) {
            if (i == n-1) i = -1;
            calculate(++i);
        }
    }
}

int main(int argc, const char * argv[]) {
    std::cout << "Please, enter count of variables!\n";
    std::cin >> n;
    int prevParam = 1, prevPrevParam = 1;
    for (int i = 0; i < n; i++) {
        varDeclare newDeclare;
        std::cout << "Please, enter [A, B], Delta (for x" << i+1 << ")\n";
        std::cin >> newDeclare.a >> newDeclare.b >> newDeclare.delta;
        newDeclare.param = prevParam + prevPrevParam;
        prevPrevParam = prevParam;
        prevParam = newDeclare.param;
        newDeclare.stepState = newDeclare.a;
        varDeclares.push_back(newDeclare);
        currentState.push_back(newDeclare.a * newDeclare.param);
    }
    std::cout << "Table of results:\n";
    std::cout << "==========================\n";
    calculate(0);
    return 0;
}
