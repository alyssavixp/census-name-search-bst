#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "CensusRecord.h"
#include <string>

class BinarySearchTree {
private:
    struct Node {
        CensusRecord data;
        Node* left;
        Node* right;

        Node(const CensusRecord& record);
    };

    Node* root;
    int size;

    Node* insert(Node* node, const CensusRecord& record);
    void printInOrder(Node* node) const;
    void clear(Node* node);
    Node* search(Node* node, const std::string& name, int& comparisons) const;
    int getHeight(Node* node) const;

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(const CensusRecord& record);
    void printAlphabetical() const;
    bool searchByName(const std::string& name, CensusRecord& result, int& comparisons) const;
    int getSize() const;
    int getHeight() const;
};

#endif