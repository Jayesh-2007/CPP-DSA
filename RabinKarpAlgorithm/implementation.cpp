#include <iostream>
#include <string>
using namespace std;

#define d 256 // Number of character in input alphabet (ASCII)

void RabinKarpSearch(string pattern, string text, int q)
{
    int m = pattern.length();
    int n = text.length();
    int patternHash = 0;    // hash value for pattern
    int textWindowHash = 0; // hash value for text - window
    int h = 1;              // It represents the weight of the leftmost character in the current window.

    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    // calculate the hash value for the pattern and first window
    for (int i = 0; i < m; i++)
    {
        patternHash = (d * patternHash + pattern[i]) % q;
        textWindowHash = (d * textWindowHash + text[i]) % q;
    }

    // slide the pattern over the text one by one
    for (int i = 0; i <= n - m; i++)
    {
        // if hash value matches then we compare by a string
        if (patternHash == textWindowHash)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                cout << "Pattern Found at index: " << i << endl;
            }
        }

        // calculate hash form of next window
        if (i < n - m)
        {
            textWindowHash = (d * (textWindowHash - text[i] * h) + text[i + m]) % q;
            if (textWindowHash < 0)
            {
                textWindowHash = textWindowHash + q;
            }
        }
    }
}

int main()
{
    string text = "bigdataisfun";
    string pattern = "data";
    int q = 101; // A prime number

    RabinKarpSearch(pattern, text, q);

    return 0;
}