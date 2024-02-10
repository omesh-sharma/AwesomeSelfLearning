# from faker import Faker

# from mainsdk import FeatureExtractor

# #fake = Faker()

# # usage : filenmae.py range label_data

# import sys
# import json


# sdkObj = FeatureExtractor()

# # my_word_list = [
# # 'danish','cheesecake','sugar',
# # 'Lollipop','wafer','Gummies',
# # 'sesame','Jelly','beans',
# # 'pie','bar','Ice','oat' ]


# labels_data = sdkObj.readLabels(sys.argv[2])

# starting_recurrence = [
# 'create an offer','I want plan ','can i have plan',
# 'Can i have offer','plan','offer',
# 'plan with','offer with','offer having',
# 'plan of','offer of','I am looking for','do a recharge', 'recharge of', 'recharge for', 'offer for',
# 'pack for', 'do a recharge']

# helper = ['with', 'having', 'for']

# label_recurrence = ['month' , 'monthly', 'weekely', 'week', 'N days', 'N month', 'N months', 'N day', 'n year', 'n years', 'quaterly']

# after_services =['having service', 'service type', 'type of service', 'service type' 'service for', 'should have', 'service with', 'of service',
#                     ]

# start_sevices = ['create a service plan', 'create a service', 'Need a service type', 'can i  have service plan for',
#                  'can i have a service for', 'service having', 'i need a  service', 'looking for service',
#                  'do a recharge having service', 'recharge with service']

# label_service = ['voice', 'SMS', 'internet', 'data', 'voice and data', 'data and voice', 'sms and voice', 'voice and sms', 'sms and data', 'data and sms', 'voice sms and data', 
#     'data sms and voice', 'daily data', 'daily sms', 'daily voice', 'ott']

# start_subscription = ['with subscription', 'subscription', 'ott subscription', 'subscription of ott',
#                       'having  subscription type']

# subscription_label = ['amazon prime', 'netflix', 'amazon and netflix', 'netflix and amazon']

# after_subscription = ['subscription', 'subscription type', 'as a subscription', 'pack']

# starting_charge = ['with charge', 'for charge of', 'should charge', 'can charge', 'charges', 'charge of']

# lable_charges = ['10$', '10', 'ten']

# starting_quantitiy = ['for', 'with', 'data ', 'in', 'and', 'of', 'data of', 'with data', 'with internet pack', 'with internet']

# label_quantity = ['GB', 'MB', '1 GB', '1 MB', '434343 bytes', '4343 kb', 'unlimited', 'lifetime', 'forever', 'five gb', 'five mb']


# starting_fees = ['fees of', 'fees', 'money', 'bucks of', 'for dollar', 'and', 'also', 'cost', 'cost is', 'peak rate of', 'with peak rate']
# after_fees = ['fees', 'dollar', 'bucks', 'money', 'rs', 'rupees']
# label_fees = ['5$', '5', 'five']

# intent = ['']



# #fake.sentence()
# # 'Expedita at beatae voluptatibus nulla omnis.'

# # try_fake = [
# #     'create an offer', 'with' , 'monthly', 'occurrence', 'recurrence', 'of charge', '10$', 'for voice', 'for internet', 'for sms',
# #     'voice and data', 'data and voice', 'sma and voice', 'voice and sms', 'sms and data', 'data and sms', 'voice sms and data', 
# #     'data sms and voice']

# try_fake1 = [[starting_recurrence], [label_recurrence], [after_services], [label_service], 
#             [starting_charge], [lable_charges], [starting_quantitiy], [label_quantity]]

# try_fake2 = [[starting_recurrence], [label_recurrence], 
#              [starting_charge], [lable_charges], [starting_quantitiy], [label_quantity],
#              [after_services], [label_service], 
#             ]


# try_fake3 = [[starting_recurrence], [label_recurrence], 
#              [starting_charge], [lable_charges], [starting_quantitiy], [label_quantity],
#              [after_services], [label_service], [starting_fees], [label_fees]
#             ]

# try_fake4 = [[starting_recurrence], [label_recurrence], 
#              [starting_charge], [lable_charges], [starting_quantitiy], [label_quantity],
#              [after_services], [label_service], [after_fees], [label_fees]
#             ]

# try_fake5 = [[start_sevices], [label_service], [start_subscription], [subscription_label], [helper], [label_recurrence], 
#              [after_fees], [label_fees]
#             ]

# try_fake6 = [[start_sevices], [label_service],[start_subscription], [subscription_label], [helper], [label_recurrence], 
#               [after_fees], [label_fees], [after_services], [label_service]
#             ]


