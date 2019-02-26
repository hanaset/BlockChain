package config


type ChaincodeInfo struct{
	Name string `json:"name"`
	Version string `json:"version"`
	Path string `json:"path"`
	Input string `json:"input"`
	Escc string `json:"escc"`
	Vscc string `json:"vscc"`
	Id []byte `json:"id"`
	// XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized []byte `json:"-"`
	XXX_sizecache int32 `json:"-"`
}