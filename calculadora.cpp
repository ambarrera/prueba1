//
//  main.cpp
//  Calculadora
//
//  Created by Amara Barrera on 20/08/25.
//

#include <iostream>
using namespace std;

// Code B
// User type to simplify the declaration
typedef float (*lpfnOperation)(float, float);

float Addition(float a, float b){
    return a+b;
}

float Subtraction(float a, float b){
    return a-b;
}

float Multiplication(float a, float b){
    return a*b;
}

float Division(float a, float b){
    if(b==0){
        throw runtime_error("division no permitida");
    }
    
    return a/b;
}

int main(){
    // CVector of pointer to functions
    lpfnOperation vpf[4] = {&::Addition, &::Subtraction,
        &::Multiplication, &::Division};
    float a, b, c; int opt;
    
    // enter the operands
    cin >> a >> b;
    
    // enter the operation 0-Addition, 1-Subtraction, 3-Multiplication, 4-Division
    cin >> opt;
    
    // The next line replaces the switch and replaces the whole switch
    try{
        c = (*vpf[opt])(a, b);
        cout << c;
    }
    
    catch(runtime_error f){
        cout << f.what() << "\n";
    }
}

