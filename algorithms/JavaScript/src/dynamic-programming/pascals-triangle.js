/*

Problem -

    Given an integer (numRows), return the first numRows of Pascal's triangle.

    Pascal's triangle - each number is the sum of the two numbers directly above it 

Example -

    Input: n = 5

    Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]

    Visualization:
        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1

Time Complexity - O(n^2) n = number of rows

Space Complexity - O(1) excluding the result array

*/

init();

function getPascalsTriangle(numRows) {

    // Base case: the tip of Pascal's triangle always starts with 1
    const pasTri = [[1]];
    
    // Start looping through the next row of Pascal's triangle until we reach the end
    for(let i = 1; i < numRows; i++) {

        // Initialize the next row of Pascal's triangle
        const nextRow = [];
        
        // Builds the next row of Pascal's triangle
        for(let j = 0; j <= i; j++) {

            // Gets the upper left and right values from the previous row
            // If the upper left or right values doesn't exist, use 0 instead
            const firstVal = pasTri[i - 1][j - 1] || 0;
            const secVal = pasTri[i - 1][j] || 0;

            // Push the new combined value to the current row of Pascal's triangle
            nextRow.push(firstVal + secVal);
        }

        // Add the next row to our original Pascal's triangle
        pasTri.push(nextRow);
    }
    
    return pasTri;
}

function testPascalsTriangle(numRows) {
    const pascalTriangle = getPascalsTriangle(numRows);

    console.log("Number of rows: ", numRows);

    printTriangle(pascalTriangle);

    console.log("Test complete!");
}

function printTriangle(pascalTriangle) {
    const SPACE = " ";

    for (let row = 0; row < pascalTriangle.length; row++) {
        const leadingSpace = SPACE.repeat(pascalTriangle.length - row - 1);
        const currentRowInTriangle = pascalTriangle[row].join(SPACE);

        console.log(leadingSpace + currentRowInTriangle);
    }
}

function init() {
    const readline = require('readline').createInterface({
        input: process.stdin,
        output: process.stdout
    });

    readline.question('Please enter the number of rows to print\n', numRows => {
        if (numRows >= 1) {
            testPascalsTriangle(numRows);
        } else {
            console.log("Please enter a valid number!");
        }

        readline.close();
    });
}