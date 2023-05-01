//var completeBtn =document.getElementById("")
let queue = JSON.parse(localStorage.getItem("queue"));
/*if (!queue) {
    queue = [0];
}*/

window.addEventListener('load',() => {
    for(var i =1;i<5;i++)
    {
        var button= document.getElementById("C"+i+"Next")
        button.disabled="true"
        
    }
    
});

function offline(id,StatusCur)
{
    var status = JSON.parse(localStorage.getItem(StatusCur));
    if(status==true)
    {
        document.getElementById(id).innerHTML="Go Online"
        document.getElementById(id+"Next").disabled=true
        status=false
        localStorage.setItem(StatusCur, JSON.stringify(status))

    }
    else{
        document.getElementById(id).innerHTML="Go Offline"
        document.getElementById(id+"Next").disabled=false
        status=true
        localStorage.setItem(StatusCur, JSON.stringify(status))
    }

}

function complete(CounterCur)
{
    var NumCur = '';
    localStorage.setItem(CounterCur, NumCur.toString());
}

function callNext(CounterCur)
{
    
    
    let queue = JSON.parse(localStorage.getItem("queue"));
    if(queue[0]==0)
        {
            queue.shift()
        }
    var nextnum=parseInt(queue[0])
    
    var NumCur = parseInt(localStorage.getItem(CounterCur));
    if (NumCur==''||!NumCur) {
        
        queue.shift()
        NumCur = nextnum;
        localStorage.setItem(CounterCur, NumCur.toString());
        localStorage.setItem("queue", JSON.stringify(queue));
    }
    
}

/*function callNext(CounterCur)
{
    let queue = JSON.parse(localStorage.getItem("queue"));
    var nextnum=parseInt(queue[0])
    queue.shift()
    var NumCur = parseInt(localStorage.getItem(CounterCur));
    if (!C1current) {
        C1current = 0;
    }
    C1current = nextnum;
    localStorage.setItem('C1current', C1current.toString());
    localStorage.setItem("queue", JSON.stringify(queue));

}*/