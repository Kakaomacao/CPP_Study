//--------------------------------------------------------------------
//
//  Laboratory 5 (In-lab 3 shell)                          delim.cs
//
//  Program validates delimiter pairing.
//
//--------------------------------------------------------------------

#include <string>
#include "stacklnk.cpp"

//--------------------------------------------------------------------
//
//  Function prototype

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------

int main(void)
{
    string inputLine;            // Input line
    char ch;                     // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line 
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }
    
        if( ! cin )              // Reached EOF: stop processing
            break;

        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}


bool delimitersOk(const string& expression)
// 일단 여는 괄호만 넣기
// 닫는 괄호 만나면 여는거 pop
{
    Stack<char> test;
    
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '(' || expression[i] == '[')
        {
            test.push(expression[i]);
        }

        switch (expression[i])
        {
        case ')':
            if (test.pop() == '(')
                continue;
            else
                return false;
            break;

        case ']':
            if (test.pop() == '[')
                continue;
            else
                return false;
            break;
        }
    }

    return true;
}