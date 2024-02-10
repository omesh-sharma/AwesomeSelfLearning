var proto_name = "https";

if(proto_name == 'https')
{
    if (window.location.protocol == 'http:') { 
        window.location.href = window.location.href.replace('http:', 'https:');
    }
}

var epic_list = [];

var features_info = [];
var stories_info = [];
var item_info = [];


var div_name_inner = "master_view";

var instance_name = [{'app_name': 'G1 8x3060ti', 'route_link': 'https://whentomine.azurewebsites.net/views/get_app2_url', 'deletion_link': 'https://whentomine.azurewebsites.net/core/delete_app_instances', 'place_holder': "Power switching <span style='font-weight:bold; color:orange'>Smart Plug</span>", 'app_type': 'CACHE_STORAGE_FILE_APP_2'}, {'app_name': 'G2-7x3060ti', 'route_link': 'https://whentomine.azurewebsites.net/views/get_app2_url', 'deletion_link': 'https://whentomine.azurewebsites.net/core/delete_app_instances', 'place_holder': "Power switching <span style='font-weight:bold; color:orange'>Smart Plug</span>", 'app_type': 'CACHE_STORAGE_FILE_APP_2'}, {'app_name': 'G3-5x3060', 'route_link': 'https://whentomine.azurewebsites.net/views/get_app2_url', 'deletion_link': 'https://whentomine.azurewebsites.net/core/delete_app_instances', 'place_holder': "Power switching <span style='font-weight:bold; color:orange'>Smart Plug</span>", 'app_type': 'CACHE_STORAGE_FILE_APP_2'}, {'app_name': 'R1-3080lhr-blandat', 'route_link': 'https://whentomine.azurewebsites.net/views/get_app2_url', 'deletion_link': 'https://whentomine.azurewebsites.net/core/delete_app_instances', 'place_holder': "Power switching <span style='font-weight:bold; color:orange'>Smart Plug</span>", 'app_type': 'CACHE_STORAGE_FILE_APP_2'}, {'app_name': 'R2-5x3070-3x3060ti', 'route_link': 'https://whentomine.azurewebsites.net/views/get_app2_url', 'deletion_link': 'https://whentomine.azurewebsites.net/core/delete_app_instances', 'place_holder': "Power switching <span style='font-weight:bold; color:orange'>Smart Plug</span>", 'app_type': 'CACHE_STORAGE_FILE_APP_2'}, {'app_name': 'R3-3080-Various', 'route_link': 'https://whentomine.azurewebsites.net/views/get_app2_url', 'deletion_link': 'https://whentomine.azurewebsites.net/core/delete_app_instances', 'place_holder': "Power switching <span style='font-weight:bold; color:orange'>Smart Plug</span>", 'app_type': 'CACHE_STORAGE_FILE_APP_2'}];

var globalToken = "Conny";

var url1 = "https://whentomine.azurewebsites.net/views/get_app3_url";

// var hide_new_creation = "True";
var hide_new_creation = "False";

var app_deletion_url = "https://whentomine.azurewebsites.net/core/delete_app_instances";

var token_setting_url = "https://whentomine.azurewebsites.net/views/get_app_token_settings";

var app_type = "CACHE_STORAGE_FILE_APP_3";;

