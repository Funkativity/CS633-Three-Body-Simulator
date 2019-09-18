#include "stdio.h"
#include "math.h"
#include <vector>

const double G = 6.672 * std::pow(10,-11);
const double timestep = 0.001;
const double mass = 1.0;
const double vi = 0.0;

// struct defining the mass, position, and velocity of each body
struct body {
    double mass;
    double pX;
    double pY;   
    double vX;
    double vY;
};

// places numBodies uniformly spaced along a line from 0 to 1
void generateBodies(std::vector<body> bodies, int numBodies){

}

// returns the rate (in millions of interactions / second)
double standardThreeBody(std::vector<body> &bodies, int numIterations){
    //initialize sum force vector to 0s
    //for each body
        //for every other body not done, add to the sum force, subtract from their sum force.
        //remove body from list/add to 'done' list
    
    //for every body, divide force by mass to get accelleration
    
    //for every body, multiply acceleration by time step to get the change in velocity
    
    //for every body, add the new velocity to the old velocity.
    
}

// similar to standardThreeBody, but uses newton's third to reduce the number 
// of calculations
double reducedThreeBody( std::vector<body> &bodies, int numIterations){
    //initialize sum force vector to 0s
    //for each body
        //for every other body, add to the sum force
    
    //for every body, divide force by mass to get accelleration
    
    //for every body, multiply acceleration by time step to get the change in velocity
    
    //for every body, add the new velocity to the old velocity.
    
}

int main(){

    std::vector<int> test_numbers = {10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    std::vector<body> bodies;
    std::vector<double> standard_performances(test_numbers.size());
    std::vector<double> reduced_performances(test_numbers.size());
    int ind = 0;
    for (auto iter = test_numbers.begin(); iter < test_numbers.end(); iter++){
        standard_performances[ind] = standardThreeBody(bodies, test_numbers[ind]);
        reduced_performances[ind] = reducedThreeBody(bodies, test_numbers[ind]);
    }

    //TODO: plot these performances
}    
