import spacy
from fastapi import FastAPI
from pydantic import BaseModel
from typing import List
import sys

from fastapi.responses import HTMLResponse

import uvicorn

import json

# usage python model spacy dev data 


api = FastAPI()

sentences_info_main = [{'name': 'dsdsadsad kdh asjkdas', 'id': "res"}]


def loadDevData(path):
    global sentences_info_main
    f = open(path)
                        
        # returns JSON object as 
        # a dictionary
    dev_data = json.load(f)

    #dev_data = dev_data[0]

    sentences_info_main = []

    for itr in dev_data:
        sentences_info_main.append({'name': itr[0], 'id': dev_data.index(itr)})

        


def makeHomePage(sentences_info):

    sentences_info = str(sentences_info)
    content = """
    <!DOCTYPE html>
    <html>

    <body>
                
                <div > 
                    <p id="sentence_" > No test data available</p>
                </div>


                        
            <div id="overlayCssApp2" onclick="summaryOverlay(()">
            <div id="overlayApp2">No Data To Show For Execution Summary.</div>
            </div>

        <script>

        

        var sentences_info_data =  """   + sentences_info + """; //[{'name': 'dsdsadsad kdh asjkdas', 'id': 'res'}];

        function createSentences()
        {   var sentence_manger = document.getElementById("sentence_");
            var inner_data = '<form id="algo2">'; // action="/extractions" method="POST">';

            inner_data += '<label for="sentence">Choose any random plan for testing: </label>';

            var act_len = sentences_info_data.length;
            //for (let i = 0; i < act_len; i++) {
                inner_data += '<select style="width: 200px !important;" id="sentence" name="sentence"></select>';
            //}
            
            
            inner_data += ' <br><br> <input type="submit" value="Submit" onclick="printresult()"> </form>';

            inner_data += "<h2> Or </h2>";

            inner_data += '<form id="algo3">  <label for="sentence">Try your own input: </label> <input type="text" id="sentence" name="sentence">  </input> ';

            var message = "`algo3`";

            inner_data += '<br><br> <input type="submit" value="Submit" onclick="printresult(' + message + ')"> </form>';
            
            sentence_manger.innerHTML = inner_data;

            var select = document.getElementById('sentence');

        for (let i = 0; i < act_len; i++) {
        
        data = sentences_info_data[i];
        
            var option = document.createElement("option");
        option.text = data["name"];
        option.value = data["name"];
        select.appendChild(option);
        }

        }      


            async function printresult(id_is="algo2") {
                // let setence_info = document.getElementById('sentence').value;
                // var curdata = {
                //     'sentence': setence_info
                // };
                // curdata = JSON.stringify(curdata);
                // var info = curdata;
                // var method_type = "POST";
                // var content_type = "application/json";

                 var url = "http://100.76.133.108:8002/extractions/";

                // const address = await fetch(url, {
                //     method: method_type,
                //     headers: {
                //         'Content-Type': 'application/json'
                //     },
                //     body: info
                // });

                // const printAddress = async()=>{
                //     let a = await address.json()

                //     if (a) {
                //         consoole.log(a.extractions);
                //     }

                // };

                // res = printAddress()

                    const thisForm = document.getElementById(id_is);


                    thisForm.addEventListener('submit', async function (e) {
                    e.preventDefault();

                    var formData = new FormData(thisForm);

                    formData = formData.entries();

                    const response = await fetch(url, {
                    method: 'POST',
                    headers: { 'Content-Type': 'application/json'},
                    body: JSON.stringify(Object.fromEntries(formData))
                });


                const result = await response.json();

                if(result)
                {
                    console.log(result.extractions);
                    document.getElementById("overlayCssApp2").style.display = "Block";
                    //alert(result.extractions);

                    document.getElementById("overlayApp2").innerHTML  =  '<div id="text" style="width:400px;"><p style="font-size:35px; margin-bottom:8px; font-weight:bolder;color:#000;text-align:center;">' + result.extractions + '</p> </div>';
                }
                
                });
            }


            document.getElementById("overlayCssApp2").style.display = "none";
            createSentences();

        </script>
        
        
    </body>
    </html>
    """

    return content

class Input(BaseModel):
    sentence: str

class Extraction(BaseModel):
    first_index: int
    last_index: int
    name: str
    content: str

class Output(BaseModel):
    # extractions: dict
    extractions: str

@api.get("/")
def homeNlp():
    #return HTMLResponse(content=open('homeNlp.html','r').read())
    global sentences_info_main
    
    import random
    random.shuffle(sentences_info_main)

    return HTMLResponse(makeHomePage(sentences_info_main))

@api.post("/extractions/" , response_model=Output)
def extractions(input: Input):
    
    nlp = spacy.load(sys.argv[1])
    document = nlp(input.sentence.lower())


    final_res = input.sentence.lower()
    user_request = input.sentence.lower()

    extraction = []
    # for entity in document.ents:
    #   extraction = {}
    extraction = [(ent.text, ent.label_) for ent in document.ents]
    import random
    color_codes = ['LawnGreen', 'ForestGreen', 'MediumVioletRed', 'Indigo', 'Olive', 'PaleGoldenRod', 'Plum', 'SteelBlue',
                   "Purple", "Salmon", "SandyBrown"]

    color_tried = []
    print(extraction)
    for itr in extraction:
        if itr[0] in user_request:
            color_nmae = color_codes[random.randrange(0,len(color_codes))]

            if color_nmae in color_tried:
                while color_nmae in color_tried:
                    color_nmae = color_codes[random.randrange(0,len(color_codes))]
            else:
                color_tried.append(color_nmae)

            final_res = final_res.replace(itr[0], f'<u style="color:{color_nmae};"> {itr[0]} </u> <mark style="background-color:{color_nmae};"> ({itr[1]}) </mark>')

    return {"extractions": final_res}
    #return {"extractions": extraction}

@api.post("/extractionsa_api/" , response_model=Output)
def extractions(input: Input):
    print('got', input.sentence.lower())
    nlp = spacy.load(sys.argv[1])
    document = nlp(input.sentence.lower())

    extraction = []
    # for entity in document.ents:
    #   extraction = {}
    extraction = [(ent.text, ent.label_) for ent in document.ents]
    
    
    return {"extractions": extraction}


loadDevData(sys.argv[2])

uvicorn.run(api, host="100.76.133.108", port=8002)