function createCards(cards_length=0) {

    var x = Math.floor((Math.random() * 10000) + 1);
    
    var data = '<div class="row">';
    
    // var elem = document.createElement('div');
    
    var elem = document.getElementById('epic_view');
    
    
    cards_length = instance_name.length;
    
    let name_is = "new_chapter";
    let actual_value = "'"+name_is+"'";
    let route_link_main_app = "'"+url1+"'";
    let set_name = app_type;
    let app_name = "'"+ set_name +"'";
    //data += '<div class="column"><div class="card"> <p class="title">No Instances Found</p> <button onclick="takeMeToApp1MainScreen(' + actual_value + ')">Create New Instances</button> </div></div>';
    // &#9618;
    //data += '<div class="column"><div class="card"> <p  style="font-size:45px;"> 🔒🔑 </p> <button onclick="takeMetoGlobalTokenScreen(' + app_name + ')"> API Tokens </button> <p></p> </div></div>';
    
    data += '<div class="column"><div class="card">  <i> &nbsp;&nbsp;&nbsp;<br>&nbsp;&nbsp; </i> <p  style="font-size:45px;"> &plus;</p> <button onclick="takeMeToApp1MainScreen(' + actual_value + ', ' + route_link_main_app + ')">Create new config </button> <p></p> </div></div>';
    
    if (hide_new_creation == 'True')
    {
    data = "";
    }
    
    if(cards_length == 0)
    {
    //alert("No Instances Found..")
    
    }
    //else
    //{
    //cards_length = 9;
    //}
    
    const characters ='ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
    
    function generateString(length) {
        let result = '';
        const charactersLength = characters.length;
        for ( let i = 0; i < length; i++ ) {
            result += characters.charAt(Math.floor(Math.random() * charactersLength));
        }
    
        return result;
    }
    
    for (i = 0; i < cards_length; i++) {
        //actual_value = col[j];
            let actual_value = "'"+instance_name[i]['app_name']+"'";
    
            let delete_id = instance_name[i]['app_name'] + "_delete_state_" + generateString(5);
    
            let act_delete = "'"+delete_id+"'";
            let deletion_link = instance_name[i]['deletion_link']
            let deletion_url = "'"+deletion_link+"'";
            
            let app_name_info= instance_name[i]['app_type']
            let app_name_dynamic = "'"+app_name_info+"'";
            
            let main_ap_url = instance_name[i]['route_link']
            let route_app_link = "'"+main_ap_url+"'";
    
            //var final = key_name + "," + value_name + "," +  actual_value + "," + file_value;
    
    
            //tabCell_new_commit.innerHTML = '<td data-label="Commit Changes"><button onclick="handleCommit(' + final + ')"> Commit </button></td>';
    //data += '<div class="column"><div class="card"> <p class="title">App Instances Name</p><p>' + instance_name[i]['app_name'] + '</p> <p> <button onclick="takeMeToApp1MainScreen(' + actual_value + ')">Visit To Instances</button> </p> </div></div>';
    data += '<div class="column"><div class="card"><div style="font-size:0.9em; display: block; min-height:20px; width:100%; height: auto;"> <div style="display: inline-block; width: auto; float: left;">' + instance_name[i]['place_holder'] + '</div>  <button  onclick="takeToDeleteEvent(' + actual_value + ', ' + deletion_url + ', ' + app_name_dynamic + ')" id=' + delete_id + ' onmouseout="normalDeleter('+ act_delete +')" onmouseover="changeDelete('+ act_delete +')" style="background-color:#f1f1f1; font-size:24px;color:red" class="fa"> &#xf014;  </button></div> <p style="font-size:38px;">' + instance_name[i]['app_name'] + '</p> <p> <button onclick="takeMeToApp1MainScreen(' + actual_value + ', ' + route_app_link + ')">Modify Notes</button> </p> </div></div>';
    }
    
    data += '</div>';
    elem.innerHTML = data;
    //document.body.appendChild(elem);
    }
    
    async function takeToDeleteEvent(app_name, delete_url, app_name_dynamic)
    {
        var result = confirm("Are you sure you want to delete the app " + app_name + "?");
        if (result) {
    
            var curdata = {'app_name': app_name, 'token':  globalToken, 'app_type': app_name_dynamic};
    
    
        curdata = JSON.stringify(curdata);
          var info = curdata;
            var method_type = "POST";
            var content_type = "application/json";
    
            const address = await fetch(delete_url,{
                method: method_type,
                headers: { 'Content-Type': 'application/json'},
                body: info
            });
    
        const printAddress = async () => {
        let a = await address.json()
    
        if (a.value==true)
        {
            // refresh page
            //alert('Working...');
            if(proto_name == 'https')
            {
    
    
                if (window.location.protocol == 'http:') { 
                   window.location.href = window.location.href.replace('http:', 'https:');
                }
                if (window.location.protocol == 'https:') { 
                   window.location.href = window.location.href.replace('https:', 'https:');
                }
    
    
             }
             else{window.location.href = window.location.href.replace('http:', 'http:');}
        }
        else
        {
          alert('Invalid Data...');      
          //location.reload(true)
        }
        };
    
        res = printAddress()
    
    
    
    
        }
    }
    

