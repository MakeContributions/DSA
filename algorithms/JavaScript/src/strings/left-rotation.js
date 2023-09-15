// JavaScript Program to Left Rotate a String

function leftRotate(string) {
    // Consider the state of string to be "captain america" through the below steps of explanation

    //We initially convert the string to character array as below.
    let stringBuffer = string.split('');
    // stringBuffer--Has--> ['c','a','p','t','a','i','n',' ','a','m','e','r','i','c','a']


    if (stringBuffer.length > 0) {
        //We now check if the array has any elements before taking the first element out as a good practice.
        // We do this by using shift operator which removes the first element of an array and returns it
        var shiftElement = stringBuffer.shift();
        //shiftElement--Has--> 'c' and stringBuffer--Has-->['a','p','t','a','i','n',' ','a','m','e','r','i','c','a']

        //We now append the element into the end of the array using push operator which adds elements towards the end of the array
        stringBuffer.push(shiftElement);
        //stringBuffer--Has--> ['a','p','t','a','i','n',' ','a','m','e','r','i','c','a','c']

        //We now convert the character array back to string and return it.
        let leftRotatedString = stringBuffer.join('');
        //leftRotatedString--Has--> "aptain americac"

        //We return the rotated String
        return leftRotatedString;
    } else {
        //If the passed string is empty, we pass an empty string too!
        return "";
    }

}

console.log(leftRotate("captain america"));
//should output captain americac
console.log(leftRotate("money"));
//should output captain oneym
console.log(leftRotate(""));
//should output  ('')