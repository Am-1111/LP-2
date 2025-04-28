# Simple Medical Suggestion Bot (Number Based)

print("Select your symptom:")
print("1. Fever")
print("2. Cough")
print("3. Body Pain")
print("4. Headache")
print("5. Other")

choice = int(input("Enter your choice (1-5): "))

if choice == 1:
    print("Suggestion: Please visit a General Physician at City Care Hospital.")
elif choice == 2:
    print("Suggestion: You should visit the Chest and Respiratory Clinic.")
elif choice == 3:
    print("Suggestion: Visit the Orthopedic Department at Health First Hospital.")
elif choice == 4:
    print("Suggestion: You can consult a Neurologist at Brain & Spine Center.")
elif choice == 5:
    print("Suggestion: Kindly visit a General Practitioner nearby for a proper checkup.")
else:
    print("Invalid choice! Please select a number between 1 to 5.")
