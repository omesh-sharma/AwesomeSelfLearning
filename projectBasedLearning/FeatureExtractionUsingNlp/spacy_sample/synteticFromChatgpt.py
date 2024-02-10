# import pandas as pd
# import random

# # Create a list of offers
# offers = [
#     {
#         'Offer': 'Voice Service',
#         'Monthly Recurring Charge': 10,
#         'Onetime Setup Fee': 0,
#         'Data Limit': 'N/A',
#         'Voice Minutes': 'N/A',
#         'SMS Limit': 'N/A',
#         'OTT Services': 'N/A'
#     },
#     {
#         'Offer': 'Voice Service with Onetime Setup Fee',
#         'Monthly Recurring Charge': 10,
#         'Onetime Setup Fee': 5,
#         'Data Limit': 'N/A',
#         'Voice Minutes': 'N/A',
#         'SMS Limit': 'N/A',
#         'OTT Services': 'N/A'
#     },
#     {
#         'Offer': 'Data Service',
#         'Monthly Recurring Charge': 10,
#         'Onetime Setup Fee': 0,
#         'Data Limit': 'N/A',
#         'Voice Minutes': 'N/A',
#         'SMS Limit': 'N/A',
#         'OTT Services': 'N/A'
#     },
#     # Add more offers as required...

# ]

# # Create a DataFrame from the offers list
# df = pd.DataFrame(offers)

# # Print the synthetic data
# print(df)




# import random

# # List of base sentences
# base_sentences = [
#     "create an offer with monthly recurring charge of {monthly_charge}$ for {service}.",
#     "create an offer with monthly recurring charge of {monthly_charge}$ for {service} and onetime setup fee of {setup_fee}$.",
#     "create {service} offer having peak hour rate of {peak_rate}$ per minute and off peak rate of {off_peak_rate}$ per minute for charge of {monthly_charge}$",
#     "create a {data_limit} data plan with {validity} days validity having {data_limit} data limit and {voice_service} and {sms_service}.",
#     "create {monthly_fee}$ monthly plan with {data_limit} data per day and {voice_service} and {sms_limit} SMS per day.",
#     "create an offer with unlimited data between {start_time} and {end_time} everyday for monthly fee of {monthly_charge}$."
# ]

# # List of possible values for placeholders
# monthly_charges = [10, 20, 45, 2000, 300]
# setup_fees = [5]
# services = ["voice service", "data service", "SMS service", "unlimited voice service", "unlimited data service", "unlimited SMS service", "unlimited voice, data, SMS service"]
# voice_service = "unlimited voice"
# sms_service = "unlimited SMS"
# data_limit = "1 GB"
# validity = 24
# peak_rate = 1
# off_peak_rate = 0.5
# start_time = "12 AM"
# end_time = "6 AM"
# sms_limit = 100

# # Function to create synthetic sentences
# def generate_synthetic_data():
#     global data_limit
#     synthetic_data = []
#     for sentence in base_sentences:
#         if "{monthly_charge}" in sentence:
#             monthly_charge = random.choice(monthly_charges)
#             sentence = sentence.replace("{monthly_charge}", str(monthly_charge))
        
#         if "{setup_fee}" in sentence:
#             setup_fee = random.choice(setup_fees)
#             sentence = sentence.replace("{setup_fee}", str(setup_fee))
        
#         if "{service}" in sentence:
#             service = random.choice(services)
#             sentence = sentence.replace("{service}", service)

#         if "{voice_service}" in sentence:
#             voice_service = random.choice([f"{data_limit} daily data service", "60 minutes daily voice service"])
#             sentence = sentence.replace("{voice_service}", voice_service)
            
#         if "{data_limit}" in sentence:
#             data_limit = random.choice(["1 GB", "2 GB"])
#             sentence = sentence.replace("{data_limit}", data_limit)

#         if "{validity}" in sentence:
#             sentence = sentence.replace("{validity}", str(validity))

#         if "{peak_rate}" in sentence:
#             sentence = sentence.replace("{peak_rate}", str(peak_rate))

#         if "{off_peak_rate}" in sentence:
#             sentence = sentence.replace("{off_peak_rate}", str(off_peak_rate))

#         if "{start_time}" in sentence:
#             sentence = sentence.replace("{start_time}", start_time)

#         if "{end_time}" in sentence:
#             sentence = sentence.replace("{end_time}", end_time)

#         if "{sms_limit}" in sentence:
#             sentence = sentence.replace("{sms_limit}", str(sms_limit))
        
#         synthetic_data.append(sentence)
    
#     return synthetic_data

# # Generate synthetic data sentences
# synthetic_data_sentences = generate_synthetic_data()

# # Print the generated synthetic data sentences
# for sentence in synthetic_data_sentences:
#     print(sentence)



from transformers import pipeline

def paraphrase_sentence(sentence):
    # Load the paraphrasing model from Hugging Face
    paraphraser = pipeline('text2text-generation', model='facebook/bart-large-cnn')

    # Generate paraphrased versions of the sentence
    paraphrased_sentences = paraphraser(sentence, max_length=100) #, num_return_sequences=5)

    # Extract and return the paraphrased sentences from the response
    return [entry['generated_text'].strip() for entry in paraphrased_sentences]

# Example sentence to paraphrase
example_sentence = "Create an offer with a monthly recurring charge of 10$ for voice service."

# Get paraphrased versions of the example sentence
paraphrased_sentences = paraphrase_sentence(example_sentence)

# Print the original sentence and paraphrased versions
print("Original Sentence:", example_sentence)
print("Paraphrased Sentences:")
for i, sentence in enumerate(paraphrased_sentences, start=1):
    print(f"{i}.", sentence)
