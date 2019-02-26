#include <iostream>
#include <jsoncpp/json/json.h>
#include <vector>

namespace config {

typedef struct CA {
	std::string hostname;
}CA;

class Organization {

public:
	bool Serialize(Json::Value value);
	void Initialize();
	bool JsonLoadFile(std::string path);
private:
	std::string _MSPID;
	std::string _name;
	std::string _domain;
	bool _enableNodeOUs;
	int _users;
	CA* _ca;
};

}