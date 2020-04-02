#include <iostream>
#include <future>
#include <list>

#include "userKeyElement.hpp"
#include "voiceRecognition.hpp"

#include <unistd.h>

int main(int argc, char* argv[]){
   userKeyElement user1;
   userKeyElement user2;
   user1.user = "marina";
   user1.add_key("stop");
   user2.user = "fábio";
   user2.add_key("stop");
   user2.add_key("start");
   std::list<userKeyElement> userKeyList;
   userKeyList.push_back(user1);
   userKeyList.push_back(user2);
   /////////////////////////////////////////////
   voiceRecognition::setUserKeyList(userKeyList);
   std::future<void> _ = std::async(voiceRecognition::startModule);
   usleep(20*1000000); // sleep for 20s
   voiceRecognition::stopModule();
   return 0;
}
