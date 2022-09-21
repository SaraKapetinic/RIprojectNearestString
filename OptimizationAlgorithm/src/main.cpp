#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <cmath>
#include <chrono>
#include "makeBigFile.h"
#include "OptAlgorithm.h"

const std::vector<char> albet ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int MAX_ITERS = 10000;
int main() {

    // If you want to generate large file for testing the algorithm, just uncomment 2 lines under
    //makeBigFile big;
    //big.writetofile();

    std::ifstream input_file("/home/sara/Desktop/RIprojectNearestString/OptimizationAlgorithm/resources/test.txt");
    if(!input_file){
        std::cerr<<"Can't open the file!"<<std::endl;
    }
    std::vector<std::string> initStrings;
    std::string line;
    while(input_file >> line){
        if(line.size()>0){
            initStrings.push_back(line);
        }
    }
    //We initialize class with vector of string, length of words and alphabet
    OptAlgorithm optimizationAlgorithm(initStrings,initStrings[0].size(),albet);

    //Printing some of the informations about the program
    std::cout<<"Number of words: "<<optimizationAlgorithm.getStrings().size()<<
    std::endl<<"Length of words: " << optimizationAlgorithm.getLength(initStrings)<<
    std::endl<<"Start solution: " << optimizationAlgorithm.getSolution()<<std::endl
    <<"Number of iterations: "<<MAX_ITERS<<std::endl
    <<"Alphabet length: "<<optimizationAlgorithm.getAlphabet().size()<<std::endl;

    //if you want to use RVNS uncomment a line bellow and comment the second line bellow
    //std::pair<std::string,int> result = optimizationAlgorithm.RVNS(MAX_ITERS,2);
    std::pair<std::string,int> result = optimizationAlgorithm.simulatedAnnealing(MAX_ITERS);

    std::cout<<std::endl;
    std::cout<<"Result: "<<result.first<<" "<<result.second<<std::endl;

    //std::cout<<optimizationAlgorithm.getSolution();

    return 0;
}