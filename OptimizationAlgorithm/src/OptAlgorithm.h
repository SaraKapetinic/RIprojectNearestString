//
// Created by sara on 19.9.22..
//

#ifndef NEARESTSTRINGOPTIMIZATION_OPTALGORITHM_H
#define NEARESTSTRINGOPTIMIZATION_OPTALGORITHM_H
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <tuple>


class OptAlgorithm {
private:
    std::vector<std::string> initStrings_;
    int lenOfWord_;
    std::string solution_;
    std::vector<char> albet_;
public:
    OptAlgorithm(std::vector<std::string> initStrings,int lenOfWord,std::vector<char>albet);
    ~OptAlgorithm();
    //getters and setters
    std::vector<std::string> getStrings(){return initStrings_;}
    void setStrings(std::vector<std::string> strs);
    int getLength(std::vector<std::string> strs){return strs[0].size();}
    std::string getSolution(){return solution_;}
    std::vector<char> getAlphabet(){return albet_;}

    //Algorithm functions
    std::string initialize(std::vector<char> albet,int len); //initialize word of length len from alphabet albet
    std::string getNeighbour(std::string solution,int k);//returns a neighbour with k different characters
    int calcHammingDistance(std::string s1,std::string s2);
    int findMaximumHammingDistance(std::string chosen,std::vector<std::string> initStrings);//returns maximum Hamming distance between string and vector of strings(Like solutionValue function)
    std::string restoreSolution(std::string sol,std::vector<int> indices,std::vector<char>prevoius);
    std::pair<std::string,int> RVNS(int iters,int max_k);

    //functions for Local Search
    std::pair<std::string,int> simulatedAnnealing(int iters);
    std::string invertSolution(std::string solution);
    std::string oldSolution(std::string solution);


    std::vector<int> indicesSolution_;
    std::vector<int> indicesAlphabet_;
    std::vector<char> previouscharacters_;
    int localSearchInvetedIndex_;
    char localSearchOldChar_;
    int bestWordValue_;
    int numofIter ;


};


#endif //NEARESTSTRINGOPTIMIZATION_OPTALGORITHM_H
