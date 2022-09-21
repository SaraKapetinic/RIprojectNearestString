#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <cmath>
#include <unordered_map>
#include <iterator>
#include <chrono>
#include <map>
#include <set>
#include "makeBigFile.h"

const std::vector<char> albet ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


int calcHammingDistance(std::string s1,std::string s2){
    int hammingDistanceCounter = 0;
    for(int i=0;i<s1.size();i++){
        if(s1[i] != s2[i]){
            hammingDistanceCounter++;
        }
    }
    return hammingDistanceCounter;
}

void generate_words(const std::vector<char> &alphabet, size_t &word_length, std::vector<std::string> &results)
{
    std::vector<size_t> index(word_length, 0);
    
    for (;;)
    {
        std::string word(index.size(), ' ');
        for (size_t i = 0; i < index.size(); ++i)
        {
            word[i] = alphabet[index[i]];
        }
        results.emplace_back(word);

        for (int i = index.size() - 1; ; --i)
        {
            if (i < 0)
            {
                return;
            }

            ++index[i];

            if (index[i] == alphabet.size())
            {
                index[i] = 0;
            }
            else
            {
                break;
            }
        }
    }
}

int findMaximumHammingDistance(std::string chosen,std::vector<std::string> initStrings){

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


int main() {
    //makeBigFile mb;
    //mb.writetofile();

    std::ifstream input_file("/home/sara/Desktop/RIprojectNearestString/BruteForce/resources/test.txt");
    if(!input_file){
        std::cerr<<"Can't open the file!"<<std::endl;
    }
    std::vector<std::string> initStrings;
    std::string line;
    int n;
    while(getline(input_file,line)){
        initStrings.push_back(line);
    }
    n = initStrings[0].size();
    std::vector<std::string> allPermutations ;
    size_t k = initStrings[0].size();
    auto started = std::chrono::high_resolution_clock::now();
    std::set<char> newAlphabet;

    for(std::string s : initStrings){
        for(int i=0;i<s.size();i++){
            newAlphabet.insert(s[i]);
        }
    }

    generate_words(albet,k,allPermutations);

    int bestHammingDistance = initStrings[0].size();
    int currentHammingDistance = 0;
    std::string bestPermutation = allPermutations[0];
    
    for(auto perm : allPermutations){
        currentHammingDistance = findMaximumHammingDistance(perm,initStrings);
        if(currentHammingDistance<bestHammingDistance){
            bestHammingDistance = currentHammingDistance;
            bestPermutation = perm;
        }
    }    

    std::cout<<bestPermutation<<" "<<bestHammingDistance<<std::endl;
    auto done = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(done-started).count();
    return 0;
}
