import spacy
import sys
from mainsdk import FeatureExtractor
from spacy.pipeline import __all__


# for entity in doc.____:
#   print(entity.text, entity.label_)

#exit()
# Load English tokenizer, tagger, parser, NER and word vectors
nlp = spacy.load("en_core_web_sm")

# Process whole documents
# text = ("When Sebastian Thrun started working on self-driving cars at "
#         "Google in 2007, few people outside of the company took him "
#         "seriously. “I can tell you very senior CEOs of major American "
#         "car companies would shake my hand and turn away because I wasn’t "
#         "worth talking to,” said Thrun, in an interview with Recode earlier "
#         "this week.")

fOpen= open(sys.argv[1],"r")
text= fOpen.read()
org_text = text
fOpen.close()
doc = nlp(text)




# Analyze syntax
# print("Noun phrases:", [chunk.text for chunk in doc.noun_chunks])
# print("Verbs:", [token.lemma_ for token in doc if token.pos_ == "VERB"])

# Find named entities, phrases and concepts
# for entity in doc.ents:
#     print(entity.text, entity.label_)


print("Starting the post processing section")


postObj = FeatureExtractor()

postObj.generateFinalrequest(org_text, doc)




#displacy.serve(doc, style='ent')