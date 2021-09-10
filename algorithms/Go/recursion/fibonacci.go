package recursion
import "fmt"
/*
Time: O(2^n) 
Space: O(n) - call stack
*/
func fibonacci_using_recursion(n int) int {
	if n == 2{
		return 1
	}
	if n == 1{
		return 0;
	}
	return fibonacci_using_recursion(n-1) + fibonacci_using_recursion(n-2)
}

/*
Time: O(N)
Space: O(1)
*/
func fibonacci_using_constant_space(n int) int{
	first:= 0
	second:= 1
	
	for i := 3; i<= n; i++{
		next:= first + second
		first = second
		second = next
	}
	
	if n > 1{
		return second
	}
	return first	// this handles n == 1 or n == 0 case
}

func run_fibonacci(){
	n := 10
	recursionValue := fibonacci_using_recursion(n)
	nonrecursionValue := fibonacci_using_constant_space(n)
	fmt.Printf("Recursion value: %d\n", recursionValue)
	fmt.Printf("Non-recursion value: %d\n", nonrecursionValue)
}