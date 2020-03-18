#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cctype>
#include <thread>
#include <chrono>
#include "mqtt/async_client.h"

using namespace std;

const string SERVER_ADDRESS	{ "tcp://broker.mqttdashboard.com:1883" };
const string CLIENT_ID		{ "async_consume" };
const string TOPIC 			{ "topic/voice_recog" };

const int  QOS = 1;

/////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	mqtt::connect_options connOpts;
	connOpts.set_keep_alive_interval(20);
	connOpts.set_clean_session(true);

	mqtt::async_client cli(SERVER_ADDRESS, CLIENT_ID);

	try {
		cout << "Connecting to the MQTT server..." << flush;
		cli.connect(connOpts)->wait();
		cli.start_consuming();
		cli.subscribe(TOPIC, QOS)->wait();
		cout << "OK" << endl;

		// Consume messages

		while (true) {
			auto msg = cli.consume_message();
			if (!msg) break;
			cout << msg->get_topic() << ": " << msg->to_string() << endl;
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