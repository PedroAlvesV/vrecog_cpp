#include <iostream>
#include "voiceRecognition.hpp"

int main(int argc, char* argv[]){
   voiceRecognition::startModule();
   voiceRecognition::setUserKeyList();
   voiceRecognition::stopModule();
   return 0;
}
