
const urlParams = new URLSearchParams(window.location.search);
const api_token = urlParams.get('token');
console.log(api_token);  



let proto_name = services_info[PROTO_NAME];

if(proto_name == 'https')
{
    
    if (window.location.protocol == 'http:') { 
       window.location.href = window.location.href.replace('http:', 'https:');
    }
}


var div_name_inner = "master_view";

var globalToken = api_token;

var url1 = services_info[BASE_URL] + services_info[APP1_URL];

var url_app1_series = services_info[BASE_URL] +  services_info[APP1_SERIES];

var url_app2_series = services_info[BASE_URL] +  services_info[APP2_SERIES];

var url_app3_series = services_info[BASE_URL] +  services_info[APP3_SERIES];

var url_all_app_series = services_info[BASE_URL] +  services_info[ALL_APP_URL];

var url_app4_series = services_info[BASE_URL] +  services_info[APP4_SERIES];

var url2 = services_info[BASE_URL] +  services_info[APP2_URL];

var app_2_a_url = services_info[BASE_URL] +  services_info[APP2_A_URL];

var url3 = services_info[BASE_URL] +  services_info[MODIFY_INSTANCES_URL];

var url4 = services_info[BASE_URL] +  services_info[APP3_URL];

var app4_url = services_info[BASE_URL] +  services_info[APP4_URL];

var app_1_a_url = services_info[BASE_URL] +  services_info[APP1_A_URL];

var app_1_b_url = services_info[BASE_URL] +  services_info[APP2_B_URL];

var app_3_a_url = services_info[BASE_URL] +  services_info[APP3_A_URL];

var app_3_b_url = services_info[BASE_URL] +  services_info[APP2_B_URL];

var app_2_b_url = services_info[BASE_URL] +  services_info[APP2_B_URL];

// For Making Header Responsive
const menu_btn = document.querySelector(".menu-btn");
const close_btn = document.querySelector(".close-btn");
const menu = document.querySelector(".menu");
const drawer = menu.querySelector(".drawer");
const blank = menu.querySelector(".blank");
const body = document.querySelector("body");
const close = () => {
menu.classList.remove("blur");
drawer.classList.remove("drawer-visible");
body.classList.remove("body");
};

menu_btn.addEventListener("click", (e) => {
menu.classList.add("blur");
drawer.classList.add("drawer-visible");
body.classList.add("body");
});

close_btn.addEventListener("click", (e) => {
close();
});

blank.addEventListener("click", (e) => {
close();
});

Array.from(drawer.querySelectorAll("a")).forEach((element) => {
element.addEventListener("click", () => {
close();
});
});

function previewUrl(url,target){
    url = encodeURIComponent(url);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(target);
        div.innerHTML = '<iframe id="frameID" style="width:100%;height:100%;" frameborder="0" src="' + url + '" />';
    },20);
}


async function createApp1Series(div_name)
{

var curdata = {'token': globalToken };


curdata = JSON.stringify(curdata);
var info = curdata;
var method_type = "GET";


console.log(globalToken);
const address = await fetch(url_app1_series ,{
    method: method_type
});

const printAddress = async () => {
let a = await address

if (a.value==false)
{
//location.reload(true);
alert("Failed To Fetch Data...");


}
else
{

//document.close();

//window.location.href = url1 + "?token=" + globalToken;
var url1_new = url_app1_series + "?token=" + globalToken;

//url1_new = encodeURIComponent(url1);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(div_name);
       div.innerHTML = '<iframe style="width:100%;height:100%;" frameborder="0" src="' + url1_new + '" />';
    },30);


}

};

res = printAddress()

}

async function createAllAppSeries(div_name)
{

var curdata = {'token': globalToken };


curdata = JSON.stringify(curdata);
var info = curdata;
var method_type = "GET";


console.log(globalToken);
const address = await fetch(url_all_app_series ,{
    method: method_type
});

const printAddress = async () => {
let a = await address

if (a.value==false)
{
//location.reload(true);
alert("Failed To Fetch Data...");


}
else
{

//document.close();

//window.location.href = url1 + "?token=" + globalToken;
var url1_new = url_all_app_series + "?token=" + globalToken;

//url1_new = encodeURIComponent(url1);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(div_name);
       div.innerHTML = '<iframe style="width:100%;height:100%;" frameborder="0" src="' + url1_new + '" />';
    },30);


}

};

res = printAddress()

}



async function createApp1(div_name)
{

var curdata = {'token': globalToken };


curdata = JSON.stringify(curdata);
var info = curdata;
var method_type = "GET";


console.log(globalToken);
const address = await fetch(url1 ,{
    method: method_type
});

const printAddress = async () => {
let a = await address

if (a.value==false)
{
//location.reload(true);
alert("Failed To Fetch Data...");


}
else
{

//document.close();

//window.location.href = url1 + "?token=" + globalToken;
var url1_new = url1 + "?token=" + globalToken;

//url1_new = encodeURIComponent(url1);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(div_name);
       div.innerHTML = '<iframe style="width:100%;height:100%;" frameborder="0" src="' + url1_new + '" />';
    },30);


}

};

