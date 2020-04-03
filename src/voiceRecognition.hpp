#ifndef VRECOG_H_INCLUDED
#define VRECOG_H_INCLUDED

#include "json.hpp"
using json = nlohmann::json;

namespace voiceRecognition
{
   
	void startModule();

	void setUserKeyList(json userKeyList);

	void stopModule();
}

#endif
