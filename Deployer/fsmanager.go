package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"os"
)

// BuildManifest is the object containing the build details
type BuildManifest struct {
	Key BuildDetails `json:"build"`
}

// BuildDetails is the object containing the information of the build to deploy to GameLift
type BuildDetails struct {
	Name            string `json:"name"`
	OperatingSystem string `json:"os"`
	SourcePath      string `json:"sourcePath"`
	AWSRegion       string `json:"AWSRegion"`
	Version         string `json:"version"`
}

func getBuildDetails() BuildDetails {
	raw, err := ioutil.ReadFile(getManifestFilePathName())

	if err != nil {
		fmt.Println(err.Error())
		os.Exit(1)
	}

	var buildManifest BuildManifest

	json.Unmarshal(raw, &buildManifest)

	return buildManifest.Key
}

// GetBuildName gets the name of the build to deploy.
func GetBuildName() string {
	return getBuildDetails().Name
}

// GetBuildOperatingSystem gets the target operating system of the build to deploy.
func GetBuildOperatingSystem() string {
	return getBuildDetails().OperatingSystem
}

// GetBuildSourcePath gets the source path of where the build is located.
func GetBuildSourcePath() string {
	return getBuildDetails().SourcePath
}

// GetBuildAWSRegion gets the region to where the build must be deployed on AWS/GameLift.
func GetBuildAWSRegion() string {
	return getBuildDetails().AWSRegion
}

// GetBuildVersion gets the current version of the build deployment.
func GetBuildVersion() string {
	return getBuildDetails().Version
}

// WriteNewBuildVersion writes to disc the new deployed build version.
func WriteNewBuildVersion(newBuildVersion int) error {
	newBuildVersionString := StringifyInt(newBuildVersion)
	newManifestJSONString := `
		{
			"build": {
				"name": "` + GetBuildName() + `",
				"os": "` + GetBuildOperatingSystem() + `",
				"sourcePath": "` + GetBuildSourcePath() + `",
				"AWSRegion": "` + GetBuildAWSRegion() + `",
				"version": "` + newBuildVersionString + `"
			}
		}
	`
	buildManifest := BuildManifest{}
	err := json.Unmarshal([]byte(newManifestJSONString), &buildManifest)

	if err != nil {
		return err
	}

	buildManifestJSON, _ := json.MarshalIndent(&buildManifest, "", "  ")
	err = WriteManifest(buildManifestJSON)

	return err
}

// WriteManifest writes a new deploy.json file based on a given content.
func WriteManifest(content []byte) error {
	err := ioutil.WriteFile(getManifestFilePathName(), content, 0644)

	return err
}

func getThisFileDirectory() string {
	dir, err := os.Getwd()

	if err != nil {
		log.Fatal(err)
	}

	return dir
}

func getManifestFilePathName() string {
	const fileName string = "deployer.json"

	if IsDebugging {
		return getThisFileDirectory() + "/../" + fileName
	}

	return "./deployer.json"
}

// GetResolvedSourcePathName gets the correct path where the source is located at.
func GetResolvedSourcePathName() string {
	if IsDebugging {
		return getThisFileDirectory() + "/../" + GetBuildSourcePath()
	}

	return GetBuildSourcePath()
}
