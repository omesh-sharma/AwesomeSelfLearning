import spacy
from faker import Faker

# Load spaCy's English NLP model
nlp = spacy.load("en_core_web_sm")

# Initialize Faker to generate fake data
fake = Faker()

def generate_plan_data(sentence):
    # Parse the user's sentence with spaCy
    doc = nlp(sentence)

    # Initialize variables for plan attributes
    plan_name = ""
    data_limit = ""
    talk_time = ""
    validity = ""

    # Extract information from the parsed sentence
    for token in doc:
        if "plan" in token.text.lower() and token.dep_ == "nsubj":
            plan_name = token.text
        elif "data" in token.text.lower():
            data_limit = fake.random_int(min=1, max=30)  # Fake data limit in GB
        elif "talk" in token.text.lower() and "time" in doc.text.lower():
            talk_time = fake.random_int(min=100, max=1000)  # Fake talk time in minutes
        elif "validity" in token.text.lower():
            validity = fake.random_int(min=1, max=30)  # Fake validity in days

    # Generate a synthetic prepaid plan sentence
    generated_sentence = f"{plan_name} offers {data_limit}GB data, {talk_time} minutes talk time, and {validity} days validity."

    return generated_sentence

# Example usage
user_sentence = "I want a prepaid plan with unlimited data and 300 minutes talk time."
synthetic_data = generate_plan_data(user_sentence)
print(synthetic_data)