function createEpicCards(cards_length=0) {

var x = Math.floor((Math.random() * 10000) + 1);

var data = '<div class="row">';

// var elem = document.createElement('div');

var elem = document.getElementById('epic_view');


cards_length = epic_list.length;

let name_is = "new_chapter";
let actual_value = "'"+name_is+"'";
let route_link_main_app = "'"+url1+"'";
let set_name = app_type;
let app_name = "'"+ set_name +"'";
//data += '<div class="column"><div class="card"> <p class="title">No Instances Found</p> <button onclick="takeMeToApp1MainScreen(' + actual_value + ')">Create New Instances</button> </div></div>';
// &#9618;
//data += '<div class="column"><div class="card"> <p  style="font-size:45px;"> 🔒🔑 </p> <button onclick="takeMetoGlobalTokenScreen(' + app_name + ')"> API Tokens </button> <p></p> </div></div>';

data += '<div class="column"><div class="card">  <i> &nbsp;&nbsp;&nbsp;<br>&nbsp;&nbsp; </i> <p  style="font-size:45px;"> &plus;</p> <button onclick="takeMeToApp1MainScreen(' + actual_value + ', ' + route_link_main_app + ')">Create New Notes </button> <p></p> </div></div>';

if (hide_new_creation == 'True')
{
data = "";
}

if(cards_length == 0)
{
//alert("No Instances Found..")

}


const characters ='ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';

function generateString(length) {
    let result = '';
    const charactersLength = characters.length;
    for ( let i = 0; i < length; i++ ) {
        result += characters.charAt(Math.floor(Math.random() * charactersLength));
    }

    return result;
}

for (i = 0; i < cards_length; i++) {
    //actual_value = col[j];

    // 0 is key , 1 is name of epic
    let generated_key = EPIC + '_' + Object.values(epic_list[i])[0];
    let feature_key = FEATURE + '_' + Object.values(epic_list[i])[0];
    let ecpic_name = Object.values(epic_list[i])[1];


    let actual_value = "'"+instance_name[i]['app_name']+"'";
    
        let delete_id = ""; //instance_name[i]['app_name'] + "_delete_state_" + generateString(5);

        let act_delete = ""; //"'"+delete_id+"'";
        let deletion_link = ""; //instance_name[i]['deletion_link']
        let deletion_url = ""; //"'"+deletion_link+"'";
        
        let app_name_info = ""; //instance_name[i]['app_type']
        let app_name_dynamic = ""; //"'"+app_name_info+"'";
        
        let main_ap_url = ""; //instance_name[i]['route_link']
        let route_app_link = ""; //"'"+main_ap_url+"'";

    data += '<div id=' + generated_key + ' > <div class="column"><div class="card"><div style="font-size:0.9em; display: block; min-height:20px; width:100%; height: auto;"> <div style="display: inline-block; width: auto; float: left;">' + "Branch" + '</div>  <a  style="background-color:#f1f1f1; font-size:24px;color:red" class="fa" href="#'+feature_key+'"> &#8623;  </a></div> <p style="font-size:38px;">' + ecpic_name + '</p>  </div></div> </div>';
}

data += '</div>';
elem.innerHTML = data;
//document.body.appendChild(elem);
}

