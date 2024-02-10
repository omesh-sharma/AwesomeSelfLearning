
import json
import os
import re

class FeatureExtractor:
    def __init__(self) -> None:
        pass
    
    def sampleTrainingData(self):
        data = {}

        data["monthly"] = {["month"]}

    def createConfig(self):
        pass

    def loadConfig(self):
        pass 

    def findMatchedOffset(self, matcher, target_string):
        res = None
        for match in re.finditer(matcher, target_string):
            res = (match.start(), match.end())

        return res



    def createFeature(self, target_str="create an offer having unlimited voice and 2 GB data download for monthly fee of 10$."):

        pass
    
    def readLabels(self, path_of_labels):
        
        labels_data =[]

        if os.path.exists(path_of_labels):

                if(path_of_labels.split('.')[1] == "json"):

                    f = open(path_of_labels)
                        
                        # returns JSON object as 
                        # a dictionary
                    labels_data = json.load(f)

                    return labels_data

                



    def trainLabeledData(self, output_dir=None, import_datas_set=None, use_syntehsis='None', only_dump_data=False, train_thresh=None):
        #from __future__ import unicode_literals, print_function
        #import plac
        import random
        from pathlib import Path
        import spacy
        from spacy.pipeline import __all__
        from spacy.training.example import Example
        from tqdm import tqdm

        #nlp = spacy.load("en_core_web_sm")
        nlp = spacy.blank("en")

        if 'ner' not in nlp.pipe_names:
            #ner = nlp.create_pipe('ner')
            # nlp.add_pipe(ner, last=True)
            ner = nlp.add_pipe('ner', last=True)
        else:
            ner = nlp.get_pipe('ner')

        training_data = []

        if import_datas_set is None:
            training_data = [
            ("create an offer with monthly recurring charge of 10$ for voice service.",{'entities': [(10,15,"OFFER"),(21,28,"DURATION"),(49,52,"MONEY"),(57,62,"SERVICE")]}),
            ("create an offer with monthly recurring charge of 10$ for voice service and onetime setup fee of 5$.", {'entities': [(10,15,"OFFER"),(21,28,"RECURRENCE"),(49,52,"MONEY"),(57,62,"SERVICE"),(75,92,"ONETIME"),(96,99,"MONEY")]}),
            ("create an offer with monthly recurring charge of 10$ for data service.",{'entities': [(10,15,"OFFER"),(21,28,"DURATION"),(49,52,"MONEY"),(57,61,"SERVICE")]}),
            ("create an offer with monthly recurring charge of 10$ for data service and onetime setup fee of 5$.", {'entities':[(10,15,"OFFER"),(21,28,"RECURRENCE"),(49,52,"MONEY"),(57,61,"SERVICE"),(74,91,"ONETIME"),(95,98,"MONEY")]}),
            ("create an offer with monthly recurring charge of 10$ for SMS service.", {'entities': [(10,15,"OFFER"),(21,28,"DURATION"),(49,52,"MONEY"),(57,60,"SERVICE")]}),
            ("create an offer with monthly recurring charge of 10$ for unlimited voice, data and SMS service.", {'entities': [(10,15,"OFFER"),(21,28,"DURATION"),(49,52,"MONEY"),(57,66,"QUANTITY"),(67,72,"SERVICE"),(74,78,"SERVICE"),(83,86,"SERVICE")]}),
            ("create an offer with monthly recurring charge of 10$ for unlimited voice, data, SMS service and onetime setup fee of 5$.", {'entities': [(10,15,"OFFER"),(21,28,"DURATION"),(49,52,"MONEY"),(57,66,"QUANTITY"),(67,72,"SERVICE"),(74,78,"SERVICE"),(80,83,"SERVICE"),(96,113,"ONETIME"),(117,120,"MONEY")]})
            ]
        else:
            import os
            import json
            if os.path.exists(import_datas_set):

                if(import_datas_set.split('.')[1] == "jsonl"):
                    training_data=[]
                    with open(import_datas_set, 'r', encoding='utf-8') as reader:
                        for line in reader:
                            training_data.append(json.loads(line))
                    
                    #print(training_data)
                    
                else:
                        
                    f = open(import_datas_set)
                    
                    # returns JSON object as 
                    # a dictionary
                    training_data = json.loads(f)

                    #print(training_data)
            else:
                print("Imported data set file is not valid, please check the path and try again")
            
            # prearing the training_data in spacy standard format : 

            final_training_data = []

            for itr in training_data:

                itr["text"] = itr["text"].lower()
                
                entities = itr["entities"]

                entities_list = []

                
                filter_annotation = []

                label_check = []

                spare_entity_list = []

                intersection_list = []

                
                for inner_itr in entities:
                    
                    if inner_itr["label"] in label_check and inner_itr["label"] != 'service':
                        continue
                        spare_entity_list.append((inner_itr["start_offset"], inner_itr["end_offset"], inner_itr["label"]))
                        pass #continue
                    else:
                        label_check.append(inner_itr["label"])

                    # Lets check entitie are not intersected before proceeding further: 
                    if intersection_list:
                        #continue
                        x1 = inner_itr["start_offset"]
                        x2 = inner_itr["end_offset"]

                        is_inter_found = False
                        for inter_itr in intersection_list:
                            if x1 <= inter_itr[1] and inter_itr[0] <= x2:
                                #spare_entity_list.append((inner_itr["start_offset"], inner_itr["end_offset"], inner_itr["label"]))

                                is_inter_found = True

                                break
                        
                        if is_inter_found:
                            continue


                    annotation_data = f'{inner_itr["start_offset"]}_{inner_itr["end_offset"]}'

                    if (annotation_data in filter_annotation):
                        #continue
                        # Lets create new entity in the run time
                        spare_entity_list.append((inner_itr["start_offset"], inner_itr["end_offset"], inner_itr["label"]))
                        pass #continue
                    else:
                        filter_annotation.append(annotation_data)

                    
                    entities_list.append((inner_itr["start_offset"], inner_itr["end_offset"], inner_itr["label"]))

                    intersection_list.append((inner_itr["start_offset"], inner_itr["end_offset"]))

                if entities_list:
                    tuple_form = (itr["text"], {"entities": entities_list})
                    final_training_data.append(tuple_form)

                    if spare_entity_list:
                        spare_entity_list = [*set(spare_entity_list)]

                        for spare_itr in spare_entity_list:
                            tuple_form = (itr["text"], {"entities": [spare_itr]})
                            final_training_data.append(tuple_form)




            if final_training_data:
                training_data = final_training_data
            else:
                print("No lable found in the imported data set , please check the data set")
                exit()

        # print(training_data)
        
        if os.path.exists(use_syntehsis):

                if(use_syntehsis.split('.')[1] == "json"):

                    f = open(use_syntehsis)
                        
                        # returns JSON object as 
                        # a dictionary
                    synthesis_data = json.load(f)

        print(training_data[1])
        training_data= []
        for itr in synthesis_data:
            create_on_spot = []

            for inner_itr in itr[1]['entities']:
                create_on_spot.append(tuple(inner_itr))



            training_data.append((itr[0], {'entities': create_on_spot}))


        # ranodm shuffling the list : \
        random.shuffle(training_data)

        train_dump = []
        dev_dump =[]

        train_dump = training_data
        
        if train_thresh:
            # print(train_thresh[0])
            # print(len(training_data))
            # print((train_thresh[0]/len(training_data)))
            # print(int((train_thresh[0]/len(training_data))* 100))
            # exit()
            train_dump = training_data[:int((train_thresh[0]/100)* len(training_data))]

            dev_dump = training_data[int((train_thresh[0]/100)* len(training_data)):]

            if only_dump_data and train_dump:
                from datetime import date

                today = date.today()
                file_name = f"spacy_data_standard_train_{str(today)}.json"

                with open(file_name, "w", encoding='utf-8') as data:
                
                    data.write(json.dumps(train_dump, indent=4))
                    data.close()


            if only_dump_data and dev_dump:
                from datetime import date

                today = date.today()
                file_name = f"spacy_data_standard_dev_{str(today)}.json"

                with open(file_name, "w", encoding='utf-8') as data:
                
                    #data.write(json.dumps(dev_dump, indent=4))
                    json.dump(dev_dump, data, indent=4)
                    data.close()

            if only_dump_data:
                return


        n_iter = 70 #int(len(training_data)/2)

        for _, annotations in train_dump:
            
            for ent in annotations.get('entities'):
                ner.add_label(ent[2])

        other_pipes = [pipe for pipe in nlp.pipe_names if pipe != 'ner']
        with nlp.disable_pipes(*other_pipes):  # only train NER
            optimizer = nlp.begin_training()
            for itr in range(n_iter):
                random.shuffle(train_dump)
                losses = {}
                for text, annotations in tqdm(train_dump):

                    # create Example
                    doc = nlp.make_doc(text)

                    print(text,annotations)
                    #exit()
                    #span = doc[start:end]
                    example = Example.from_dict(doc, annotations)
                    # Update the model

                    nlp.update(
                        [example],  
                        drop=0.5,  
                        sgd=optimizer,
                        losses=losses)

                    # nlp.update(
                    #     [text],  
                    #     [annotations],  
                    #     drop=0.5,  
                    #     sgd=optimizer,
                    #     losses=losses)
                print(losses)
        

        for text, _ in dev_dump:
            doc = nlp(text)
            print('Entities', [(ent.text, ent.label_) for ent in doc.ents])
    

        if output_dir is not None:


            from datetime import date

            today = date.today()
            output_dir = f"{output_dir}_{str(today)}"

            output_dir = Path(output_dir)
            if not output_dir.exists():
                output_dir.mkdir()
            nlp.to_disk(output_dir)
            print("Saved model to", output_dir)

    def createCustomDataSet(file_name):
        pass


    def createLablesForDocanno(self):

        lable_list = []

        while True:
            lable_name = input("enter the lable names , enter lable name lable_d to delete  specific lable name and press ok  or enter to terminate.. ->    ")

            if lable_name == "ok" or lable_name == "" or lable_name == " ":
                break
            elif '_d' in lable_name:
                lable_name = lable_name.replace("_d")
                lable_list.remove(lable_name)
            else:
                lable_list.append(lable_name)

        import json

        lable_set = []

        if lable_list:
            for itr in lable_list:
                
                lable_stream = {}
                lable_stream["text"] = itr
                print(itr)
                lable_stream["text_color"] = "#ffffff"
                lable_stream["background_color"] = "#FF0000"
                index = lable_list.index(itr)
                lable_stream["suffix_key"] = str(index)

                lable_set.append(lable_stream)
            
            from datetime import date

            today = date.today()
            file_name = f"lable_data_{str(today)}.json"

            with open(file_name, "a+", encoding='utf-8') as data:
            
                data.write(json.dumps(lable_set, indent=4))
                data.close()



    def generateFinalrequest(self, org_text, spacyDoc):
        print("Noun phrases:", [chunk.text for chunk in spacyDoc.noun_chunks])
        print("Verbs:", [token.lemma_ for token in spacyDoc if token.pos_ == "VERB"])

        # Find named entities, phrases and concepts
        for entity in spacyDoc.ents:
            
            print(entity.text, entity.label_)


