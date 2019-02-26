#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>
#include "chaincodeinfo.h"

namespace config {


bool ChaincodeInfo::JsonLoadFile(std::string path)
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

bool ChaincodeInfo::Serialize(Json::Value value)
{
	if (value.empty())
		return false;

	_name = value["name"].asString();
	_version = value["version"].asString();
	_path = value["path"].asString();
	_input = value["input"].asString();
	_escc = value["escc"].asString();
	_vscc = value["vscc"].asString();

	return true;
}

void ChaincodeInfo::Initialize()
{
	_name.clear();
	_version.clear();
	_path.clear();
	_input.clear();
	_escc.clear();
	_vscc.clear();

}

}