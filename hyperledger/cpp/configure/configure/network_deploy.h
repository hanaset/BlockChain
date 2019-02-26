#include <iostream>
#include <jsoncpp/json/json.h>
#include <vector>

namespace config {

typedef struct Peer {
	std::string id;
	std::string ip;
	std::string admin_listen;
	std::string endorsor_listen;
	std::string chaincode_listen;
}Peer;

typedef struct Orderer {
	std::string id;
	std::string ip;
	std::string listen;
}Orderer;


class Network_deploy {

public:
	Network_deploy() {}
	virtual ~Network_deploy() {};
	std::vector<Peer> getPeers() { return _peers; }
	std::vector<Orderer> getOrderers() { return _orderers; }
	bool Serialize(Json::Value value);
	bool JsonLoadfile(std::string path);
	void Initialize();
private:
	std::vector<Peer> _peers;
	std::vector<Orderer> _orderers;
};

}