#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

//public
bool IntList::exists(int value) const{
   return exists(head,value);
}
ostream & operator<<(ostream &out, const IntList &List){
   out << List.head;
   return out;
}
ostream & operator<<(ostream &out, IntNode *Node){
   if(Node == nullptr){
      return out;
   }
   else if(Node->next != nullptr){
      out << Node->value << " ";
      out << Node->next;
   }else{
      out << Node->value;
      return out;
   }
   return out;
}

//private
bool IntList::exists(IntNode *node, int value) const{
   if(node == nullptr){
      return false;
   }
   else if(node->next == nullptr){
      return (node->value == value);
   }else{
      if(node->value == value){
         return true;
      }else{
         return(exists(node->next,value));
      }
   }
}