function createFeatureCards(cards_length=0) {

    var x = Math.floor((Math.random() * 10000) + 1);
    
    var data = '<div class="row">';
    
    // var elem = document.createElement('div');
    
    var elem = document.getElementById('feature_view');
    
    
    cards_length = features_info.length;
    
    let name_is = "new_chapter";
    let actual_value = "'"+name_is+"'";
    let route_link_main_app = "'"+url1+"'";
    let set_name = app_type;
    let app_name = "'"+ set_name +"'";
    //data += '<div class="column"><div class="card"> <p class="title">No Instances Found</p> <button onclick="takeMeToApp1MainScreen(' + actual_value + ')">Create New Instances</button> </div></div>';
    // &#9618;
    //data += '<div class="column"><div class="card"> <p  style="font-size:45px;"> 🔒🔑 </p> <button onclick="takeMetoGlobalTokenScreen(' + app_name + ')"> API Tokens </button> <p></p> </div></div>';
    
    data += '<div class="column"><div class="card">  <i> &nbsp;&nbsp;&nbsp;<br>&nbsp;&nbsp; </i> <p  style="font-size:45px;"> &plus;</p> <button onclick="takeMeToApp1MainScreen(' + actual_value + ', ' + route_link_main_app + ')">Create new config </button> <p></p> </div></div>';
    
    if (hide_new_creation == 'True')
    {
    data = "";
    }
    
    if(cards_length == 0)
    {
    //alert("No Instances Found..")
    
    }
    
    
    const characters ='ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
    
    function generateString(length) {
        let result = '';
        const charactersLength = characters.length;
        for ( let i = 0; i < length; i++ ) {
            result += characters.charAt(Math.floor(Math.random() * charactersLength));
        }
    
        return result;
    }
    
    // We are going in dept of feature 0..n
    for (i = 0; i < cards_length; i++) {

        
        // Get all feature of 0
        //features_info[0]['info'][0];

        // Get first fetaure of 0 and then we need to interate KEY and FEATURE 
        //features_info[0]['info'][0][0];
        //actual_value = col[j];

        var nth_feat = Object.keys(Object.values(Object.values(features_info[i]['info'])[0])[0][FEATURE]); //Object.values(features_info[i]['info'])[0]

        var n_len = nth_feat.length;

        let generated_key = FEATURE + '_' + i;

        

        var prod_name = getDesiredInfo(String(i));

        
        data += '<div id='+generated_key+'>';

        data += '<div id="container"><h1 class="style-3">  '+ prod_name +'  tags </h1></div> ';


        for (j = 0; j < n_len; j++) {
    
        // 0 is key , 1 is name of epic
        
        let story_key = STORY + '_' + i + '_' + j; //STORY + features_info[i]['info'][i][0][KEY] + '_' + j; //STORY + '_' + i + '_' + i + '_' + j;
        
        let ecpic_name =  Object.keys(Object.values(Object.values(features_info[i]['info'])[0])[0][FEATURE])[j]; //Object.keys(Object.values(Object.values(features_info[i]['info'])[0][j])[1])[0]; //Object.values(Object.values(features_info[i]['info'])[0][j])[1]
    
    
        let actual_value = "'"+instance_name[i]['app_name']+"'";
        
            let delete_id = ""; //instance_name[i]['app_name'] + "_delete_state_" + generateString(5);
    
            let act_delete = ""; //"'"+delete_id+"'";
            let deletion_link = ""; //instance_name[i]['deletion_link']
            let deletion_url = ""; //"'"+deletion_link+"'";
            
            let app_name_info = ""; //instance_name[i]['app_type']
            let app_name_dynamic = ""; //"'"+app_name_info+"'";
            
            let main_ap_url = ""; //instance_name[i]['route_link']
            let route_app_link = ""; //"'"+main_ap_url+"'";
    
        data += '<div class="column"><div class="card"><div style="font-size:0.9em; display: block; min-height:20px; width:100%; height: auto;"> <div style="display: inline-block; width: auto; float: left;">' + "Subject" + '</div>  <a  style="background-color:#f1f1f1; font-size:24px;color:red" class="fa" href="#'+story_key+'"> &#8623;  </a></div> <p style="font-size:38px;">' + ecpic_name + '</p> <p> <button onclick="takeMeToApp1MainScreen(' + actual_value + ', ' + route_app_link + ')">Modify Notes</button> </p> </div></div> </div>';
        
        }

        data += '</div> </div> <hr><hr>';
        
        
    }
    
    data += '</div>';
    elem.innerHTML = data;
    //document.body.appendChild(elem);
    }

    
    function createStoriesCards(cards_length=0) {

        var x = Math.floor((Math.random() * 10000) + 1);
        
        var data = '<div class="row">';
        
        // var elem = document.createElement('div');
        
        var elem = document.getElementById('story_view');
        
        
        cards_length = stories_info.length;
        
        let name_is = "new_chapter";
        let actual_value = "'"+name_is+"'";
        let route_link_main_app = "'"+url1+"'";
        let set_name = app_type;
        let app_name = "'"+ set_name +"'";
        //data += '<div class="column"><div class="card"> <p class="title">No Instances Found</p> <button onclick="takeMeToApp1MainScreen(' + actual_value + ')">Create New Instances</button> </div></div>';
        // &#9618;
        //data += '<div class="column"><div class="card"> <p  style="font-size:45px;"> 🔒🔑 </p> <button onclick="takeMetoGlobalTokenScreen(' + app_name + ')"> API Tokens </button> <p></p> </div></div>';
        
        data += '<div class="column"><div class="card">  <i> &nbsp;&nbsp;&nbsp;<br>&nbsp;&nbsp; </i> <p  style="font-size:45px;"> &plus;</p> <button onclick="takeMeToApp1MainScreen(' + actual_value + ', ' + route_link_main_app + ')">Create new config </button> <p></p> </div></div>';
        
        if (hide_new_creation == 'True')
        {
        data = "";
        }
        
        if(cards_length == 0)
        {
        //alert("No Instances Found..")
        
        }
        
        
        const characters ='ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
        
        function generateString(length) {
            let result = '';
            const charactersLength = characters.length;
            for ( let i = 0; i < length; i++ ) {
                result += characters.charAt(Math.floor(Math.random() * charactersLength));
            }
        
            return result;
        }
        
        // We are going in dept of feature 0..n
        for (i = 0; i < cards_length; i++) {
    
            
            // Get all feature of 0
            //features_info[0]['info'][0];
    
            // Get first fetaure of 0 and then we need to interate KEY and FEATURE 
            //features_info[0]['info'][0][0];
            //actual_value = col[j];
    
            var nth_feat = stories_info[i]['info'][i];
    
            var n_len = nth_feat.length;
    
            dynamic_div_dict = {}
            
            prev = 0;

            for (j = 0; j < n_len; j++) {
            

            dynamic_div = ""
        
            
            // Below one is used to get key value of item
            //stories_info[i]['info'][i][2]
            
            let story_key = ITEM + '_' + i + '_' + i + '_' + j;
            
            let ecpic_name =  Object.keys(Object.values(stories_info[i]['info'][i])[j][STORY])[0];
        
        
            let actual_value = "'"+instance_name[i]['app_name']+"'";
            
                let delete_id = ""; //instance_name[i]['app_name'] + "_delete_state_" + generateString(5);
        
                let act_delete = ""; //"'"+delete_id+"'";
                let deletion_link = ""; //instance_name[i]['deletion_link']
                let deletion_url = ""; //"'"+deletion_link+"'";
                
                let app_name_info = ""; //instance_name[i]['app_type']
                let app_name_dynamic = ""; //"'"+app_name_info+"'";
                
                let main_ap_url = ""; //instance_name[i]['route_link']
                let route_app_link = ""; //"'"+main_ap_url+"'";
        
        
                let check = Object.values(stories_info[i]['info'][i][j])[0].split("_")
                let check_req = Object.values(stories_info[i]['info'][i][j])[0].split("_")
                check = String(check[0] + '_' +  check[1])

            var story_name = getDesiredInfo(check); //getDesiredInfo(String(i) + '_'+ String(j)); //getDesiredInfo(String(i) + '_'+ 0);
            
            let generated_key = String(STORY + '_' + check_req[0] + '_' + check_req[1]); //Object.values(stories_info[i]['info'][i][j])[0] //STORY + '_' + Object.values(stories_info[i]['info'][i])[0][KEY];
            story_key = ITEM + '_' + Object.values(stories_info[i]['info'][i][j])[0];
            let uniq_key = Object.values(stories_info[i]['info'][i][j])[0];

            ecpic_name = getDesiredInfo(Object.values(stories_info[i]['info'][i][j])[0]);
            


            dynamic_div = '<div class="column"><div class="card"><div style="font-size:0.9em; display: block; min-height:20px; width:100%; height: auto;"> <div style="display: inline-block; width: auto; float: left;">' + "Topic" + '</div>  <a  style="background-color:#f1f1f1; font-size:24px;color:red" class="fa" href="#'+story_key+'"> &#8623;  </a></div> <p style="font-size:38px;">' + ecpic_name + '</p> <p> <button onclick="takeMeToApp1MainScreen(' + actual_value + ', ' + route_app_link + ')">Modify Notes</button> </p> </div></div> </div>';

            if(dynamic_div_dict[check_req[1]] == undefined)
            {
                dynamic_div_dict[check_req[1]] = ""
            }

            if (dynamic_div_dict[check_req[1]] == "")
            {
                dynamic_div_dict[check_req[1]] = '<div id='+generated_key+'>'; 
                dynamic_div_dict[check_req[1]] += '<div id="container"><h1 class="style-3">  '+ story_name +'  tags </h1></div> ';
            }
            
            {
                dynamic_div_dict[check_req[1]] +=  dynamic_div;
            }
    
            }
            
            for(itr in dynamic_div_dict)
            {
                data += dynamic_div_dict[itr];
                data += '</div> </div> <hr><hr>';
            }
            //data += '</div> </div> <hr><hr>';
            
        }
        
        data += '</div>';
        elem.innerHTML = data;
        //document.body.appendChild(elem);
        }
    

        function createItemsCards(cards_length=0) {

            var x = Math.floor((Math.random() * 10000) + 1);
            
            var data = '<div class="row">';
            
            // var elem = document.createElement('div');
            
            var elem = document.getElementById('item_view');
            
            
            cards_length = stories_info.length;
            
            let name_is = "new_chapter";
            let actual_value = "'"+name_is+"'";
            let route_link_main_app = "'"+url1+"'";
            let set_name = app_type;
            let app_name = "'"+ set_name +"'";
            //data += '<div class="column"><div class="card"> <p class="title">No Instances Found</p> <button onclick="takeMeToApp1MainScreen(' + actual_value + ')">Create New Instances</button> </div></div>';
            // &#9618;
            //data += '<div class="column"><div class="card"> <p  style="font-size:45px;"> 🔒🔑 </p> <button onclick="takeMetoGlobalTokenScreen(' + app_name + ')"> API Tokens </button> <p></p> </div></div>';
            
            data += '<div class="column"><div class="card">  <i> &nbsp;&nbsp;&nbsp;<br>&nbsp;&nbsp; </i> <p  style="font-size:45px;"> &plus;</p> <button onclick="takeMeToApp1MainScreen(' + actual_value + ', ' + route_link_main_app + ')">Create new config </button> <p></p> </div></div>';
            
            if (hide_new_creation == 'True')
            {
            data = "";
            }
            
            if(cards_length == 0)
            {
            //alert("No Instances Found..")
            
            }
            
            
            const characters ='ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
            
            function generateString(length) {
                let result = '';
                const charactersLength = characters.length;
                for ( let i = 0; i < length; i++ ) {
                    result += characters.charAt(Math.floor(Math.random() * charactersLength));
                }
            
                return result;
            }
            
            // We are going in dept of feature 0..n
            for (i = 0; i < cards_length; i++) {
        
                
                // Get all feature of 0
                //features_info[0]['info'][0];
        
                // Get first fetaure of 0 and then we need to interate KEY and FEATURE 
                //features_info[0]['info'][0][0];
                //actual_value = col[j];
        
                var nth_feat = stories_info[i]['info'][i];
        
                var n_len = nth_feat.length;
        
                dynamic_div_dict = {}
                
                prev = 0;
    
                for (j = 0; j < n_len; j++) {
                
    
                dynamic_div = ""
            
                
                // Below one is used to get key value of item
                //stories_info[i]['info'][i][2]
                
                let story_key = ITEM + '_' + i + '_' + i + '_' + j;
                
                let ecpic_name =  Object.keys(Object.values(stories_info[i]['info'][i])[j][STORY])[0];
            
            
                let actual_value = "'"+instance_name[i]['app_name']+"'";
                
                    let delete_id = ""; //instance_name[i]['app_name'] + "_delete_state_" + generateString(5);
            
                    let act_delete = ""; //"'"+delete_id+"'";
                    let deletion_link = ""; //instance_name[i]['deletion_link']
                    let deletion_url = ""; //"'"+deletion_link+"'";
                    
                    let app_name_info = ""; //instance_name[i]['app_type']
                    let app_name_dynamic = ""; //"'"+app_name_info+"'";
                    
                    let main_ap_url = ""; //instance_name[i]['route_link']
                    let route_app_link = ""; //"'"+main_ap_url+"'";
            
            
                    let check = Object.values(stories_info[i]['info'][i][j])[0].split("_")
                    let check_req = Object.values(stories_info[i]['info'][i][j])[0].split("_")
                    check = String(check[0] + '_' +  check[1])
    
                var story_name = getDesiredInfo(Object.values(stories_info[i]['info'][i][j])[0]); //getDesiredInfo(String(i) + '_'+ String(j)); //getDesiredInfo(String(i) + '_'+ 0);
                let ITEM_KEY = ITEM + '_' + Object.values(stories_info[i]['info'][i][j])[0];
                let generated_key = String(STORY + '_' + check_req[0] + '_' + check_req[1]); //Object.values(stories_info[i]['info'][i][j])[0] //STORY + '_' + Object.values(stories_info[i]['info'][i])[0][KEY];
                story_key = INFO + '_' + Object.values(stories_info[i]['info'][i][j])[0];
                let uniq_key = Object.values(stories_info[i]['info'][i][j])[0];
    
                ecpic_name = getDesiredInfo(Object.values(stories_info[i]['info'][i][j])[0] + '_' + '1');
                
    
    
                dynamic_div = '<div class="column"><div class="card"><div style="font-size:0.9em; display: block; min-height:20px; width:100%; height: auto;"> <div style="display: inline-block; width: auto; float: left;">' + "Info" + '</div>  <a  style="background-color:#f1f1f1; font-size:24px;color:red" class="fa" href="#'+story_key+'"> &#8623;  </a></div> <p style="font-size:38px;">' + ecpic_name + '</p> <p> <button onclick="takeMeToApp1MainScreen(' + actual_value + ', ' + route_app_link + ')">Modify Notes</button> </p> </div></div> </div>';
    
                if(dynamic_div_dict[j] == undefined)
                {
                    dynamic_div_dict[j] = ""
                }
    
                if (dynamic_div_dict[j] == "")
                {
                    dynamic_div_dict[j] = '<div id='+ITEM_KEY+'>'; 
                    dynamic_div_dict[j] += '<div id="container"><h1 class="style-3">  '+ story_name +'  tags </h1></div> ';
                }
                
                {
                    dynamic_div_dict[j] +=  dynamic_div;
                }
        
                }
                
                for(itr in dynamic_div_dict)
                {
                    data += dynamic_div_dict[itr];
                    data += '</div> </div> <hr><hr>';
                }
                //data += '</div> </div> <hr><hr>';
                
            }
            
            data += '</div>';
            elem.innerHTML = data;
            //document.body.appendChild(elem);
            }
        

