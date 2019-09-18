#include "stdio.h"
#include "math.h"
#include <vector>
#include <chrono>
#include <fstream>
#include <iostream> 

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

// TODO: Test if this actually works
// returns the rate (in millions of interactions / second)
double standardThreeBody(std::vector<body> &bodies, int numIterations){
    auto start_time = std::chrono::high_resolution_clock::now();

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
    auto finish_time = std::chrono::high_resolution_clock::now();
    std::chrono::seconds time_span = 
            std::chrono::duration_cast<std::chrono::duration<std::chrono::seconds>>(finish_time - start_time);
    double num_interactions = (bodies.size() * (bodies.size() + 1)) / 2;
    return (num_interactions / time_span.count());
}

// similar to standardThreeBody, but uses newton's third to reduce the number 
// of calculations
double reducedThreeBody( std::vector<body> &bodies, int numIterations){
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
        standard_performances[ind] = standardThreeBody(bodies, test_numbers[ind]);
        reduced_performances[ind] = reducedThreeBody(bodies, test_numbers[ind]);
    }


    // write the performances to body_benchmarks.dat
    ////////////////////////////////////////////////////////////////////////////////////////
    // first column will be the number of bodies
    // second column will be standard performances
    // third column will be reduced performances
    std::ofstream outdata;
    outdata.open("body_benchmarks.dat"); // opens the file
    if( !outdata ) { // file couldn't be opened
        std::cerr << "Error: file could not be opened" << std::endl;
        exit(1);
    }

    for (int i = 0; i < test_numbers.size(); i++){
        outdata << test_numbers[i] << "\t\t" << standard_performances[i] << "\t\t"
                << reduced_performances[i] << std::endl;
    }
    outdata.close();
    
    return 0;
}    
