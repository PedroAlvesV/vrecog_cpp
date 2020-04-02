#include "userKeyElement.hpp"

void userKeyElement::add_key(std::string newKey){
   std::string* newKeySet = NULL;
   newKeySet = new std::string[this->total_keys+1];
   if(this->total_keys > 0){
      for(int i=0; i<this->total_keys; i++){
         newKeySet[i] = this->key[i];
      }
      delete [] this->key;
      this->key = NULL;
   }
   newKeySet[this->total_keys] = newKey;
   this->total_keys = this->total_keys + 1;
   this->key = newKeySet;
}
