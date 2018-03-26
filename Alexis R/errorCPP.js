// JavaScript Document
function corruption_effect(){
    var pos_y  = parseInt(Math.random()*(the_canvas.height-100));
    var cwidth = the_canvas.width;

    the_canvas.getContext('2d').drawImage(  the_canvas                               ,
                                            0                                        ,
                                            pos_y                                    ,
                                            cwidth                                   ,
                                            100                                      ,
                                            (((parseInt(Math.random()*2)*2)-1) * 50) ,
                                            pos_y                                    ,
                                            cwidth                                   ,
                                            100                                      );
}


function add_image(){
    var rnd_pic = document.getElementById('pic'+parseInt(Math.random()*18));

    the_canvas.getContext('2d').drawImage( rnd_pic                                                    ,
                                           parseInt(Math.random()*(the_canvas.width-rnd_pic.width))   ,
                                           parseInt(Math.random()*(the_canvas.height-rnd_pic.height)) );
}


function do_sound(){
    var rnd_snd = document.getElementById('snd'+parseInt(Math.random()*7));
    rnd_snd.currentTime = 0;
    rnd_snd.play();
}


function run(){
    var the_canvas = document.getElementById('the_canvas');
    if(Math.random() < 0.2){corruption_effect();}
    add_image();
    do_sound();
}


function setsize(){
    var c  = document.getElementById('the_canvas');
    var cd = document.getElementById('canvas_container');
    c.width = cd.clientWidth;
    c.height = cd.clientHeight;
}


window.addEventListener('resize',setsize);
window.addEventListener('load',function(){window.setInterval(run,99);});
setsize();