import json

# Data to be written
dictionary = {}

EPIC ="EPIC" # OS
FEATURE = "FEATURE" # Linux
STORY = "STORY" # GDB
ITEM = "ITEM" # usage or notes
NAME = "NAME"

# dictionary[EPIC] = "OS Operating system"
# dictionary[FEATURE] = "Linux"
# dictionary[STORY] = "gdb"
# dictionary[ITEM] = "used for debugging"

dictionary["OS Operating system"] = [{"Linux": [{"gdb": "used for debugging"}]}]
# dictionary[FEATURE] = "Linux"
# dictionary[STORY] = "gdb"
# dictionary[ITEM] = "used for debugging"


masterDictionary = []

masterDictionary.append(dictionary)


# Serializing json
json_object = json.dumps(masterDictionary, indent=4)

# Writing to sample.json
with open("data.json", "w") as outfile:
	outfile.write(json_object)
