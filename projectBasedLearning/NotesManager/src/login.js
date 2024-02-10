

let proto_name = services_info[PROTO_NAME]
    if(proto_name == 'https')
    {
        
        
        if (window.location.protocol == 'http:') { 
           window.location.href = window.location.href.replace('http:', 'https:');
        }
    }

    
    var globalToken = "";
    var route = "";
    var api_getter = "";
    var url = services_info[BASE_URL] + services_info[LOGIN_URL]; 

    async function required()
    {
    var empt = document.forms["form1"]["token_input"].value;
    if (empt == "")
    {
    alert("Please input a Value");
    return false;
    }
    else
    {
    document.getElementById('container').style.display = "none";

    var childNodes = document.getElementById("container").getElementsByTagName('*');
    for (var node of childNodes) {
        node.disabled = true;
    }

    document.getElementById('loader').style.display = "block";
    
    await new Promise(done => setTimeout(() => done(), 2000));
    
    var curdata = {'token': empt };
    
    globalToken = empt;
    
    route = services_info[BASE_URL] + services_info[LOGIN_URL];
    api_getter =  route + "?token=" + globalToken;

     curdata = JSON.stringify(curdata);
      var info = curdata;
        var method_type = "POST";
        var content_type = "application/json";
        
        const address = await fetch(url,{
            method: method_type,
            headers: {
            'Content-Type': content_type,
            },
            body: info
        });
    const printAddress = async () => {
    let a = await address.json()

    
    if (a.value==true)
    {
    
    action = getApps()

    }
    else
    {
      alert('Authentication Failed');
      location.reload(true)
    }
    };

    res = printAddress()
        }
    }
    
    async function getApps()
    {
    
    var curdata = {'token': globalToken };
    

     curdata = JSON.stringify(curdata);
      var info = curdata;
        var method_type = "GET";
        
        
        console.log(globalToken);
        const address = await fetch(api_getter ,{
            method: method_type
        });
        
    const printAddress = async () => {
    let a = await address
    
    if (a.value==false)
    {
    location.reload(true);
    }
    else
    {
    
    document.getElementById('loader').style.display = "none";

        var childNodes = document.getElementById("loader").getElementsByTagName('*');
        for (var node of childNodes) {
            node.disabled = true;
        }


        
     document.close();
     
     //localStorage.setItem( 'context', myData );
     // Source on how to pass the html content data from the one page to anothe page.
     //https://blog.logrocket.com/localstorage-javascript-complete-guide/
     //https://stackoverflow.com/questions/36599781/how-to-pass-data-from-one-page-to-another-page-html
     //https://medium.com/@cyberbotmachines/how-to-pass-value-from-one-html-page-to-another-using-javascript-3c9ab62df4d

     window.location.href = services_info[MASTER_APP_URL] + "?token=" + globalToken; //api_getter;
     

    }
    
    };
    
    res = printAddress()
    
    }
    
    function openPage(pageName,elmnt,color) {
      var i, tabcontent, tablinks;
      tabcontent = document.getElementsByClassName("tabcontent");
      for (i = 0; i < tabcontent.length; i++) {
        tabcontent[i].style.display = "none";
      }
      tablinks = document.getElementsByClassName("tablink");
      for (i = 0; i < tablinks.length; i++) {
        tablinks[i].style.backgroundColor = "";
      }
      document.getElementById(pageName).style.display = "block";
      elmnt.style.backgroundColor = color;
    }
    
    // Get the element with id="defaultOpen" and click on it
    document.getElementById("defaultOpen").click();
    