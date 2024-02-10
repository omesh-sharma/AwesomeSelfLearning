import spacy
import sys
from mainsdk import FeatureExtractor
from spacy.pipeline import __all__


# usage : mode name and second argument as data set , thoird as syntehsis data set

nlp = spacy.load(sys.argv[1])

fOpen= open(sys.argv[2],"r")
lines = fOpen.readlines()

for itr in lines:
    if itr and itr != '\n':
        itr = itr.lower()
        org_text = itr
        fOpen.close()
        doc = nlp(itr)



        # Analyze syntax
        print('Entities', [(ent.text, ent.label_) for ent in doc.ents])
        #print("tokens:", [(token.text , token.ent_type, token.ent_iob)for token in doc])

        # Find named entities, phrases and concepts
        # for entity in doc.ents:
        #     print(entity.text, entity.label_)

        print("\n _____________________________________________________________________ \n")