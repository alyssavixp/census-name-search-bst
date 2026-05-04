#include "BinarySearchTree.h"
#include "CensusData.h"
#include <iostream>
#include <string>
#include <vector>

void printMenu() {
    std::cout << "\nCensus Name Search BST\n";
    std::cout << "1. Print names alphabetically\n";
    std::cout << "2. Search for a surname\n";
    std::cout << "3. Show tree statistics\n";
    std::cout << "4. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    BinarySearchTree tree;
    std::vector<CensusRecord> records = loadCensusRecords("sample_names.csv");

    for (const CensusRecord& record : records) {
        tree.insert(record);
    }

    std::cout << "Loaded " << tree.getSize() << " census records.\n";

    int choice = 0;

    while (choice != 4) {
        printMenu();
        std::cin >> choice;

        if (choice == 1) {
            tree.printAlphabetical();
        } else if (choice == 2) {
            std::string name;
            CensusRecord result;
            int comparisons = 0;

            std::cout << "Enter surname in uppercase: ";
            std::cin >> name;

            bool found = tree.searchByName(name, result, comparisons);

            if (found) {
                std::cout << result.name << "," << result.rank << "," << result.count << std::endl;
                std::cout << "Comparisons: " << comparisons << std::endl;
            } else {
                std::cout << "Name not found.\n";
                std::cout << "Comparisons: " << comparisons << std::endl;
            }
        } else if (choice == 3) {
            std::cout << "Records loaded: " << tree.getSize() << std::endl;
            std::cout << "Tree height: " << tree.getHeight() << std::endl;
        } else if (choice == 4) {
            std::cout << "Goodbye.\n";
        } else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}