# import random

# #from textblob import TextBlob


# master_faker = [try_fake1, try_fake2, try_fake3, try_fake4, try_fake5, try_fake6]

# itr_range = sys.argv[1]

# for itr_master in master_faker:

#     for keep_on_going in range(0,int(itr_range)):
#         final_str = ''
#         for main_itr in itr_master:
#             # print(main_itr)
#             # exit()
#             for inner_itr in main_itr:
#                 rand_seed = random.randrange(0, len(inner_itr))

#                 final_str += inner_itr[rand_seed] + " "
            
#         final_str += '.'

#         final_str = final_str.replace(' .', '.')

#         #final_str = TextBlob(final_str)

#         #final_str = final_str.correct()

#         print(final_str, "\n")







# # res = fake.sentence(ext_word_list=try_fake)
# # print(res)

# # 'Oat beans oat Lollipop bar cheesecake.'





from faker import Faker

from mainsdk import FeatureExtractor

#fake = Faker()

# usage : filenmae.py range label_data

import sys
import json



units = [
"zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
"nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
"sixteen", "seventeen", "eighteen", "nineteen", "twenty"
]

sdkObj = FeatureExtractor()

# my_word_list = [
# 'danish','cheesecake','sugar',
# 'Lollipop','wafer','Gummies',
# 'sesame','Jelly','beans',
# 'pie','bar','Ice','oat' ]

TEXT = 'text'
INTENT = 'intent'
#print(sys.argv[2])
labels_data = sdkObj.readLabels(sys.argv[2])

final_lables = []

for itr in labels_data:
    
    final_lables.append(itr[TEXT])

labels_data = final_lables

starting_recurrence = [{TEXT:[
'create an offer','I want plan ','can i have plan',
'Can i have offer','plan','offer',
'plan with','offer with','offer having',
'plan of','offer of','I am looking for','do a recharge', 'recharge of', 'recharge for', 'offer for',
'pack for', 'do a recharge']}]

helper = [{TEXT:['with', 'having', 'for']}]

label_recurrence = [{f'{INTENT}*recurrance':['month' , 'monthly', 'weekely', 'week', '1 days', '1 month', '1 months', '1 day', '1 year', '1 years', 'quaterly']}]

after_services =[{TEXT:['having service', 'service type', 'type of service', 'service type', 'service for', 'should have', 'service with', 'of service',
]}]

start_sevices = [{TEXT:['create a service plan', 'create a service', 'Need a service type', 'can i  have service plan for',
                 'can i have a service for', 'service having', 'i need a  service', 'looking for service',
                 'do a recharge having service', 'recharge with service']}]

label_service = [{f'{INTENT}*service':['voice', 'SMS', 'internet', 'data', 'voice and data', 'data and voice', 'sms and voice', 'voice and sms', 'sms and data', 'data and sms', 'voice sms and data', 
    'data sms and voice', 'daily data', 'daily sms', 'daily voice', 'ott']}]

start_subscription = [{TEXT:['with subscription', 'subscription', 'ott subscription', 'subscription of ott',
                      'having  subscription type']}]

subscription_label = [{f'{INTENT}*ott_subscription':['amazon prime', 'netflix', 'amazon and netflix', 'netflix and amazon']}]

after_subscription = [{TEXT:['subscription', 'subscription type', 'as a subscription', 'pack']}]

starting_charge = [{TEXT:['with charge', 'for charge of', 'should charge', 'can charge', 'charges', 'charge of']}]

lable_charges = [{f'{INTENT}*charge':['10$', '10', 'ten']}]

starting_quantitiy = [{TEXT:['for', 'with', 'data ', 'in', 'and', 'of', 'data of', 'with data', 'with internet pack', 'with internet']}]

label_quantity = [{f'{INTENT}*quantity':['GB', 'MB', '1 GB', '1 MB', '434343 bytes', '4343 kb', 'unlimited', 'lifetime', 'forever', 'five gb', 'five mb']}]


starting_fees = [{TEXT:['fees of', 'fees', 'fee' 'money', 'bucks of', 'for dollar', 'and', 'also', 'cost', 'cost is', 'peak rate of', 'with peak rate']}]
after_fees = [{TEXT:['fees', 'fee',  'dollar', 'bucks', 'money', 'rs', 'rupees']}]
label_fees = [{f'{INTENT}*fee':['5$', '5', 'five']}]



#fake.sentence()
# 'Expedita at beatae voluptatibus nulla omnis.'

