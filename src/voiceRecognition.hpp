#ifndef VRECOG_H_INCLUDED
#define VRECOG_H_INCLUDED

#include <list>
#include "userKeyElement.hpp"

namespace voiceRecognition
{
   
	void startModule();

	void setUserKeyList(std::list<userKeyElement> userKeyList);

	void stopModule();
}

#endif
