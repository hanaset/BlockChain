#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>
#include "org.h"

namespace config {

void Organization::Initialize() 
{
	_MSPID.clear();
	_name.clear();
	_domain.clear();
	_enableNodeOUs = false;
	_users = 0;
}

bool Organization::JsonLoadFile(std::string path)
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

bool Organization::Serialize(Json::Value value)
{
	if (value.empty())
		return false;

	_name = value["name"].asString();
	_MSPID = value["msp_id"].asString();
	_domain = value["domain"].asString();
	_enableNodeOUs = value["enable_node_organizational_units"].asBool();
	_users = value["users"].asInt();
	
	_ca = new CA[value["CA"].size()];
	for (int i = 0; i < value["CA"].size(); i++) 
	{
		_ca[i].hostname = value["CA"][i].asString();
	}
	return true;
}

}