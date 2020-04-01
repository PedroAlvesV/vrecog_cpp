#include <iostream>
#include <future>
#include "voiceRecognition.hpp"

#include <unistd.h>

int main(int argc, char* argv[]){
   voiceRecognition::setUserKeyList();
   std::future<void> _ = std::async(voiceRecognition::startModule);
   usleep(20*1000000); // sleep for 20s
   voiceRecognition::stopModule();
   return 0;
}
