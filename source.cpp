#include <iostream>
#include "hd.h"

int main(){
    List* head = nullptr;
    List* digits = nullptr;

    push_front(head, '3');
    push_front(head, 'a');
    push_front(head, 'b');
    push_front(head, '2');
    push_front(head, 'a');
    push_front(head, 'a');
    push_front(head, 'c');
    push_front(head, 'c');
    push_front(head, 'c');
    push_front(head, '8');
    push_front(head, 'f');
    push_front(head, 'a');
    push_front(head, '5');
    push_front(head, 'd');
    push_front(head, 'q');
    print_list(head);
    repeats(head);
    cout << "DELETING SAME!" << endl;
    delete_same(head);
    print_list(head);
    cout << "CREATING DIGITS LIST" << endl;
    search_nums(head, digits);
    print_list(digits);

    return 0;
}







