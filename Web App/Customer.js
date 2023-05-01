
let queue = JSON.parse(localStorage.getItem("queue"));
let C1current = parseInt(localStorage.getItem("C1current"));
let C2current = parseInt(localStorage.getItem("C2current"));
let C3current = parseInt(localStorage.getItem("C3current"));
let C4current = parseInt(localStorage.getItem("C4current"));

var nowDisplay=document.getElementById('nowServing')
var lastDisplay=document.getElementById('lastNumber')

    
var CtnDisplay_1=document.getElementById('counter1')
var CtnDisplay_2=document.getElementById('counter2')
var CtnDisplay_3=document.getElementById('counter3')
var CtnDisplay_4=document.getElementById('counter4')




if (!queue) {
    queue = [0];
}

window.addEventListener('load',() => {
    var C1status = JSON.parse(localStorage.getItem("C1status"));
    var C2status = JSON.parse(localStorage.getItem("C2status"));
    var C3status = JSON.parse(localStorage.getItem("C3status"));
    var C4status = JSON.parse(localStorage.getItem("C4status"));
    for(var i =1;i<5;i++)
    {
        var Cstatus=JSON.parse(localStorage.getItem("C"+i+"status"));
        if(!Cstatus)
        {
            Cstatus=false;
            localStorage.setItem("C"+i+"status", JSON.stringify(Cstatus));
        }

        var Ccurrent=parseInt(localStorage.getItem("C"+i+"current"));
        var circleId='circle'+i
        var circle=document.getElementById(circleId);
        circle.className = (Cstatus && Ccurrent === "") || (Cstatus && !Ccurrent) ? "bi bi-circle-fill text-success"
                  : (Cstatus && Ccurrent !== "") || (Cstatus && Ccurrent) ? "bi bi-circle-fill text-danger"
                  : "bi bi-circle-fill text-muted";

        var Counter = "Cctn"+i
        background=document.getElementById(Counter)
        if(Cstatus==true)
        {
            background.style.backgroundColor="wheat"
        }
        else if(Cstatus==false)
        {
            background.style.backgroundColor="#8C979A"
        }
    }
    
});

window.addEventListener('storage', () => {
    var queue = JSON.parse(localStorage.getItem("queue"));
   /* var C1current = parseInt(localStorage.getItem("C1current"));
    var C2current = parseInt(localStorage.getItem("C2current"));
    var C3current = parseInt(localStorage.getItem("C3current"));
    var C4current = parseInt(localStorage.getItem("C4current"));*/
    nowDisplay.innerHTML=queue[0];
    /*CtnDisplay_1.innerHTML=C1current?C1current:"";
    CtnDisplay_2.innerHTML=C2current?C2current:"";
    CtnDisplay_3.innerHTML=C3current?C3current:"";
    CtnDisplay_4.innerHTML=C4current?C4current:"";*/
    
    for(var i=1;i<5;i++)
    {
        var CtnDisplay=document.getElementById('counter'+i);
        var Ccurrent = parseInt(localStorage.getItem("C"+i+"current"));
        CtnDisplay.innerHTML=Ccurrent?Ccurrent:"";
        var Ccurrent=parseInt(localStorage.getItem("C"+i+"current"));

        var circleId='circle'+i
        var circle=document.getElementById(circleId);
        var Cstatus=JSON.parse(localStorage.getItem("C"+i+"status"));
        circle.className = (Cstatus && Ccurrent === "") || (Cstatus && !Ccurrent) ? "bi bi-circle-fill text-success"
                  : (Cstatus && Ccurrent !== "") || (Cstatus && Ccurrent) ? "bi bi-circle-fill text-danger"
                  : "bi bi-circle-fill text-muted";

        
        var Counter = "Cctn"+i
        var display="CtnDisplay_"+i
        background=document.getElementById(Counter)
        if(Cstatus==true)
        {
            background.style.backgroundColor="wheat"
            
        }
        else if(Cstatus==false)
        {
            background.style.backgroundColor="#8C979A"
            CtnDisplay.innerHTML="Offline"
        }
    }

  });
//nowDisplay.innerHTML=queue[0]
lastDisplay.innerText = queue[queue.length - 1];
//CtnDisplay_1.innerHTML=C1current

var count =0 
var last
function takeNumber()
{
    var queue = JSON.parse(localStorage.getItem("queue"));
    if (!queue) {
        queue = [0];
    }
    count++;
    last= queue[queue.length -1 ]

    queue.push(last+1);


    localStorage.setItem("queue", JSON.stringify(queue));
    lastDisplay.innerText = queue[queue.length - 1];
}