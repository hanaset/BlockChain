package config

import (
	"fmt"
	"os"
	"io/ioutil"
)

type Network_deploy struct{
	Peers []Peer `json:"peers"`
	Orderers []Orderer `json:"orderers"`
}

type Peer struct{
	ID string `json:"id"`
	IP string `json:"ip"`
	IP2 string `json:"ip2"`
	Admin_listen string `json:"admin_listen"`
	Endorsor_listen string `json:"endorsor_listen"`
	Chaincode_listen string `json:"chaincode_listen"`
}

type Orderer struct{
	ID string `json:"id"`
	IP string `json:"ip"`
	Listen string `json:"listen"`
}

func JsonLoadFile(Path string)[]byte{
	jsonFile, err := os.Open(Path)

	if err != nil{
		fmt.Println(err)
	}

	byteValue, _ := ioutil.ReadAll(jsonFile)
	
	return byteValue

}
