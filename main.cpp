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
    double xcur = 0.0;
    double ycur = 0.0;
    double xStep = 1.0/numBodies;
    double yStep = 1.0/numBodies;
    for (auto i = bodies.begin(); i<bodies.end(); i++){
        i->vX = 0.0;
        i->vY = 0.0;
        i->pX = xcur;
        i->pY = ycur;
        xcur += xStep;
        ycur += yStep;
    }
}

// TODO: Test if this actually works
// TODO: Return a time
// returns the rate (in millions of interactions / second)
double standardThreeBody(std::vector<body> &bodies, int numIterations){
    for (auto i = bodies.begin(); i < bodies.end(); i++){
        for (auto j = bodies.begin(); j < bodies.end(); j++){
            double x_diff = (j->pX - i->pX);
            double y_diff = (j->pY - i->pY);
            double distance_squared = x_diff * x_diff + y_diff * y_diff;

            // update by acceleration times time interval
            double product = G * j->mass * timestep / distance_squared;
            i->vX += x_diff * product;
            i->vY += y_diff * product;

        }
    }
    for (auto i = bodies.begin(); i < bodies.end(); i++){
        i->pX += i->pX * timestep;
        i->pY += i->pY * timestep;        
    }
    return -1.0;

    // //initialize sum force vector to 0s
    // std::vector<double> sum_forces(bodies.size(),0.0);
    // //for each body
    //     //for every other body, add to the sum force
    
    // //for every body, divide force by mass to get accelleration
    
    // //for every body, multiply acceleration by time step to get the change in velocity
    
    // //for every body, add the new velocity to the old velocity.
    
    // //for every body, update position from v and timestep
    
}

// similar to standardThreeBody, but uses newton's third to reduce the number 
// of calculations
double reducedThreeBody( std::vector<body> &bodies, int numIterations){
    for (auto i = bodies.begin(); i < bodies.end(); i++){
        for (auto j = i+1; j < bodies.end(); j++){
            double x_diff = (j->pX - i->pX);
            double y_diff = (j->pY - i->pY);
            double distance_squared = x_diff * x_diff + y_diff * y_diff;

            // update by acceleration times time interval
            double producti = G * j->mass * timestep / distance_squared;
            double productj = G * i->mass * timestep / distance_squared;
            i->vX += x_diff * producti;
            i->vY += y_diff * producti;
            j->vX += -1 * x_diff * productj;
            j->vY += -1 * y_diff * productj;

        }
    }
    for (auto i = bodies.begin(); i < bodies.end(); i++){
        i->pX += i->pX * timestep;
        i->pY += i->pY * timestep;
    }
    //initialize sum force vector to 0s
    //for each body
        //for every other body not done, add to the sum force, subtract from their sum force.
        //remove body from list/add to 'done' list
    
    //for every body, divide force by mass to get accelleration
    
    //for every body, multiply acceleration by time step to get the change in velocity
    
    //for every body, add the new velocity to the old velocity.
    
    //for every body, update position from v and timestep
   
}

int main(){

    std::vector<int> test_numbers = {10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    std::vector<body> bodies;
    std::vector<double> standard_performances(test_numbers.size());
    std::vector<double> reduced_performances(test_numbers.size());
    int ind = 0;
    for (auto iter = test_numbers.begin(); iter < test_numbers.end(); iter++){
        bodies.clear();
        bodies.resize(*iter);
        generateBodies(bodies, *iter);
        standard_performances[ind] = standardThreeBody(bodies, test_numbers[ind]);
        reduced_performances[ind] = reducedThreeBody(bodies, test_numbers[ind]);
        ind += 1;
    }

    //TODO: plot these performances
}    
