package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"log"
	"os"
	"strings"
)

// StringifyInt converts an integer into a string
func StringifyInt(n int) string {
	buf := [11]byte{}
	pos := len(buf)
	i := int(n)
	signed := i < 0

	if signed {
		i = -i
	}

	for {
		pos--
		buf[pos], i = '0'+byte(i%10), i/10

		if i == 0 {
			if signed {
				pos--
				buf[pos] = '-'
			}

			return string(buf[pos:])
		}
	}
}

func toJSON(p interface{}) string {
	bytes, err := json.Marshal(p)

	if err != nil {
		fmt.Println(err.Error())
		os.Exit(1)
	}

	return string(bytes)
}

func askForConfirmation(s string) bool {
	reader := bufio.NewReader(os.Stdin)

	for {
		fmt.Printf("%s [y/n]: ", s)

		response, err := reader.ReadString('\n')
		if err != nil {
			log.Fatal(err)
		}

		response = strings.ToLower(strings.TrimSpace(response))

		if response == "" || response == "y" || response == "yes" {
			return true
		} else if response == "n" || response == "no" {
			return false
		}
	}
}
