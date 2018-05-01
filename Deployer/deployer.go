package main

import (
	"fmt"
	"log"
	"os"
	"os/exec"
	"strconv"

	"github.com/urfave/cli"
)

// IsDebugging returns true if Deployer is running for debugging purposes.
var IsDebugging = false

func main() {
	app := cli.NewApp()
	app.Name = "Strive Deployer"
	app.Usage = "Easily deploy Strive content!"
	app.Commands = []cli.Command{
		{
			Name:   "server",
			Action: server,
			Flags: []cli.Flag{
				cli.StringFlag{
					Name:  "debug",
					Value: "false",
					Usage: "Set whether the command is running for debugging purposes or not",
				},
			},
		},
	}

	err := app.Run(os.Args)

	if err != nil {
		log.Fatal(err)
	}
}

func server(c *cli.Context) error {
	if c.String("debug") == "true" {
		IsDebugging = true
	}

	buildVersion := GetBuildVersion()
	newBuildVersion, err := getNewBuildVersion(buildVersion)

	if err != nil {
		log.Fatal(err)
	}

	shouldDeploy := askForConfirmation(
		GetBuildName() + " will be deployed with version " + StringifyInt(newBuildVersion) + " to region " + GetBuildAWSRegion() + ". You sure? (default 'yes')",
	)

	if shouldDeploy {
		command := "aws"
		arguments := []string{
			"gamelift",
			"upload-build",

			"--name",
			GetBuildName(),

			"--operating-system",
			GetBuildOperatingSystem(),

			"--build-root",
			GetResolvedSourcePathName(),

			"--region",
			GetBuildAWSRegion(),

			"--build-version",
			"v" + StringifyInt(newBuildVersion),
		}

		commandOutput, err := exec.Command(command, arguments...).CombinedOutput()

		if err != nil {
			fmt.Println(string(commandOutput[:]))
			os.Exit(1)
		}

		fmt.Println("Cool. Deployed successfully.")
		WriteNewBuildVersion(newBuildVersion)

		return nil
	}

	fmt.Println("Ok. Nothing will be deployed.")

	return nil
}

func getNewBuildVersion(oldBuildVersion string) (int, error) {
	oldBuildVersionInt, err := strconv.Atoi(oldBuildVersion)

	if err != nil {
		return 0, err
	}

	newBuildVersionInt := oldBuildVersionInt + 1

	return newBuildVersionInt, nil
}
