#include "parseList.h"
#include "animalClasses.h"
#include <filesystem>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>

#include "genAnimalNames.h"

std::vector<std::string> splitBySpace(const std::string& str) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string word;

    while (ss >> word) {
        result.push_back(word);
    }

    return result;
}

std::vector<Animal*> animals;
std::map<std::string, int> speciesMap = {{"Hyena", 0}, {"Lion", 0}, {"Bear", 0}, {"Tiger", 0}};
std::string currentAnimal;

int parseList() {
    // this has the console report the path the file system is looking in for "arrivingAnimals.txt"
    // if you receive an error while opening the file, place file into this directory
    std::fstream myFile{"arrivingAnimals.txt"};
    std::cout << "Checking in directory: " << std::filesystem::current_path() << " for file\n";

    // returns an error if unable to find the file

    if (!myFile) {
        std::cerr << "Error: could not find file in directory" << std::endl;
        return 1;
    }

    // Read through each line
    std::string strInput;
    while (std::getline(myFile, strInput)) {
        //std::cout << strInput << '\n';

        //Parse single line
        std::vector<std::string> parts;
        std::stringstream ss(strInput);
        std::string item;

        //Split by commas
        while (std::getline(ss, item, ',')) {
            item.erase(0, item.find_first_not_of(" \t"));
            item.erase(item.find_last_not_of(" \t") + 1);
            parts.push_back(item);
        }

        //Print the split parts
        //for (const auto& part : parts) {
        //    std::cout << part << '\n';
        //}

        //Now split each part by spaces and print the result
        int sectionNum = 0;
        std::cout << "Next animal\n";
        for (const auto& part : parts) {
            std::vector<std::string> splitWords = splitBySpace(part);
            if (sectionNum == 0) {
                std::cout << "Split part " << sectionNum << " (age in years and species) is: " << part << '\n';
            }
            if (sectionNum == 1) {
                std::cout << "Split part " << sectionNum << " (birth season) is: " << part << '\n';
                for (const auto& word : splitWords) {
                    if ("hyena") {
                        Hyena("h01", 4);
                        speciesMap.at("Hyena")++;
                    }
                }
            }
            if (sectionNum == 2) {
                std::cout << "Split part " << sectionNum << " (color) is: " << part << '\n';
            }
            if (sectionNum == 3) {
                std::cout << "Split part " << sectionNum << " (weight) is: " << part << '\n';
            }
            if (sectionNum == 4) {
                std::cout << "Split part " << sectionNum << " (origin part 1) is: " << part << '\n';
            }
            if (sectionNum == 5) {
                std::cout << "Split part " << sectionNum << " (origin part 2) is: " << part << '\n';
            }

            std::cout << "-----" << std::endl;
            sectionNum++;
            }
        }
    return 0;
}


