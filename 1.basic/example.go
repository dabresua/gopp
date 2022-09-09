package main

import "C"

import (
	"fmt"
)

//export Print
func Print(str string) {
	fmt.Printf("Go prints: %s\n", str)
}

func main() {
	// We need the main function to make possible
	// CGO compiler to compile the package as C shared library
}
