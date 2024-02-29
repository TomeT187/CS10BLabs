#include "IntList.h"

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList(){
    clear();
}
void IntList::clear(){
    while(!empty()){
        pop_front();
    }
}

void IntList::push_front(int value){
    if(!empty()){
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


IntList::IntList(const IntList &cpy){
        cout << cpy << endl;
        if((cpy.head != nullptr)){
            cout << 1;
            cout << 2;
            IntNode* temp = cpy.head;
            clear();
            while(temp != nullptr){

                push_back(temp->value);
                temp = temp->next;
            }
        }else{
            this->head = nullptr;
        }


}



IntList& IntList::operator=(const IntList &rhs){
    if (this != & rhs){
        clear();
        IntNode* temp = rhs.head;
        while(temp != nullptr){
            this->push_back(temp->value);
            temp = temp->next;
        }
    }
    return *this;
}

void IntList::push_back(int value){
    IntNode* temp = new IntNode(value);
    if(!empty()){
        tail->next = temp;
        tail = temp;
    }else{
        head = temp;
        tail = temp;//could be written better, idc
    }
}

void IntList::selection_sort(){
    if(!empty()){
        int minVal;
        IntNode* minPtr;
        int temp;
        for(IntNode* i = head; i->next != nullptr; i = i->next){
            minVal = i->value;
            minPtr = i;
            temp = minVal;
            for(IntNode* curr = i; curr != nullptr; curr = curr->next){
                if(curr->value < minVal){
                    minVal = curr->value;
                    minPtr = curr;
                }
            }
            if (i != minPtr){
                temp = i->value;
                i->value = minVal;
                minPtr->value = temp;
            }
        }
    }
}

void IntList::insert_ordered(int value){//there is probably a better way to do this
    if(empty()){                        //if no elements
        push_back(value);
    }else if(head->next == nullptr){    //if one element
        if(head->value > value){
            push_front(value);
        }else{
            push_back(value);
        }
    }else if(head->next->next == nullptr){//if two elements
        if(head->value > value){
            push_front(value);
        }else if(tail->value < value){
            push_back(value);
        }else{
            IntNode* newNode = new IntNode(value);
            head->next = newNode;
            newNode->next = tail;
        }
    }else{                               //else 
        IntNode* newNode = new IntNode(value);//there is definitely a better way to do this
        IntNode* low = head;
        IntNode* high = head->next;
        for(IntNode* curr = head; (curr != nullptr) ; curr = curr->next){//((curr->value < value) && )
            if(curr->value < value){
                low = curr;
                high = curr->next;
            }
        }
        if(high == nullptr){
            push_back(value);
            delete newNode;
        }else if(low == head){
            if(head->value > value){
                push_front(value);
                delete newNode;
            }else{
                IntNode* temp = head->next;
                head->next = newNode;
                newNode->next = temp; 
            }
        }else{
            low->next = newNode;
            newNode->next = high;
        }
    }
}

void IntList::remove_duplicates(){//todo: change  tail when needed
    IntNode* prev = head;
    for(IntNode* curr = head; (curr != nullptr) ; curr = curr->next){
        for(IntNode* i = curr; (i != nullptr) ; i = i->next){
            if (curr != i && curr->value == i->value){
                prev->next = i->next;
                if(i == tail){
                    tail = prev;
                }
                delete i;

                i=prev;
            }else{
                prev = i;
            }
        }
    }
}

ostream & operator<<(ostream & out, const IntList & rhs){
    if(rhs.head != nullptr){
        IntNode* temp = rhs.head;
        while (temp != nullptr){
            out << temp->value;
            temp = temp->next;
            if(temp != nullptr){
                out << " ";
            }           
        }
    }
    return out;
    
}