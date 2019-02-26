package config

type CA struct {
	HostName string `json:"hostname"`
}

type Organization struct {
	MSPID string `json:"msp_id"`
	NAME string `json:"name"`
	Domain string `json:"domain"`
	EnableNodeOUS bool `json:"enable_node_organizational_units"`
	Users int `json:"users"`
	CA *CA `json:"ca"`
}