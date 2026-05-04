# Census Name Search BST

A C++ command-line project that loads surname data from a CSV file into a binary search tree. The program can print names alphabetically, search for a surname, and display basic tree statistics.

## Overview

This project demonstrates how a binary search tree can organize structured records using a string key. Each record contains a surname, census rank, and count. The tree uses the surname as the key, which allows an in-order traversal to print the records alphabetically.

## Features

- Loads census-style surname records from a CSV file
- Stores records in a binary search tree
- Prints records alphabetically using in-order traversal
- Searches for a surname by name
- Reports the number of comparisons used during search
- Displays tree size and height
- Builds from the command line using a Makefile

## Technical Concepts

- C++
- Binary search trees
- Recursion
- Structs and classes
- Pointers and dynamic memory
- File input
- CSV parsing
- Command-line programs
- Makefiles

## File Structure

```text
main.cpp
BinarySearchTree.h
BinarySearchTree.cpp
CensusRecord.h
CensusData.h
CensusData.cpp
sample_names.csv
Makefile