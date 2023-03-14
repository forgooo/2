#ifndef INC_2_HD_H
#define INC_2_HD_H

#include <iostream>
using namespace std;

struct List{
    char ch;
    List* next;
};

void push_back(List*& head, char ch){
    List* newList = new List;
    newList->ch = ch;
    newList->next = nullptr;

    if(head == nullptr){
        head = newList;
    } else {
        List* current = head;
        while(current->next != nullptr)
            current=current->next;
        current->next = newList;
    }
}

void push_front(List*& head, char ch){
    List* newList = new List;

    newList->next = head;
    newList->ch = ch;

    head = newList;
}

void print_list(List* list){
    List* current = list;
    while(current != nullptr){
        cout << current->ch << " ";
        current = current->next;
    }
    cout << endl;
}

void repeats(List* head){
    int max = 0, counter = 0;
    List* current = head;
    while(current->next != nullptr){
        if(current->ch == current->next->ch){
            counter++;
        } else {
            counter++;
            (counter > max) ? max = counter : counter = 0;
            counter = 0;
        }
        current = current->next;
    }
    cout << "Max repeats:" << max   << endl;
}

void delete_same(List*& head) {
    List* current = head;
    List* prev = nullptr;
    List* temp = nullptr;

    while (current != nullptr && current->next != nullptr) {
        if (current->ch == current->next->ch) {
            if (current == head) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            temp = current->next;
            delete current;
            current = temp;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void insert_sorted(List*& list, char ch) {
    List* new_node = new List;
    new_node->ch = ch;
    new_node->next = nullptr;

    if (list == nullptr) {
        list = new_node;
        return;
    }

    if (list->ch >= ch) {
        new_node->next = list;
        list = new_node;
        return;
    }

    List* current = list;
    while (current->next != nullptr && current->next->ch < ch) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}


void search_nums(List* head, List*& digits){
    List* current = head;

    while(current->next != nullptr){
        if(int(current->ch) >= 48 && int(current->ch) <= 57){
            insert_sorted(digits, current->ch);
        }
        current = current->next;
    }
}

#endif //INC_2_HD_H