package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"os"
)

// DeployManifest is a struct
type DeployManifest struct {
	BuildVersion string `json:"version"`
}

func getManifest() DeployManifest {
	raw, err := ioutil.ReadFile("./deploy.json")

	if err != nil {
		fmt.Println(err.Error())
		os.Exit(1)
	}

	var manifest DeployManifest

	json.Unmarshal(raw, &manifest)

	return manifest
}

// GetBuildVersion gets the current version of the build deployment.
func GetBuildVersion() string {
	return getManifest().BuildVersion
}

// WriteNewBuildVersion writes to disc the new deployed build version.
func WriteNewBuildVersion(newBuildVersion int) error {
	newBuildVersionString := Stringify(newBuildVersion)
	newManifestJSONString := `
		{
			"version": "` + newBuildVersionString + `"
		}
	`
	deployManifest := DeployManifest{}
	err := json.Unmarshal([]byte(newManifestJSONString), &deployManifest)

	if err != nil {
		return err
	}

	deployManifestJSON, _ := json.Marshal(&deployManifest)
	err = ioutil.WriteFile("./deploy.json", deployManifestJSON, 0644)

	return err
}
