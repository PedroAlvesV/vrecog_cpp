#include <iostream>
#include <iomanip> // for setw only
#include <future>
#include <list>

#include "json.hpp"
#include "voiceRecognition.hpp"

#include <unistd.h> // for usleep only

using json = nlohmann::json;

int main(){
   json userKeyList = {};
   userKeyList.push_back({
      {"user", "marina"},
      {"key", {"stop"}}
   });
   userKeyList.push_back({
      {"user", "fabio"},
      {"key", {"stop", "start"}}
   });
   std::cout << std::setw(4) << userKeyList << '\n';
   /////////////////////////////////////////////
   voiceRecognition::setUserKeyList(userKeyList);
   std::future<void> _ = std::async(voiceRecognition::startModule);
   usleep(20*1000000); // to keep module running for 20s
   voiceRecognition::stopModule();
   return 0;
}
