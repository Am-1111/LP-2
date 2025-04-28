# Simple E-Commerce Chatbot

while True:
    user = input("You: ").lower()

    if "hello" in user:
        print("Bot: Hello! Welcome to our store. How can I assist you today?")
    
    elif "price" in user:
        print("Bot: The price of the product is Rs. 500.")
    
    elif "buy" in user:
        print("Bot: Great! You can proceed to checkout on our website.")
    
    elif "return" in user:
        print("Bot: We offer a 7-day return policy. Please keep your invoice.")
    
    elif "bye" in user or "exit" in user:
        print("Bot: Thank you for visiting! Have a nice day!")
        break
    
    else:
        print("Bot: Sorry, I didn't understand that. Could you please rephrase?")