# try_fake = [
#     'create an offer', 'with' , 'monthly', 'occurrence', 'recurrence', 'of charge', '10$', 'for voice', 'for internet', 'for sms',
#     'voice and data', 'data and voice', 'sma and voice', 'voice and sms', 'sms and data', 'data and sms', 'voice sms and data', 
#     'data sms and voice']

try_fake1 = [[starting_recurrence], [label_recurrence], [after_services], [label_service], 
            [starting_charge], [lable_charges], [starting_quantitiy], [label_quantity]]

try_fake2 = [[starting_recurrence], [label_recurrence], 
             [starting_charge], [lable_charges], [starting_quantitiy], [label_quantity],
             [after_services], [label_service], 
            ]


try_fake3 = [[starting_recurrence], [label_recurrence], 
             [starting_charge], [lable_charges], [starting_quantitiy], [label_quantity],
             [after_services], [label_service], [starting_fees], [label_fees]
            ]

try_fake4 = [[starting_recurrence], [label_recurrence], 
             [starting_charge], [lable_charges], [starting_quantitiy], [label_quantity],
             [after_services], [label_service], [after_fees], [label_fees]
            ]

try_fake5 = [[start_sevices], [label_service], [start_subscription], [subscription_label], [helper], [label_recurrence], 
             [after_fees], [label_fees]
            ]

try_fake6 = [[start_sevices], [label_service],[start_subscription], [subscription_label], [helper], [label_recurrence], 
              [after_fees], [label_fees], [after_services], [label_service]
            ]


import random

#from textblob import TextBlob


master_faker = [try_fake1, try_fake2, try_fake3, try_fake4, try_fake5, try_fake6]

itr_range = sys.argv[1]


fina_lables_data = []


for itr_master in master_faker:

    for keep_on_going in range(0,int(itr_range)):
        
        final_str = '' 
        entities_list = []

        for main_itr in itr_master:
            
            
            #print(main_itr[0][0])
            #for inner_itr in main_itr[0][0].values():
            
            
            # print(main_itr[0][0])
            
            # exit()

            

            for keys_itr, inner_itr in main_itr[0][0].items():
                
        
                
                for sub_itr in inner_itr:
                    
                    rand_seed = random.randrange(0, len(inner_itr))

                    
                    intent_entry = inner_itr[rand_seed]

                    old_intent = intent_entry
                    
                    
                    for inner_ele in intent_entry:
                        
                        for inner_char in inner_ele:
                            #print(inner_char, "  %%%%")
                            if inner_char.isdigit():    
                                if 'year' in intent_entry:
                                    intent_entry = intent_entry.replace(inner_char, str(1))
                                else:
                                    seek_rand = str(random.randrange(10, 365))[1]
                                    while seek_rand == 0:
                                        seek_rand = str(random.randrange(10, 365))[1]

                                    intent_entry = intent_entry.replace(inner_char, seek_rand)
                    
                    for itr_units in units:
                        for itr_intent in intent_entry.split():
                            #print(intent_entry)
                            if itr_units.lower() == itr_intent.lower():
                                #print(itr_intent)
                                replace_seed = random.randrange(0, len(units))

                                intent_entry = intent_entry.replace(itr_intent, units[replace_seed])
                                
                            
                    
                    # if old_intent != intent_entry:
                    #     print(intent_entry)
                    #     exit()


                    final_str += intent_entry #inner_itr[rand_seed] + " "
            
                    
                    if '*' in keys_itr:
                        if keys_itr.split('*')[1] in labels_data:
                        
                            
                            res = sdkObj.findMatchedOffset(intent_entry, final_str)
                            #print(res)
                            if res:
                                entities_list.append((res[0],res[1], keys_itr.split('*')[1]))

                    break
                
                final_str += ' ' 
        final_str += '.' 
        final_str = final_str.replace(' .', '.')
        
        #final_str = final_str.correct()

        # print(final_str, "\n")

        # final_str = TextBlob(final_str)

        final_stream = (final_str, {"entities": entities_list})
    
        fina_lables_data.append(final_stream)

        #print(fina_lables_data, "\n")
        #exit()


#exit()


from datetime import date

today = date.today()

print("created data set for total text : ", len(fina_lables_data))

file_name = f"syntehsis_data_{str(today)}.json"
with open(file_name, "a+", encoding='utf-8') as data:

    data.write(json.dumps(fina_lables_data, indent=4))
    data.close()

# for itr in fina_lables_data:
#     print(itr)






# res = fake.sentence(ext_word_list=try_fake)
# print(res)

# 'Oat beans oat Lollipop bar cheesecake.'