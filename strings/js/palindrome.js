// JavaScript Palindrome Checker: Checks whether a word is the same in reverse. Ignores punctuation, capitalization & spaces.

function isPalindrome(str) {
    // First convert the string into proper alphanumeric word
    let properStr = str
        .replace(/[_\W]/g, "")
        .toLowerCase();
    
    // Now reverse the proper string
    let reverseStr = properStr
        .split("")
        .reverse()
        .join("");
    
    // Finally compare the proper string and reverse string and return true or false
    return properStr === reverseStr;
}

// Output to the console
console.log(isPalindrome("eye"));
console.log(isPalindrome("Mr. Owl ate my metal worm"));
console.log(isPalindrome("RAce C*_aR"));
