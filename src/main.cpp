#include <iostream>
#include <iomanip> // for setw only
#include <unistd.h> // for usleep only

#include "json.hpp"
#include "voiceRecognition.hpp"

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
   voiceRecognition vrecog;
   vrecog.setUserKeyList(userKeyList);
   vrecog.startModule();
   usleep(20*1000000); // to keep module running for 20s
   vrecog.stopModule();
   return 0;
}
