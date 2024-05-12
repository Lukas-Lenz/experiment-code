#include "Field.h"
#include "../core/State.h"

#include <iostream>

int main() {


    Field field {5, 6};

    while(true) {

        std::cout << "Field status:" << std::endl;
        field.print();
        std::cout << "Updating" << std::endl;
        field.update(dummyState());
        std::cout << "After Update:" << std::endl;
        field.print();

        std::string x;
        std::cin >> x;

    }

    return 0;

}