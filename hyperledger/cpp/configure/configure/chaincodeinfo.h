#include <iostream>
#include <jsoncpp/json/json.h>

#define BYTE_MAX 100

namespace config {

class ChaincodeInfo {

public:
	bool JsonLoadFile(std::string path);
	bool Serialize(Json::Value value);
	void Initialize();

private:
	std::string _name;
	std::string _version;
	std::string _path;
	std::string _input;
	std::string _escc;
	std::string _vscc;
	//unsigned char _id[BYTE_MAX];
	//unsigned char _xxx_unrecognized[BYTE_MAX];
	int32_t _xxx_sizecache;
};
}
