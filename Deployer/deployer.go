package main

import (
	"fmt"
	"log"
	"os"
	"os/exec"
	"strconv"

	"github.com/urfave/cli"
)

// AWSRegion is one of the available AWS regions.
type AWSRegion string

const (
	// SAEast1 is the region corresponding to AWS' "sa-east-1"
	SAEast1 AWSRegion = "sa-east-1"
)

// UploadBuildOptions is a type containing the needed information to deploy to AWS/GameLift.
type UploadBuildOptions struct {
	Name            string
	OperatingSystem string
	RootPath        string
	AWSRegion       AWSRegion
}

func main() {
	app := cli.NewApp()
	app.Name = "Strive Deployer"
	app.Usage = "Easily deploy Strive content!"
	app.Commands = []cli.Command{
		{
			Name:   "server",
			Action: server,
		},
	}
	app.Flags = []cli.Flag{
		cli.StringFlag{
			Name:  "env",
			Value: "development",
			Usage: "Set the target environment of the deployment",
		},
	}

	err := app.Run(os.Args)

	if err != nil {
		log.Fatal(err)
	}
}

func server(c *cli.Context) error {
	CurrentUploadBuildOptions := UploadBuildOptions{
		Name:            "StriveAlpha",
		OperatingSystem: "WINDOWS_2012",
		RootPath:        "\".\\WindowsServer\"",
		AWSRegion:       SAEast1,
	}

	buildVersion := GetBuildVersion()
	newBuildVersion, err := getNewBuildVersion(buildVersion)

	if err != nil {
		log.Fatal(err)
	}

	shouldProceed := askForConfirmation("A server build will be deployed with version " + Stringify(newBuildVersion) + ". You sure? (default 'yes')")

	if shouldProceed {
		deployCommandString := "gamelift upload-build" +
			" --operating-system " + CurrentUploadBuildOptions.OperatingSystem +
			" --build-root " + CurrentUploadBuildOptions.RootPath +
			" --name " + CurrentUploadBuildOptions.Name +
			" --region " + string(CurrentUploadBuildOptions.AWSRegion) +
			" --build-version v" + Stringify(newBuildVersion)

		commandOutput, err := exec.Command("aws", deployCommandString).Output()

		if err != nil {
			log.Fatal(err.Error())
		}

		fmt.Println(commandOutput)

		return nil
	}

	fmt.Println("Ok. Nothing will be deployed.")

	return nil

	// err = WriteNewBuildVersion(newBuildVersion)

	// if err != nil {
	// 	log.Fatal(err)
	// }

	// return nil
}

func getNewBuildVersion(oldBuildVersion string) (int, error) {
	oldBuildVersionInt, err := strconv.Atoi(oldBuildVersion)

	if err != nil {
		return 0, err
	}

	newBuildVersionInt := oldBuildVersionInt + 1

	return newBuildVersionInt, nil
}

func reportUnexpectedError(e error) {
	log.Fatal(e)
}
