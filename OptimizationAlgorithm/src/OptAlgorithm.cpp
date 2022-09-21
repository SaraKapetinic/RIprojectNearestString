//
// Created by sara on 19.9.22..
//

#include "OptAlgorithm.h"

OptAlgorithm::OptAlgorithm(std::vector<std::string> initStrings, int lenOfWord,std::vector<char> albet):
initStrings_(initStrings),lenOfWord_(lenOfWord_),albet_(albet){}

OptAlgorithm::~OptAlgorithm(){}

void OptAlgorithm::setStrings(std::vector<std::string> strs) {
    initStrings_ = strs;
}

std::string OptAlgorithm::initialize(std::vector<char> albet,int len) {
    std::string generateString = "";
    int randomIndex;
    std::vector<int> indices;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,25);
    for(int i =0; i< len;i++) {
        int index = dist(gen);
        indices.push_back(index);

    }
    for(int i:indices){
        generateString += (albet[i]);
    }
    return generateString;
}

std::string OptAlgorithm::getNeighbour(std::string solution, int k) {

    previouscharacters_.clear();
    indicesSolution_.clear();
    indicesAlphabet_.clear();
    int randomIndex;
    std::vector<int> indicesOfAlphabet;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,albet_.size()-1);

    std::vector<int> indicesOfSolution;
    int randomIndexSolution;
    std::uniform_int_distribution<> dist1(0,solution.size()-1);

    for(int i=0;i<k;i++){
        randomIndex = dist(gen);
        indicesOfAlphabet.push_back(randomIndex);
        randomIndexSolution = dist1(gen);
        indicesOfSolution.push_back(randomIndexSolution);
    }
   for(int i=0;i<indicesOfSolution.size();i++){
       previouscharacters_.push_back(solution[indicesOfSolution[i]]);
       solution[indicesOfSolution[i]] = albet_[indicesOfAlphabet[i]];

   }
   indicesAlphabet_ = indicesOfAlphabet;
   indicesSolution_= indicesOfSolution;

   return solution;

}

int OptAlgorithm::calcHammingDistance(std::string s1,std::string s2){
    int hammingDistanceCounter = 0;
    for(int i=0;i<s1.size();i++){
        if(s1[i] != s2[i]){
            hammingDistanceCounter++;
        }
    }
    return hammingDistanceCounter;
}

int OptAlgorithm::findMaximumHammingDistance(std::string chosen,std::vector<std::string> initStrings){

    int currentHammingDistance = 0;
    int bestHammingDistance = 0;

    for(std::string s:initStrings){
        currentHammingDistance = calcHammingDistance(s,chosen);

        if(currentHammingDistance>bestHammingDistance){
            bestHammingDistance = currentHammingDistance;
        }
        if(bestHammingDistance == initStrings[0].size()){
            return bestHammingDistance;
        }
    }
    return bestHammingDistance;
}

std::string OptAlgorithm::restoreSolution(std::string sol,std::vector<int> indices,std::vector<char>prevoius){
    for(int i=0;i<indices.size();i++){
        sol[indices[i]] = prevoius[i];
    }
    return sol;
}

std::pair<std::string,int> OptAlgorithm::RVNS(int iters, int max_k) {

    solution_ = initialize(albet_,initStrings_[0].size());
    int currValue = findMaximumHammingDistance(solution_,initStrings_);
    std::string result = solution_;

    for(int i=0;i<iters;i++){
        int k = 0;
        while(k <= max_k){
            std::string newSolution = getNeighbour(solution_,k);
            int newValue = findMaximumHammingDistance(newSolution,initStrings_);

            if(newValue < currValue){
                 solution_ = newSolution;
                 currValue = newValue;
                 result = newSolution;
                 break;
            }
            else {
                k++;
                solution_ = restoreSolution(newSolution,indicesSolution_,previouscharacters_);
            }
        }
    }
    return std::make_pair(result,currValue);
}

std::string OptAlgorithm::invertSolution(std::string solution){
    int randomIndexOfAlphabet;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,albet_.size()-1);
    randomIndexOfAlphabet = dist(gen);

    int randomSolutionIndex;
    std::uniform_int_distribution<> dist1(0,solution.size()-1);
    randomSolutionIndex = dist1(gen);
    localSearchInvetedIndex_ = randomSolutionIndex;
    localSearchOldChar_ = solution[randomSolutionIndex];

    solution[randomSolutionIndex] = albet_[randomIndexOfAlphabet];

    return solution;
}

std::pair<std::string,int> OptAlgorithm::simulatedAnnealing(int iters){
    int n = initStrings_[0].size();
    solution_ = initialize(albet_,n);
    int currentValue = findMaximumHammingDistance(solution_,initStrings_);
    std::string result = solution_;
    int bestValue = currentValue;

    for(int i=0;i<iters;i++){
        std::string newSolution = invertSolution(solution_);
        int newValue = findMaximumHammingDistance(newSolution,initStrings_);

        if(newValue < currentValue){
            solution_ = newSolution;
            currentValue = newValue;
            if(newValue<bestValue){
                bestValue = newValue;
                result = newSolution;
            }
        }
        else{
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(0,1);
            double q = dist(gen);
            double p = 0.5;
            if(p > q){
                solution_ = newSolution;
                currentValue = newValue;
            }
            else{
                solution_ = oldSolution(newSolution);
            }
        }
    }
    return std::make_pair(result,bestValue);
}

std::string OptAlgorithm::oldSolution(std::string solution) {
    solution[localSearchInvetedIndex_] = localSearchOldChar_;
    return solution;
}

