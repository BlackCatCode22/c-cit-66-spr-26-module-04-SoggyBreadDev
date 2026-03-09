//
// Created by new user on 3/6/2026.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "genAnimalNames.h"
#include "parseList.h"

std::string genAnimalNames() {
    // Open file for reading
    std::fstream myAnimalFile("animalNames.txt");

    // Get each line of the file into a 1D array
    // Count number of lines in file
    // Read file one line at a time
    std::string myStr;
    int numOfLines{};
    while (getline(myAnimalFile, myStr)) {
        numOfLines++;
    }
    std::cout << "\nThere are " << numOfLines << " lines in the file.";

    // Create an array to hold the lines of the file
    std::string myAnimalFileArray[numOfLines];

    // Return to top of file
    myAnimalFile.clear();
    myAnimalFile.seekg(0);

    // Read file one line at a time and insert each line into array
    // Use for loop now that num of lines in file is known
    for (int i=0; i<numOfLines; i++) {
        getline(myAnimalFile, myAnimalFileArray[i]);
    }

    // Divide by size of first element to get num of elements
    int lenOfArray = (sizeof(myAnimalFileArray) / sizeof(myAnimalFileArray[0]));

    // Create two variables needed for array searching
    std::string speciesNames[4] = {"Hyena", "Lion", "Bear", "Tiger"};
    std::string arrayElementFirstWord;


    std::vector<std::string> hyenaNames;
    std::vector<std::string> lionNames;
    std::vector<std::string> bearNames;
    std::vector<std::string> tigerNames;
    std::string currentSpecies;

    std::cout << "\n********* The Animal Name File Array *********\n";
    for (int i=0; i<lenOfArray; i++) {
        //end current line and print the element at index i of the array
        if (myAnimalFileArray[i].empty()) {
            continue;
        }

        // find the first blank space in the array element
        int firstSpace = myAnimalFileArray[i].find(' ');

        // copy initialize first word as the substring in element i of the array, at the position of the first space
        arrayElementFirstWord = myAnimalFileArray[i].substr(0, firstSpace);

        //check if the first word is any of our animal types, continue to next iteration if true
        std::stringstream ss(myAnimalFileArray[i]);
        std::string name;
        if (arrayElementFirstWord == speciesNames[0]) {
            currentSpecies = "Hyena";
            continue;
        }
        if (arrayElementFirstWord == speciesNames[1]) {
            currentSpecies = "Lion";
            continue;
        }
        if (arrayElementFirstWord == speciesNames[2]) {
            currentSpecies = "Bear";
            continue;
        }
        if (arrayElementFirstWord == speciesNames[3]) {
            currentSpecies = "Tiger";
            continue;
        }
        while (ss >> name) {
            name.erase(name.find_last_not_of(", ") + 1);
            if (currentSpecies == "Hyena") {
                hyenaNames.push_back(name);
            }
            if (currentSpecies == "Lion") {
                lionNames.push_back(name);
            }
            if (currentSpecies == "Bear") {
                bearNames.push_back(name);
            }
            if (currentSpecies == "Tiger") {
                tigerNames.push_back(name);
            }
        }
        std::cout << '\n';
    }
    myAnimalFile.clear();
    myAnimalFile.seekg(0);

    myAnimalFile.close();
return 0;
}
