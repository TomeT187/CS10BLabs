#include "IntList.h"

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}
IntList::~IntList(){
    clear();
}
void IntList::clear(){
    bool done = head == nullptr;
    while(!done){
        pop_front();
        done = head == nullptr;
    }
}
void IntList::push_front(int value){
    if(head != nullptr){
        IntNode* temp = new IntNode(value);
        temp->next = head;
        head = temp;

    }else{
        head = new IntNode(value);
        tail = head;   
    }
}
void IntList::pop_front(){
    if(!empty()){
        IntNode* temp = head;
        head = head->next;
        delete temp;
    }
    
}
bool IntList::empty() const{
    return (head == nullptr);
}
const int & IntList::front() const{
    return head->value;
}
const int & IntList::back() const{
    return tail->value;
}
ostream & operator<<(ostream & out, const IntList & rhs){
    IntNode* temp = rhs.head;
    bool notDone = rhs.head != nullptr;
    while (notDone){
        out << temp->value;
        temp = temp->next;
        if(temp != nullptr){
            out << " ";
        }
        
        notDone = temp != nullptr;
    }
    return out;
    
}