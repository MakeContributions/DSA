#include <iostream>
using namespace std;

// सम फ़ंक्शन का विवरण
int Sum(int a, int b)
{
  // अगर 'a' शून्य है, तो 'b' को वापस लौटाएं
  if (a == 0)
    return b;
  // अगर 'b' शून्य है, तो 'a' को वापस लौटाएं
  else if (b == 0)
    return a;

  // अन्यथा, a और b के योग को वापस लौटाएं
  else
    return a + b;
}

int main()
{
  // नंबर्स इनिटियलाइज करें
  int x, y, Result;

  // उपयोगकर्ता से इनपुट लें
  cout << "\n2 नंबर्स दर्ज करें:";
  cin >> x >> y;

  // सम को कॉल करें और परिणाम प्रिंट करें
  Result = Sum(x, y);
  cout << "\nयोग = " << Result;

  return 0;
}
