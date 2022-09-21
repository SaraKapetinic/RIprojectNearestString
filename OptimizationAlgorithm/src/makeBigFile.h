//
// Created by sara on 18.9.22..
//

#ifndef NEARESTSTRING_MAKEBIGFILE_H
#define NEARESTSTRING_MAKEBIGFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

// Class for generating files for testing the algorithm


class makeBigFile {
public :
    const std::vector<std::string> albet = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    void writetofile(){
        std::string s;
        std::ofstream output_file("/home/sara/Desktop/RIprojectNearestString/OptimizationAlgorithm/resources/test.txt");

        for(int i =0 ;i<4;i++){
            s = generateNextRandomWord(albet,2);
            output_file << s;
            output_file << std::endl;
        }
    }
    std::string generateNextRandomWord(std::vector<std::string> alphabet,int len)
    {
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
};

#endif //NEARESTSTRING_MAKEBIGFILE_H
