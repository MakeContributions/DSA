// JavaScript Program to Left Rotate a String

function rightRotate(string) {
    // Consider the state of string to be "captain america" through the below steps of explanation

    //We initially convert the string to character array as below.
    let stringBuffer = string.split('');
    // stringBuffer--Has--> ['c','a','p','t','a','i','n',' ','a','m','e','r','i','c','a']


    if (stringBuffer.length > 0) {
        //We now check if the array has any elements before taking the last element out as a good practice.
        // We do this by using pop operator which removes the last element of an array and returns it
        var shiftElement = stringBuffer.pop();
        //shiftElement--Has--> 'a' and stringBuffer--Has-->['c','a','p','t','a','i','n',' ','a','m','e','r','i','c']

        //We now append the element into the beginning of the array using unshift operator which adds elements towards the beginning of the array
        stringBuffer.unshift(shiftElement);
        //stringBuffer--Has--> ['a','c','a','p','t','a','i','n',' ','a','m','e','r','i','c']

        //We now convert the character array back to string and return it.
        let rightRotatedString = stringBuffer.join('');
        //rightRotatedString--Has--> "acaptain americ"

        //We return the rotated String
        return rightRotatedString;
    } else {
        //If the passed string is empty, we pass an empty string too!
        return "";
    }

}

console.log(rightRotate("captain america"));
//should output acaptain americ
console.log(rightRotate("money"));
//should output ymone
console.log(rightRotate(""));
//should output  ('')