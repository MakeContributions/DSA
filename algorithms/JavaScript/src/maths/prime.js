//Determine whether a number is prime

function prime(num) {
    if(num===1) return false //1 is not a prime number
    if(num===2) return true  //2 is a prime number

    for (let i = 2; i < num; i++) {
        if(num%i ===0) return false 
        //loop through all digits before the number, it should only be divisible by 1 and itself,
        //so all iterations of this loop should return a remainder for a prime number
    }
    return true
}

//Time complexity: O(n). In the worst case, we have to loop through almost all digits before the number provided

// sample inputs                expected answer
console.log(prime(27))          //false
console.log(prime(31))          //true
console.log(prime(1051))        //true