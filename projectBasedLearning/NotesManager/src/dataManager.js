//import dataJson from '../DataSet/data.json';

// In future we can use API to recieve this json
function getEpic() {
    // fetch("../DataSet/data.json") 
    //     .then((res) => { 
    //     return res.json(); 
    // }) 
    // .then((data) => console.log(data)); 

    epic_info = []

    data_set_stream = data_set[0];

    // var total_len = data_set.length;

    // for (i = 0; i < total_len; i++) {

        
    //     var l1_len = data_set[i].length;
    //     for (j = 0; i < l1_len; j++)
    //     {
    //         var info = {KEY: i, EPIC: data_set[i][j]};
    //         epic_info.push(info);
    //     }
        
    // }

    var counter = 0;
    for (let key_itr in data_set_stream) {

        var info = {KEY: counter, EPIC: key_itr, FEATURE: data_set_stream[key_itr]};
        epic_info.push(info);
        counter++;
    }


    return epic_info;
}

function getFeatures(epic_info) {

    features = []

    var total_len = epic_info.length;

    for (i = 0; i < total_len; i++) {
        var info = {};

        info[[epic_info[i][KEY]]] = [];
        
        var feat_len = epic_info[i][FEATURE].length;

        for (j = 0; j < feat_len; j++) {
            info[epic_info[i][KEY]].push({KEY: epic_info[i][KEY] + '_' + j, FEATURE: epic_info[i][FEATURE][j]})
            
        }
        features.push({info});
    }

    return features;
}

function getStories(features_info) {
    
    stories = []

    var total_len = features_info.length;

    for (i = 0; i < total_len; i++) {
        var info = {};

        info[i] = [];
        
        var feat_len = features_info[i][INFO][i].length;

        for (j = 0; j < feat_len; j++) {
            //{KEY: features_info[i][INFO][i][j][KEY] + '_' + j, STORY: features_info[i][INFO][i][j][FEATURE]

            let counter = 0;
            for (let key_itr in features_info[i][INFO][i][j][FEATURE])
            {
                var len_1 = features_info[i][INFO][i][j][FEATURE][key_itr].length;

                for (k = 0; k < len_1; k++) 
                {
                    //info[i].push({KEY: features_info[i][INFO][i][j][KEY] + '_' + k, STORY: features_info[i][INFO][i][j][FEATURE][key_itr][k]})
                    info[i].push({KEY: i + '_' + counter + '_'  + k, STORY: features_info[i][INFO][i][j][FEATURE][key_itr][k]})
                }
                counter++;
            }
        }
        stories.push({info});
    }

    return stories;
}

function getItems(stories_info)
{
    stories = []

    var total_len = stories_info.length;

    for (i = 0; i < total_len; i++) {
        var info = {};

        info[i] = [];
        
        var feat_len = stories_info[i][INFO][i].length;

        for (j = 0; j < feat_len; j++) {
            //{KEY: features_info[i][INFO][i][j][KEY] + '_' + j, STORY: features_info[i][INFO][i][j][FEATURE]
            info[i].push({KEY: stories_info[i][INFO][i][j][KEY] + '_' + j, ITEM: stories_info[i][INFO][i][j][STORY]})
            
            
        }
        stories.push({info});
    }

    return stories;
}


function getDesiredInfo(key_passed)
{
    const myArray = key_passed.split("_");

    epic_name = "";
    feature_name = "";
    story_name = "";
    item_name = "";

    final_res = "";

    if(myArray.length == 1)
    {
        // Looking for epic name
        //data_set;
        l1 = Object.values(data_set)[0];
        l2 = Object.keys(l1)[myArray[0]];

        epic_name = l2;
        final_res =  l2;
    }

    if(myArray.length == 2)
    {
        // Looking for epic name
        //feature name;
        l1 = Object.values(data_set)[0];
        l2 = Object.values(l1)[myArray[0]][0];
        l3 = Object.keys(l2)[myArray[1]];

        feature_name = l3;
        final_res =  l3;
    }

    if(myArray.length == 3)
    {
        // Looking for epic name
        //story name;
        l1 = Object.values(data_set)[0];
        l2 = Object.values(l1)[myArray[0]][0];
        l3 = Object.values(l2)[myArray[1]][myArray[2]];
        l4 = Object.keys(l3)[0];

        story_name = l4;
        final_res =  l4;
    }

    if(myArray.length == 4)
    {
        // Looking for epic name
        //story name;
        l1 = Object.values(data_set)[0];
        l2 = Object.values(l1)[myArray[0]][0];
        l3 = Object.values(l2)[myArray[1]][myArray[2]];
        l4 = Object.values(l3)[0];


        item_name = l4;
        final_res =  l4;
    }

    //see = Object.keys(data_set)[0];
    // feature = Object.values(data_set)[0][0];
    // story = Object.values(feature)[0][1];
    // item = Object.values(story)[0];

    return final_res
}