res = printAddress()

}


async function createApp2Series(div_name)
{
var curdata = {'token': globalToken };


curdata = JSON.stringify(curdata);
var info = curdata;
var method_type = "GET";


console.log(globalToken);
const address = await fetch(url_app2_series ,{
    method: method_type
});

const printAddress = async () => {
let a = await address

if (a.value==false)
{
//location.reload(true);
alert("Failed To Fetch Data...");


}
else
{

//document.close();

//window.location.href = url1 + "?token=" + globalToken;
var url1_new = url_app2_series + "?token=" + globalToken;

//url1_new = encodeURIComponent(url1);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(div_name);
       div.innerHTML = '<iframe style="width:100%;height:100%;" frameborder="0" src="' + url1_new + '" />';
    },30);


}

};

res = printAddress()

}


async function createApp2(div_name)
{

var curdata = {'token': globalToken };


curdata = JSON.stringify(curdata);
var info = curdata;
var method_type = "GET";


console.log(globalToken);
const address = await fetch(url2 ,{
    method: method_type
});

const printAddress = async () => {
let a = await address

if (a.value==false)
{
//location.reload(true);
alert("Failed To Fetch Data...");


}
else
{

//document.close();

//window.location.href = url1 + "?token=" + globalToken;
var url1_new = url2 + "?token=" + globalToken;

//url1_new = encodeURIComponent(url1);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(div_name);
       div.innerHTML = '<iframe style="width:100%;height:100%;" frameborder="0" src="' + url1_new + '" />';
    },30);


}

};

res = printAddress()

}

async function createApp1_a(div_name)
{

var curdata = {'token': globalToken };


curdata = JSON.stringify(curdata);
var info = curdata;
var method_type = "GET";


console.log(globalToken);
const address = await fetch(app_1_a_url ,{
    method: method_type
});

const printAddress = async () => {
let a = await address

if (a.value==false)
{
//location.reload(true);
alert("Failed To Fetch Data...");


}
else
{

//document.close();

//window.location.href = app_1_a_url + "?token=" + globalToken;
var url1_new = app_1_a_url + "?token=" + globalToken;

//url1_new = encodeURIComponent(app_1_a_url);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(div_name);
       div.innerHTML = '<iframe style="width:100%;height:100%;" frameborder="0" src="' + url1_new + '" />';
    },30);


}

};

res = printAddress()

}


async function createApp1_b(div_name)
{

var curdata = {'token': globalToken };


curdata = JSON.stringify(curdata);
var info = curdata;
var method_type = "GET";


console.log(globalToken);
const address = await fetch(app_1_b_url ,{
    method: method_type
});

const printAddress = async () => {
let a = await address

if (a.value==false)
{
//location.reload(true);
alert("Failed To Fetch Data...");


}
else
{

//document.close();

//window.location.href = app_1_b_url + "?token=" + globalToken;
var url1_new = app_1_b_url + "?token=" + globalToken;

//url1_new = encodeURIComponent(app_1_b_url);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(div_name);
       div.innerHTML = '<iframe style="width:100%;height:100%;" frameborder="0" src="' + url1_new + '" />';
    },30);


}

};

res = printAddress()

}



async function createApp2_b(div_name)
{

var curdata = {'token': globalToken };


curdata = JSON.stringify(curdata);
var info = curdata;
var method_type = "GET";


console.log(globalToken);
const address = await fetch(app_2_b_url ,{
    method: method_type
});

const printAddress = async () => {
let a = await address

if (a.value==false)
{
//location.reload(true);
alert("Failed To Fetch Data...");


}
else
{

//document.close();

//window.location.href = url1 + "?token=" + globalToken;
var url1_new = app_2_b_url + "?token=" + globalToken;

//url1_new = encodeURIComponent(url1);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(div_name);
       div.innerHTML = '<iframe style="width:100%;height:100%;" frameborder="0" src="' + url1_new + '" />';
    },30);


}

};

res = printAddress()

}


async function createApp2_a(div_name)
{

var curdata = {'token': globalToken };


curdata = JSON.stringify(curdata);
var info = curdata;
var method_type = "GET";


console.log(globalToken);
const address = await fetch(app_2_a_url ,{
    method: method_type
});

const printAddress = async () => {
let a = await address

if (a.value==false)
{
//location.reload(true);
alert("Failed To Fetch Data...");


}
else
{

//document.close();

//window.location.href = url1 + "?token=" + globalToken;
var url1_new = app_2_a_url + "?token=" + globalToken;

//url1_new = encodeURIComponent(url1);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(div_name);
       div.innerHTML = '<iframe style="width:100%;height:100%;" frameborder="0" src="' + url1_new + '" />';
    },30);


}

};

res = printAddress()

}



