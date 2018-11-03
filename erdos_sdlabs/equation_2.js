function eqn(x){
    return Math.pow(x,6) + 8*Math.pow(x,4) - 6*Math.pow(x,2) + 8;
}

function pow6(){
    a = []
    for(var i=0; i<100; i++)
        a.push(Math.pow(i,3))
    return a
}

p6_list = pow6();

for(var x=0; x<20; x++){
    //console.log(x, eqn(x))
    if(a.indexOf(eqn(x))!=-1){
        console.log(x, eqn(x))
    }
}
// x=3, y^2=11
// 57566
