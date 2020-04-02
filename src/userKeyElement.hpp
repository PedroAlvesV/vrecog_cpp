#ifndef USERKEYELEMENT_H_INCLUDED
#define USERKEYELEMENT_H_INCLUDED

#include <string>

class userKeyElement {
   public:
      std::string user;
      std::string* key = NULL;
      int total_keys = 0;
      void add_key(std::string newKey);
};

#endif
