#include <iostream>
#include <tgmath.h>
using namespace std;

string reverse(string strReversant)
{
    string reversed = "";
    for (int rvrsInd = strReversant.length() - 1; rvrsInd >= 0; rvrsInd--) //rvrsInd stands for Reversed Index
    {
        reversed += strReversant[rvrsInd];
    }
    return reversed;
}
string PowDigitSum(long long tupow)
{
    string strNum = "1";
    string result = "1";
    int holder = 0;
    for (int i = 0; i < tupow; i++) //i < tupow instead of i <= tupow because you are doing it 0...n times. And since 0 is counted, and tupow is 3 you do it 4 times causing the answer to one power higher
    {
        result = "";
        holder = 0;
        for (int i = strNum.length() - 1; i >= 1; i--)
        {
            result += to_string((strNum[i] -'0') * 2 + holder)[to_string((strNum[i] -'0') * 2 + holder).length() - 1];
            holder = ((strNum[i] - '0') * 2 + holder) / 10;
        }
        if (strNum.length() - 1 >= 1)
        {
            result += reverse(to_string((strNum[0] - '0') * 2 + holder));
            strNum = reverse(result);
        }
        else 
        {
            result += to_string((strNum[0] - '0') * 2 + holder);
            strNum = result;
        }
    }
    return reverse(result);
}
int main()
{
    int PowDigSum = 0;
    cout << PowDigitSum(1000) << "\n";
}