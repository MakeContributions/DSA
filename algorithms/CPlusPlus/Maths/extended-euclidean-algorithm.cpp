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
// Function performs the Extended Euclidean Algorithm. This utililizes linear algebra to solve the Bezout Identity.
vector<int> EEA(int a, int b)
{
    vector<vector<int> > xy = Identity() ; // start with the Identity matrix to perform operations on 
    // initialize the remainder vector r 
    // notice how column 1 represents the value being multiplied by a and col 2 represents being multiplied by b to get each solution in r
    // therefore so far the first row has the solution 1*a + 0*b = a and the second has 0*a + 1*b = b which is true 
    vector<int> r ;
    r.push_back(a) ; 
    r.push_back(b) ;  
    
    //allocate memory for the quotient q
    int q = 0 ; 

    // while no remainder is 0 
    while (r[0] != 0 && r[1] != 0)
    {
        if (r[0] > r[1])
        {
            q = r[0] / r[1] ; // get the quotient value 
            r[0] = r[0] % r[1] ; // update the remainder 
            xy[0][0] -= (q * xy[1][0]) ; // perform row operations on matrix by subtracting q*row 2 from row 1
            xy[0][1] -= (q * xy[1][1]) ;  
        }
        else
        {
            q = r[1] / r[0] ; // get the quotient value 
            r[1] = r[1] % r[0] ; // update the remainder
            xy[1][0] -= (q * xy[0][0]) ; // perform row operations on matrix by subtracting q*row 1 from row 2
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