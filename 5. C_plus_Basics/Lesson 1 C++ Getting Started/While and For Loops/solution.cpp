#include <iostream>

int main() {
    
    for (int i = 0; i < 80; i++) {
        if (i < 10) {
            std::cout << "slow" << std::endl;
        }
        else if (i < 30) {
            std::cout << "medium" << std::endl;
        }
        else if (i < 70) {
            std::cout << "fast" << std::endl;
        }
        else {
            std::cout << "too fast" << std::endl; 
        }
        
    }
    
    
    return 0;
}