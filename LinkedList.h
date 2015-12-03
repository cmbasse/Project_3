#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include "math.h"
#include "node.h"
#include <vector>
#include <string>



class LinkedList{

public:
    LinkedList();

    void insert(std::string key, int value, int x, int y, std::string direction);
    void rmove(std::string key);
    void toString();

    bool is_in(std::string key);
    int size();
    bool is_empty();

    ~LinkedList();
private:
    void limitSize();
    int maxLen = 20;
    int* first;
    int* last;
    int length = 0;
};
#endif //LINKED_LIST_H