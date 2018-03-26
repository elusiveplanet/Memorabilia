// JavaScript Document
function drawBall() {
    context.beginPath();
    context.arc(ballX, ballY, ballRadius*2, 0, Math.PI*2);
    context.fillStyle = "black";
    context.fill();
    context.strokeStyle = "#FFFFFF";
    context.stroke();
    context.closePath();
}

function drawPlatform() {
    context.beginPath();
    context.rect(20, 40, 40, 120);
    context.fillStyle = "#23D500";
    context.fill();
    context.closePath();    
}

function draw() {
	if (ballY + ballDY < 0){
		ballDY = -ballDY;
	}
		 
	if (ballY + ballDY > canvas.height){
		ballDY = -ballDY; 
	}
 	
    context.clearRect(0, 0, canvas.width, canvas.height);
     
    drawBall();
    drawPlatform();
     
    ballX = ballX + ballDX;
    ballY = ballY + ballDY;  
}
