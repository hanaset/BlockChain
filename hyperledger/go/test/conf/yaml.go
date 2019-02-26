package main

import (
        "fmt"
        "log"
	"io/ioutil"

        "gopkg.in/yaml.v2"
)


func main() {
	data, err := ioutil.ReadFile("sample.yaml");
	
	if err != nil{
		panic(err)
	}
    
        m := make(map[interface{}]interface{})
    
        err = yaml.Unmarshal([]byte(data), &m)
        if err != nil {
                log.Fatalf("error: %v", err)
        }
        fmt.Printf("--- m:\n%v\n\n", m)
    
	d, err := yaml.Marshal(&m)
        if err != nil {
                log.Fatalf("error: %v", err)
        }
        fmt.Printf("--- m dump:\n%s\n\n", string(d))
}
