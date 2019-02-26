#include "network_deploy.h"
#include <iostream>
#include <jsoncpp/json/json.h>
#include <fstream>

namespace config {

bool Network_deploy::JsonLoadfile(std::string path)
{
	std::ifstream stream;
	stream.open(path);

	if (stream.fail()) {
		printf("file open fail\n");
		return false;
	}
	
	Json::Value root;
	stream >> root;

	return Serialize(root);
}

bool Network_deploy::Serialize(Json::Value value)
{
	if (value.empty())
		return false;

	Json::Value peers, orderers;

	peers = value["peers"];
	orderers = value["orderers"];

	Peer peer;
	Orderer orderer;
	for (int i = 0; i < peers.size(); i++)
	{
		peer.id = peers[i]["id"].asString();
		peer.ip = peers[i]["ip"].asString();
		peer.admin_listen = peers[i]["admin_listen"].asString();
		peer.endorsor_listen = peers[i]["endorsor_listen"].asString();
		peer.chaincode_listen = peers[i]["chaincode_listen"].asString();

		_peers.push_back(peer);
	}

	for (int i = 0; i < orderers.size(); i++)
	{
		orderer.id = orderers[i]["id"].asString();
		orderer.ip = orderers[i]["ip"].asString();
		orderer.listen = orderers[i]["listen"].asString();

		_orderers.push_back(orderer);
	}

	return true;
}

void Network_deploy::Initialize()
{
	_peers.clear();
	_orderers.clear();
}

}