#include "network_deploy.h"

int main() {
	
	config::Network_deploy temp;
	temp.initialize("sample.json");


	std::cout << "Peers-----------" << std::endl;
	for (int i = 0; i < temp.getPeers().size(); i++)
	{
		std::cout << "id:" + temp.getPeers()[i].id << std::endl;
		std::cout << "ip:" + temp.getPeers()[i].ip << std::endl;
		std::cout << "listen1:" + temp.getPeers()[i].admin_listen << std::endl;
		std::cout << "listen2:" + temp.getPeers()[i].endorsor_listen << std::endl;
		std::cout << "listem3:" + temp.getPeers()[i].chaincode_listen << std::endl << std::endl;
	}


	std::cout << "Orderes---------" << std::endl;
	for (int i = 0; i < temp.getOrderers().size(); i++)
	{
		std::cout << "id:" + temp.getOrderers()[i].id << std::endl;
		std::cout << "ip:" + temp.getOrderers()[i].ip << std::endl;
		std::cout << "listen1:" + temp.getOrderers()[i].listen << std::endl;
	}

	return 0;
}