async function createApp4(div_name)
{

var curdata = {'token': globalToken };


curdata = JSON.stringify(curdata);
var info = curdata;
var method_type = "GET";


console.log(globalToken);
const address = await fetch(app4_url ,{
    method: method_type
});

const printAddress = async () => {
let a = await address

if (a.value==false)
{
//location.reload(true);
alert("Failed To Fetch Data...");


}
else
{

//document.close();

//window.location.href = app4_url + "?token=" + globalToken;
var url1_new = app4_url + "?token=" + globalToken;

//url1_new = encodeURIComponent(app4_url);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(div_name);
       div.innerHTML = '<iframe style="width:100%;height:100%;" frameborder="0" src="' + url1_new + '" />';
    },30);


}

};

res = printAddress()

}


async function createApp4Series(div_name)
{

var curdata = {'token': globalToken };


curdata = JSON.stringify(curdata);
var info = curdata;
var method_type = "GET";


console.log(globalToken);
const address = await fetch(url_app4_series ,{
    method: method_type
});

const printAddress = async () => {
let a = await address

if (a.value==false)
{
//location.reload(true);
alert("Failed To Fetch Data...");


}
else
{

//document.close();

//window.location.href = app4_url + "?token=" + globalToken;
var url1_new = url_app4_series + "?token=" + globalToken;

//url1_new = encodeURIComponent(app4_url);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(div_name);
       div.innerHTML = '<iframe style="width:100%;height:100%;" frameborder="0" src="' + url1_new + '" />';
    },30);


}

};

res = printAddress()

}




function refresh()
{
location.reload(true);
}

async function createApp3(div_name)
{

var curdata = {'token': globalToken };


curdata = JSON.stringify(curdata);
var info = curdata;
var method_type = "GET";


console.log(globalToken);
const address = await fetch(url4 ,{
    method: method_type
});

const printAddress = async () => {
let a = await address

if (a.value==false)
{
//location.reload(true);
alert("Failed To Fetch Data...");


}
else
{

//document.close();

//window.location.href = url1 + "?token=" + globalToken;
var url1_new = url4 + "?token=" + globalToken;

//url1_new = encodeURIComponent(url1);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(div_name);
       div.innerHTML = '<iframe style="width:100%;height:100%;" frameborder="0" src="' + url1_new + '" />';
    },30);


}

};

res = printAddress()

}


async function createApp3Series(div_name)
{

var curdata = {'token': globalToken };


curdata = JSON.stringify(curdata);
var info = curdata;
var method_type = "GET";


console.log(globalToken);
const address = await fetch(url_app3_series ,{
    method: method_type
});

const printAddress = async () => {
let a = await address

if (a.value==false)
{
//location.reload(true);
alert("Failed To Fetch Data...");


}
else
{

//document.close();

//window.location.href = url1 + "?token=" + globalToken;
var url1_new = url_app3_series + "?token=" + globalToken;

//url1_new = encodeURIComponent(url1);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(div_name);
       div.innerHTML = '<iframe style="width:100%;height:100%;" frameborder="0" src="' + url1_new + '" />';
    },30);


}

};

res = printAddress()

}



function refresh()
{
location.reload(true);
}

async function createApp3_a(div_name)
{

var curdata = {'token': globalToken };


curdata = JSON.stringify(curdata);
var info = curdata;
var method_type = "GET";


console.log(globalToken);
const address = await fetch(app_3_a_url ,{
    method: method_type
});

const printAddress = async () => {
let a = await address

if (a.value==false)
{
//location.reload(true);
alert("Failed To Fetch Data...");


}
else
{

//document.close();

//window.location.href = url1 + "?token=" + globalToken;
var url1_new = app_3_a_url + "?token=" + globalToken;

//url1_new = encodeURIComponent(url1);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(div_name);
       div.innerHTML = '<iframe style="width:100%;height:100%;" frameborder="0" src="' + url1_new + '" />';
    },30);


}

};

res = printAddress()

}

async function createApp3_b(div_name)
{

var curdata = {'token': globalToken };


curdata = JSON.stringify(curdata);
var info = curdata;
var method_type = "GET";


console.log(globalToken);
const address = await fetch(app_3_b_url ,{
    method: method_type
});

const printAddress = async () => {
let a = await address

if (a.value==false)
{
//location.reload(true);
alert("Failed To Fetch Data...");


}
else
{

//document.close();

//window.location.href = url1 + "?token=" + globalToken;
var url1_new = app_3_b_url + "?token=" + globalToken;

//url1_new = encodeURIComponent(url1);
    //use timeout coz mousehover fires several times
    clearTimeout(window.ht);
    window.ht = setTimeout(function(){
        var div = document.getElementById(div_name);
       div.innerHTML = '<iframe style="width:100%;height:100%;" frameborder="0" src="' + url1_new + '" />';
    },30);


}

};

res = printAddress()

}


function refresh()
{
location.reload(true);
}


//createApp2("master_view");