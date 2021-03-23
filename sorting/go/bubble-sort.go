package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

//Swaps two values of a slice
func Swap(sliceInt []int, indexValue int) {
	//Treats edge case
	if indexValue < len(sliceInt)-1 {
		tempValue := sliceInt[indexValue]
		sliceInt[indexValue] = sliceInt[indexValue+1]
		sliceInt[indexValue+1] = tempValue
	}
}

//Recursive implementation of Bubble sort
func bubbleSort(sliceInt []int) {
	for k := 0; k < len(sliceInt)-1; k++ {
		if sliceInt[k] > sliceInt[k+1] {
			Swap(sliceInt, k)
			bubbleSort(sliceInt)
		}
	}
}

func check(e error) {
	if e != nil {
		fmt.Println("error: ", e)
	}
}

func userInput() []int {

	sliceInt := make([]int, 0, 10)
	//Takes input from user
	fmt.Println("Type in a sequence of up to 10 integers separated by a space:")
	reader := bufio.NewReader(os.Stdin)
	scanner, err := reader.ReadString('\n')
	check(err)

	//Trims \r and \n from the user input
	scanner = strings.TrimSuffix(scanner, "\n")
	scanner = strings.TrimSuffix(scanner, "\r")

	//Splits integers and appends to sliceInt
	splitInput := strings.Split(scanner, " ")

	for i := 0; i < int(math.Min(10.0, float64(len(splitInput)))); i++ {
		userInput, err := strconv.Atoi(splitInput[i])
		check(err)
		sliceInt = append(sliceInt, userInput)
	}
	return sliceInt
}

func main() {

	//Calls userInput
	sliceInt := userInput()

	//Calls bubbleSort
	bubbleSort(sliceInt)

	//Prints the slice of integers in sorted order
	fmt.Println(sliceInt)

}
