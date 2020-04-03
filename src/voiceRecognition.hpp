#ifndef VRECOG_H_INCLUDED
#define VRECOG_H_INCLUDED

#include "json.hpp"
using json = nlohmann::json;

class voiceRecognition {
   private:
      bool run;
      void handler();
   public:
      void startModule();
      void setUserKeyList(json);
      void stopModule();
};

#endif
