// Sample Input and Output: 
// 56 15
/* The GCD of 56 and 15 is 1
   56 * -4 + 15 * 15 = 1   */
#include <iostream>
#include <vector>

using namespace std ; 

// Input: None 
// Output: A 2 by 2 Identity Matrix
vector<vector<int> > Identity()
{
    vector<vector<int> > out ; 
    vector<int> row;
    row.push_back(1) ; 
    row.push_back(0) ; 
    out.push_back(row) ; 
    row[0] = 0 ; 
    row[1] = 1 ; 
    out.push_back(row) ; 
    return out ; 
} 

// Input: positive integers a and b
// Output: a vector containing the integers x and y such that ax + by = GCD(a, b) and the GCD of a and b
//         vector is of the format [x, y, GCD(a, b)] 
// Explanation: Function performs the Extended Euclidean Algorithm. This utililizes linear algebra to solve the Bezout Identity.
//              Start the algorithm by augmenting the 2 by 2 identity matrix xy to the column vector r of the 2 remainders such 
//              that xy*[a, b] = r. Therefore, you begin with the system of two equations such that 1*a+0*b=a and 0*a+1*b=b
//              which is obviously true. From there, the algorithm iteratively performs row operations on the two rows based on 
//              which row has a larger remainder until a remainder is 0. Each row operation is subtracting the quotient q * smaller
//              row to get the new remainder and the last one before a remainder is 0 is the GCD of the two starting remainders. 
//              Further since xy*[a,b]=r still is unchanged after row operations, the solution for Bezout's Identity is the row 
//              that isn't the 0 remainder. 
vector<int> EEA(int a, int b)
{
    vector<vector<int> > xy = Identity() ; // start with the Identity matrix to perform operations on 

    // initialize the remainder vector r 
    vector<int> r ;
    r.push_back(a) ; 
    r.push_back(b) ;  
    
    //allocate memory for the quotient q
    int q = 0 ; 

    // while no remainder is 0 
    while (r[0] != 0 && r[1] != 0)
    {
        if (r[0] > r[1]) // if row 1 remainder is larger than row 2
        {
            q = r[0] / r[1] ; // get the quotient value 
            // subtract q*row 2 from row 1 and update the values in row 1 to the result on matrix and remainder vector
            r[0] -= (q * r[1]) ;  
            xy[0][0] -= (q * xy[1][0]) ; 
            xy[0][1] -= (q * xy[1][1]) ;  
        }
        else // row 2 remainder is larger than row 1 
        {
            q = r[1] / r[0] ; // get the quotient value 
            // subtract q*row 1 from row 2 and update the values in row 2 to the result on matrix and remainder vector
            r[1] -= (q * r[0]) ; 
            xy[1][0] -= (q * xy[0][0]) ; 
            xy[1][1] -= (q * xy[0][1]) ; 
        }
    }

    // declare variables for elements of the output vector 
    int x, y, gcd ; 
    
    // if row 1 has a remainder 0, then row 2 is the solution 
    if (r[0] == 0)
    {
        x = xy[1][0] ; // x is the first col
        y = xy[1][1] ; // y is the second col 
        gcd = r[1] ;  // gcd is the solution r
    } // otherwise the solution is row 1 because row 2 is equal to 0 zero 
    else
    {
        x = xy[0][0] ; // x is the first col
        y = xy[0][1] ; // y is the second col
        gcd = r[0] ; // gcd is the solution r
    }

    //prepare output vector for return 
    vector<int> out ; 
    out.push_back(x) ; 
    out.push_back(y) ; 
    out.push_back(gcd) ; 

    return out ; 
}

int main(int argc, char **argv)
{
    cout << "Enter two positive integers: " ; 
    int a, b ;
    cin >> a >> b ;
    vector<int> out = EEA(a, b) ; 
    cout << "The GCD of " << a << " and " << b << " is " << out[2] << endl ; 
    cout << a << " * " << out[0] << " + " << b << " * " << out[1] << " = " << out[2] << endl ;
}