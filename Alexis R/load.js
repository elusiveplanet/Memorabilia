
$(function(){
particle_no = 30;

window.requestAnimFrame = (function(){
  return  window.requestAnimationFrame ||
    window.webkitRequestAnimationFrame ||
    window.mozRequestAnimationFrame    ||
    window.oRequestAnimationFrame      ||
    window.msRequestAnimationFrame     ||
    function( callback ){
    window.setTimeout(callback, 1000 / 60);
  };
})();

var canvas = document.getElementById('fire'),
ctx = canvas.getContext("2d");

var counter = 0;
var particles = [];
var w = 1280, h = 125;
canvas.width = w;
canvas.height = h;

function reset(){
  ctx.clearRect(0,0,w,h);

  ctx.fillStyle = "#000000";
  ctx.fillRect(0,0,1280,125);
}

function progressbar(){
  this.widths = 0;
  this.hue = Math.random();

  this.draw = function(){
    ctx.fillStyle = 'hsla('+this.hue+', 100%, 40%, 1)';
    ctx.fillRect(0,75,this.widths,50);
    var grad = ctx.createLinearGradient(0,0,0,130);
    grad.addColorStop(0,"transparent");
    grad.addColorStop(1,"rgba(0,0,0,0.5)");
    ctx.fillStyle = grad;
    ctx.fillRect(0,75,this.widths,50);
  }
}

function particle(){
  this.x = bar.widths;
  this.y = 75;

  this.vx = 0.8 + Math.random()*1;
  this.v = Math.random()*5;
  this.g = 1 + Math.random()*3;
  this.down = false;

  this.draw = function(){
    ctx.fillStyle = 'hsla('+bar.hue+', 100%, 40%, 1)';;
    var size = Math.random()*2;
    ctx.fillRect(this.x, this.y, size, size);
    ctx.fillRect(this.x, this.y + 25, size, size);
    ctx.fillRect(this.x, this.y + 50, size, size);
  }
}

bar = new progressbar();

function draw(){
  reset();
  //counter = globalFire;
  bar.hue = Math.random() * 15;

  bar.widths = globalFire * 9;
  if(!(bar.widths > 1280)){
    bar.draw();
    for(var i=0;i<particle_no;i+=10){
      particles.push(new particle());
    }
  }
  update();
}

function update(){
  for(var i=0;i<particles.length;i++){
    var p = particles[i];
    p.x -= p.vx;
    if(p.down == true){
      p.g += 0.1;
      p.y += p.g;
    }
    else{
      if(p.g<0){
        p.down = true;
        p.g += 0.1;
        p.y += p.g;
      }
      else{
        p.y -= p.g;
        p.g -= 0.1;
      }
    }
    p.draw();
  }
}

function animloop() {
  draw();
  requestAnimFrame(animloop);
}

animloop();

});