async function takeToDeleteEvent(app_name, delete_url, app_name_dynamic)
{
    var result = confirm("Are you sure you want to delete the app " + app_name + "?");
    if (result) {

        var curdata = {'app_name': app_name, 'token':  globalToken, 'app_type': app_name_dynamic};


    curdata = JSON.stringify(curdata);
      var info = curdata;
        var method_type = "POST";
        var content_type = "application/json";

        const address = await fetch(delete_url,{
            method: method_type,
            headers: { 'Content-Type': 'application/json'},
            body: info
        });

    const printAddress = async () => {
    let a = await address.json()

    if (a.value==true)
    {
        // refresh page
        //alert('Working...');
        if(proto_name == 'https')
        {


            if (window.location.protocol == 'http:') { 
               window.location.href = window.location.href.replace('http:', 'https:');
            }
            if (window.location.protocol == 'https:') { 
               window.location.href = window.location.href.replace('https:', 'https:');
            }


         }
         else{window.location.href = window.location.href.replace('http:', 'http:');}
    }
    else
    {
      alert('Invalid Data...');      
      //location.reload(true)
    }
    };

    res = printAddress()




    }
}

function normalDeleter(id_val)
{
document.getElementById(id_val).style.backgroundColor = "#f1f1f1";

}

function changeDelete()
{
document.getElementById(id_val).style.backgroundColor = "#424874";

}

