// The Palindrome Algorithm
// this takes in a string and returns a boolean equal to the result of
// whether the program is palindrome or not.
fn palindrome(s: &str) -> bool {
    // char vector to keep the normal string
    let string: Vec<char> = s.chars().collect();
    // char vector to keep the reverse string
    let mut reverse: Vec<char> = Vec::new();
    // reverse the string and hold it in reverse.
    for ch in &string {
        reverse.insert(0, *ch);
    }
    // return whether the reverse and the normal matches
    return string == reverse;
}

// a utility function to check the result of palindrome function
fn check_palindrome(s: &str) {
    if palindrome(s) {
        println!("{} is a palindrome", s);
    } else {
        println!("{} is not a palindrome", s);
    }
}

// main function
fn main() {
    // string 1
    let s1 = "abba";
    // string 2
    let s2 = "abbcccbba";
    // string 3
    let s3 = "abbccbbba";
    // call check_palindrome (internally calls palindrome) for each string
    check_palindrome(s1);
    check_palindrome(s2);
    check_palindrome(s3);
}
