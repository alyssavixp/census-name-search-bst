#include "BinarySearchTree.h"
#include <iostream>
#include <algorithm>

BinarySearchTree::Node::Node(const CensusRecord& record) {
    data = record;
    left = nullptr;
    right = nullptr;
}

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
    size = 0;
}

BinarySearchTree::~BinarySearchTree() {
    clear(root);
}

void BinarySearchTree::clear(Node* node) {
    if (node == nullptr) {
        return;
    }

    clear(node->left);
    clear(node->right);
    delete node;
}

void BinarySearchTree::insert(const CensusRecord& record) {
    root = insert(root, record);
    size++;
}

BinarySearchTree::Node* BinarySearchTree::insert(Node* node, const CensusRecord& record) {
    if (node == nullptr) {
        return new Node(record);
    }

    if (record.name < node->data.name) {
        node->left = insert(node->left, record);
    } else if (record.name > node->data.name) {
        node->right = insert(node->right, record);
    }

    return node;
}

void BinarySearchTree::printAlphabetical() const {
    printInOrder(root);
}

void BinarySearchTree::printInOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }

    printInOrder(node->left);
    std::cout << node->data.name << "," << node->data.rank << "," << node->data.count << std::endl;
    printInOrder(node->right);
}

bool BinarySearchTree::searchByName(const std::string& name, CensusRecord& result, int& comparisons) const {
    comparisons = 0;
    Node* found = search(root, name, comparisons);

    if (found == nullptr) {
        return false;
    }

    result = found->data;
    return true;
}

BinarySearchTree::Node* BinarySearchTree::search(Node* node, const std::string& name, int& comparisons) const {
    if (node == nullptr) {
        return nullptr;
    }

    comparisons++;

    if (name == node->data.name) {
        return node;
    }

    if (name < node->data.name) {
        return search(node->left, name, comparisons);
    }

    return search(node->right, name, comparisons);
}

int BinarySearchTree::getSize() const {
    return size;
}

int BinarySearchTree::getHeight() const {
    return getHeight(root);
}

int BinarySearchTree::getHeight(Node* node) const {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    return 1 + std::max(leftHeight, rightHeight);
}