async function takeMetoGlobalTokenScreen(app_type)
{

var curdata = {'token': globalToken, 'INSTANCES_NAME':  instance_name};


     curdata = JSON.stringify(curdata);
      var info = curdata;
        var method_type = "GET";

        var url_new = token_setting_url + "?token=" + globalToken + "&app_type=" + app_type;

        //console.log(globalToken);
        const address = await fetch(url_new ,{
            method: method_type
        });

    const printAddress = async () => {
    let a = await address

    if (a.status != 200)
    {
    //location.reload(true);
    alert("Failed To Fetch Data...");


    }
    else
    {

     //document.close();

     //window.location.href = url1 + "?token=" + globalToken;
     var url1_new = token_setting_url + "?token=" + globalToken;

     document.close();
     window.location.href = url_new;

    }

    };

    res = printAddress()


}

async function takeMeToApp1MainScreen(instance_name, route_app_link){

var curdata = {'token': globalToken, 'INSTANCES_NAME':  instance_name};


     curdata = JSON.stringify(curdata);
      var info = curdata;
        var method_type = "GET";

        var url_new = route_app_link + "?token=" + globalToken + "&INSTANCES_NAME=" + instance_name;

        //console.log(globalToken);
        const address = await fetch(url_new ,{
            method: method_type
        });

    const printAddress = async () => {
    let a = await address

    if (a.status != 200)
    {
    //location.reload(true);
    alert("Failed To Fetch Data...");


    }
    else
    {

     //document.close();

     //window.location.href = url1 + "?token=" + globalToken;
     var url1_new = route_app_link + "?token=" + globalToken;

     document.close();
     window.location.href = url_new;

    }

    };

    res = printAddress()


}



epic_list = getEpic();

features_info = getFeatures(epic_list);

stories_info = getStories(features_info)

item_info = getItems(stories_info);

test_anything = getDesiredInfo("0_0_0_1");

// TODO : create sections 
//https://www.geeksforgeeks.org/how-to-create-links-to-sections-within-the-same-page-in-html/

createEpicCards(0);
createFeatureCards(0);
createStoriesCards(0);
createItemsCards(0);
    