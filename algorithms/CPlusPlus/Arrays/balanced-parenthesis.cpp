#include <bits/stdc++.h>
using namespace std;

bool areBracketsBalanced (string expr) 
{

  stack < char >s;
  char x;


  // Traversing the Expression
  for (int i = 0; i < expr.length (); i++)
   if (expr[i] == '(' || expr[i] == '[' ||expr[i] == '{')
  {
   // Push the element in the stack
   s.push (expr[i]);
   continue;
  }

  // IF current current character is not opening
  // bracket, then it must be closing. So stack
  // cannot be empty at this point.
 
  if (s.empty ()) 
    return false;

switch (expr[i])
{

 case ')': // Store the top element in a
            x = s.top ();
            s.pop ();

  if (x == '{' || x == '[')
   return false;

   break;

case '}': // Store the top element in b
          x = s.top ();
          s.pop ();
   if (x == '(' || x == '[') 
    return false;
    break;
case ']': x = s.top ();
          s.pop ();
  if (x == '(' || x == '{')
     return false;
     break;
   }
 }
return (s.empty ());
}
// Driver code
int main () 
{
  string expr = "{()}[]";
 // Function call
 if (areBracketsBalanced (expr))
  cout << "Balanced";
else
  cout << "Not Balanced";
  return 0;
}

// Output:-
// Enter the brackets to check if its balanced or not : [{}] 
// Balanced
// Enter the brackets to check if its balanced or not : {]
Not Balanced
