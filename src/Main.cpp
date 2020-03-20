#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include "mqtt/async_client.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

const string SERVER_ADDRESS	{ "tcp://broker.mqttdashboard.com:1883" };
const string CLIENT_ID		{ "listener-cpp" };
const string TOPIC 			{ "topic/voice_recog" };

const int  QOS = 1;

/////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]){

	json cmdList = {
		{"command1", "Executar comando 1"},
		{"comando 2", "Executar comando 2"},
		{"play", "Iniciando"},
		{"pause", "Pausando"},
		{"desligar", "Desligando..."},
		{"test", "Executar teste"}
	};
	cout << std::setw(4) << cmdList << '\n';

	mqtt::connect_options connOpts;
	connOpts.set_keep_alive_interval(20);
	connOpts.set_clean_session(true);

	mqtt::async_client cli(SERVER_ADDRESS, CLIENT_ID);

	try {
		cout << "Connected as '" << CLIENT_ID << "' to '" << SERVER_ADDRESS << "'" << endl;
		cli.connect(connOpts)->wait();
		cli.start_consuming();
		cli.subscribe(TOPIC, QOS)->wait();

		// Consume messages

		while (true) {
			auto msg = cli.consume_message();
			if (!msg) break;
			if (!cmdList[msg->to_string()].empty())
			   cout << cmdList[msg->to_string()] << endl;
			else
			   cout << "\"" << msg->to_string() << "\" (invalid command) was received from '" << msg->get_topic() << "'" << endl;
		}

		// Disconnect

		cout << "\nShutting down and disconnecting from the MQTT server..." << flush;
		cli.unsubscribe(TOPIC)->wait();
		cli.stop_consuming();
		cli.disconnect()->wait();
		cout << "OK" << endl;
	}
	catch (const mqtt::exception& exc) {
		cerr << exc.what() << endl;
		return 1;
	}

 	return 0;
}
