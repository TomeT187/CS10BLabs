#include "IntList.h";

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}
IntList::~IntList(){
    clear();
}
void IntList::clear(){

}
void IntList::push_front(int value){
    if(head != nullptr){
        IntNode temp(value);
        temp.next = head;
        head = &temp;

    }else{
        head = new IntNode(value);
        tail = head;
    }

}
void IntList::pop_front(){

}
bool IntList::empty() const{

}
const int & IntList::front() const{

}
const int & IntList::back() const{

}
ostream & operator<<(ostream & out, const IntList & rhs){
    IntNode* temp = rhs.head;
    bool notDone = true;
    while (notDone)
    {
        /* code */
        out << temp->value;
        if(temp == nullptr){
            out << " ";
        }
        temp = temp->next;
        notDone = temp != nullptr;
    }
    return out;
    
}