#include <iostream>
#include <iomanip>
#include <fstream>
#include "mqtt/async_client.h"
#include "json.hpp"
#include "voiceRecognition.hpp"

#include <atomic>

using namespace std;
using json = nlohmann::json;

const string SERVER_ADDRESS   { "tcp://broker.mqttdashboard.com:1883" };
const string CLIENT_ID        { "listener-cpp" };
const string TOPIC            { "topic/voice_recog" };
const int  QOS = 1; 
mqtt::async_client cli(SERVER_ADDRESS, CLIENT_ID);
json keyList;

namespace voiceRecognition
{   

   atomic<bool> run = {false};

   void startModule(){
      //cout << "startModule()" << endl;
      run = true;
   
      mqtt::connect_options connOpts;
      connOpts.set_keep_alive_interval(20);
      connOpts.set_clean_session(true);
      
      try {
         cout << "Connected as '" << CLIENT_ID << "' to '" << SERVER_ADDRESS << "'" << endl;
         cli.connect(connOpts)->wait();
         cli.start_consuming();
         cli.subscribe(TOPIC, QOS)->wait();

         // Consume messages
         
         while (run) {
            auto msg = cli.consume_message();
            if (!msg) break;
            
            int pos = msg->to_string().find_first_of(':');
            std::string user = msg->to_string().substr(0, pos),
                        cmd  = msg->to_string().substr(pos+1);
            
            for (auto& element : keyList["userKeyList"]) {
               if (user.compare(element["user"]) == 0) {
                  for (auto& command : element["key"]){
                     if (cmd.compare(command) == 0) {
                        cout << "User '" << user << "' ";
                        cout << "invoked command '" << cmd << "'" << endl;
                     }
                  }
               }
            }
         }

      }
      catch (const mqtt::exception& exc) {
         cerr << exc.what() << endl;
      }
      
   }

   void setUserKeyList(){//(list <user, key>){
      cout << "setUserKeyList()" << endl;
      keyList["userKeyList"] = {{}};
      keyList["userKeyList"][0] = {
         {"user", "marina"},
         {"key", {"stop", "start"}}
      };
      keyList["userKeyList"][1] = {
         {"user", "fabio"},
         {"key", {"stop"}}
      };
      cout << std::setw(4) << keyList << '\n';
   }

   void stopModule(){
      //cout << "stopModule()" << endl;
      run = false;
      
      try {
         cout << "Shutting down and disconnecting from the MQTT server..." << flush;
         cli.unsubscribe(TOPIC)->wait();
         cli.stop_consuming();
         cli.disconnect()->wait();
         cout << "OK" << endl;
      }
      catch (const mqtt::exception& exc) {
      }
   }
}
