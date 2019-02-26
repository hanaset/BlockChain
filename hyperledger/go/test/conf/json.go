package main

import (
	"fmt"
	"encoding/json"
	"os"
	"io/ioutil"
)

type PeerConf struct{
	ID string `json:"id"`
	Log_Path string `json:"log_path"`
	Peer_Info Peer_info `json:"peer_info"`
	Network_deploy Network_deploy `json:"network_deploy"`
}

type Peer_info struct{
	Endorser Endorser `json:"endorser"`
}

type Endorser struct{
	Node Node `json:"node"`
}

type Node struct{
	Listen string `json:"listen"`
	Max_pool_req int `json:"max_pool_req"`
	Min_pool_req int `json:"min_pool_req"`
	Max_pool_res int `json:"max_pool_res"`
	Min_pool_res int `json:"min_pool_res"`
}

type Network_deploy struct{
	Peers []Peer `json:"peers"`
	Orderers []Orderer `json:"orderers"`
}

type Peer struct{
	ID string `json:"id"`
	IP string `json:"ip"`
	Admin_listen string `json:"admin_listen"`
	Endorsor_listen string `json:"endorsor_listen"`
	Chaincode_listen string `json:"chaincode_listen"`
}

type Orderer struct{
	ID string `json:"id"`	
	IP string `json:"ip"`
	Listen string `json:"listen"`
}


func main(){

	jsonFile, err := os.Open("sample.json")

	if err != nil{
		fmt.Println(err)
	}

	defer jsonFile.Close()

	var peerconf PeerConf

	byteValue, _ := ioutil.ReadAll(jsonFile)

//	var result map[string]interface{}
//	json.Unmarshal([]byte(byteValue), &result)
	json.Unmarshal([]byte(byteValue), &peerconf)

//	fmt.Println(result["network_deploy"])

	fmt.Println(peerconf)

}
