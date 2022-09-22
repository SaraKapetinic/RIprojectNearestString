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
#include <chrono>
#include "makeBigFile.h"
#include <unordered_map>
#include <iterator>


const std::vector<char> albet ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


std::string generateNextRandomWord(std::vector<std::string> alphabet,int len);
std::string findWordsWithMaxDistance(std::vector<std::string> words,int iters);
int hammingDistance(std::string s1,std::string s2);

int main() {
    // If you want to generate large file for testing the algorithm, just uncomment 2 lines under
    makeBigFile big;
    big.writetofile();
    std::ifstream input_file("/home/sara/Desktop/RIprojectNearestString/Second Optimization/resources/test4.txt");
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

    std::vector<std::unordered_map<char,int>> mapOfCharactersAndOccrs(initStrings[0].size()); // position in string,map of characters and occurence on position

    auto started = std::chrono::high_resolution_clock::now();

    std::unordered_map<char,int>::iterator it;

        for(int i =0 ;i<initStrings[0].size();i++){
            for(std::string word : initStrings){

                // check if key `c` exists in the map or not
                std::unordered_map<char, int>::iterator it = mapOfCharactersAndOccrs[i].find(word[i]);

                // key already present on the map
                if (it != mapOfCharactersAndOccrs[i].end()) {
                    it->second++;    // increment map's value for key `c`
                }
                    // key not found
                else {
                    mapOfCharactersAndOccrs[i].insert(std::make_pair(word[i], 1));
                }
            }
        }

    std::string bestWord = "";
    int maxOccurence = -1;
    char rememberedChar;
    for(int i =0;i<mapOfCharactersAndOccrs.size();i++){
        maxOccurence = -1;
        for(auto &e : mapOfCharactersAndOccrs[i]){
            if(e.second > maxOccurence){
                rememberedChar = e.first;
                maxOccurence = e.second;
            }
        }
        bestWord += rememberedChar;
    }
    std::cout<<bestWord <<std::endl;

    auto done = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(done-started).count();

    return 0;
}

int hammingDistance(std::string s1,std::string s2){
    int hammingDistanceCounter = 0;
    for(int i=0;i<s1.size();i++){
        if(s1[i] != s2[i]){
            hammingDistanceCounter++;
        }
    }
    return hammingDistanceCounter;
}

