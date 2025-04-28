#include <bits/stdc++.h>
using namespace std;

int main()
{
    string userInput;

    cout << "Bot: Hello! Welcome to our store.\n";

    while (true)
    {
        cout << "You: ";
        getline(cin, userInput);

        // Convert input to lowercase
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

        if (userInput.find("hello") != string::npos)
        {
            cout << "Bot: Hello! How can I assist you today?\n";
        }
        else if (userInput.find("price") != string::npos)
        {
            cout << "Bot: The price of the product is Rs. 500.\n";
        }
        else if (userInput.find("buy") != string::npos)
        {
            cout << "Bot: Great! You can proceed to checkout on our website.\n";
        }
        else if (userInput.find("return") != string::npos)
        {
            cout << "Bot: We offer a 7-day return policy. Please keep your invoice.\n";
        }
        else if (userInput.find("bye") != string::npos || userInput.find("exit") != string::npos)
        {
            cout << "Bot: Thank you for visiting! Have a nice day!\n";
            break;
        }
        else
        {
            cout << "Bot: Sorry, I didn't understand that. Could you please rephrase?\n";
        }
    }

    return 0;
}
