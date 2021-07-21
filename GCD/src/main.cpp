#include <iostream>
#include "gcd.h"
#include <fstream>

int main() {
    
    int a; 
    int b;
    
    std::ifstream inputfile;
    std::ofstream outputfile;
    
    outputfile.open("../tst/output.txt");
    inputfile.open("../tst/input.txt");
    
    while(inputfile >> a >> b){
            outputfile << gcd(a,b) << std::endl;
            std::cout << gcd(a,b) << std::endl; 
    }
    
    outputfile.close();
    inputfile.close();
    
    return 0;
}
