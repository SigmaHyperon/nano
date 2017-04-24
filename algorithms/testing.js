var allElements = [];
var ce1 = undefined; //connectelement1
var ce2 = undefined; //connectelement2
var index; //Index for repositioning with mouse
var connections = [];
var rects = [];
var counter = 0;
var boxSize = 75;
var optimalPath = [];
var countercon = 0;
var cons = [];

function setup() {
  createCanvas(windowWidth, windowHeight);
  background(128);
}

function draw() {
  textAlign(CENTER, CENTER);
  background(128);
  for(i in connections){
    fill(connections[i].color);
    stroke(connections[i].color);
    connections[i].xs = allElements[connections[i].e1].x + (boxSize/2);
    connections[i].ys = allElements[connections[i].e1].y + (boxSize/2);
    connections[i].xe = allElements[connections[i].e2].x + (boxSize/2);
    connections[i].ye = allElements[connections[i].e2].y + (boxSize/2);

    strokeWeight(5);
    line(connections[i].xs, connections[i].ys, connections[i].xe, connections[i].ye);
    textSize(25);
    var point = {};
    point = getTextPosition(connections[i]);
    noStroke();
    fill(0,0,255);
    text(connections[i].w.toString(), point.x, point.y, 0,100);
  }
  stroke(0);
  for(i in rects){
    fill(rects[i].color);
    strokeWeight(1);
    rect(rects[i].x, rects[i].y, boxSize, boxSize);
    fill(0);
    textSize(40);
    text(rects[i].id.toString(), rects[i].x, rects[i].y, boxSize, boxSize);
  }
}

function getTextPosition(val){
  var point = {};
  point.x = (val.xs + val.xe) / 2;
  point.y = (val.ys + val.ye) / 2;
  //point.y -= 50;
  return point;
}

function mouseDragged() {
  if (mouseButton == LEFT) {
    for (i in allElements) {
      if (mouseX >= allElements[i].x && mouseX <= allElements[i].x + boxSize) {
        if (mouseY >= allElements[i].y && mouseY <= allElements[i].y + boxSize) {
          if(index == undefined){
          index = i;
          break;
        }
        }
      }
    }
    if(index != undefined){
      allElements[index].x = mouseX;
      allElements[index].y = mouseY;
  }
  }
}

function mousePressed() {
  if (mouseButton == LEFT) {

  }
  if (mouseButton == RIGHT) {
    for (i in allElements) {
      if (allElements[i].elem == 'R') {
        if (mouseX >= allElements[i].x && mouseX <= allElements[i].x + boxSize) {
          if (mouseY >= allElements[i].y && mouseY <= allElements[i].y + boxSize) {
            if(ce1 == undefined){
              ce1 = allElements[i];
              ce1.i = i;
              break;
            } else {
              ce2 = allElements[i];
              ce2.i = i;
              makeConnection();
              break;
            }
          }
        }
      }
    }
  }
}

function makeConnection() {
  for(i in connections){
    if(connections[i].e1 == ce1.i && connections[i].e2 == ce2.i || connections[i].e1 == ce2.i && connections[i].e2 == ce1.i){
      ce1 = undefined;
      ce2 = undefined;
      return;
    }
  }
  if (ce1.i != ce2.i) {
    var myline = {};
    myline.elem = 'C';
    myline.xs = ce1.x + (boxSize/2);
    myline.ys = ce1.y + (boxSize/2);
    myline.xe = ce2.x + (boxSize/2);
    myline.ye = ce2.y + (boxSize/2);
    myline.e1 = Number(ce1.i);
    myline.e2 = Number(ce2.i);
    var w = prompt("Enter weight of connection (weight >0)", "");
    if(w <= 0){
      ce1 = undefined;
      ce2 = undefined;
      alert("Invalid Argument!");
      return;
    }
    myline.w = Number(w);
    myline.id = Number(countercon++);
    myline.color = color(0);

    allElements.push(myline);
    connections.push(myline);
  }
  ce1 = undefined;
  ce2 = undefined;
}

function mouseReleased(){
  index = undefined;
}

function keyPressed(){
  //console.log(keyCode);
  if(keyCode == 191){
    var x = prompt("Please enter your command! ('help' for more information)", "");
    if(x == "help"){
      alert("dijkstra - Show Dijkstras Algorithm");
    }
    if(x == "dijkstra"){
      calcDijkstra();
    }
  }
  if(keyCode == 86){
    var r = {};
    r.elem = 'R';
    r.x = mouseX;
    r.y = mouseY;
    r.color = color(0,0,255);

    for (i in allElements) {
      if (allElements[i].elem == 'R') {
        if (r.x >= allElements[i].x && r.x <= allElements[i].x + boxSize) {
          if (r.y >= allElements[i].y && r.y <= allElements[i].x + boxSize) {
            return;
          }
        }
      }
    }
    r.id = Number(counter++);
    allElements.push(r);
    rects.push(r);
  }
}

function calcDijkstra(){
  var s = prompt("Please enter the startnode-number!", "0");
  if(s >= rects.length - 1){
    alert("Vertex not found!");
    return;
  }
  for(i in rects){
    rects[i].score = Number.MAX_SAFE_INTEGER;
    rects[i].visited = false;
  }
  rects[s].score =Number(0);
  for(i in connections){
    cons.push(connections[i]);
  }
  dijkstra(s);
}

function dijkstra(val){
  if(val > rects.length - 1){
    return;
  }
  console.log("Setting var 'score' to " + rects[val].score + " of rect " + val);
  var score = Number(rects[val].score);
  console.log("Save that rect " + val + " has been visited");
  rects[val].visited = true;
  for(var i = 0; i < cons.length; i++){
    console.log("Checking connection " + i + " of " + cons.length);
    if(cons[i].e1 == val || cons[i].e2 == val){//if connection connects to actual point;
      console.log("Connection is somehow connecting with element " + val);
      if(cons[i].e1 != val){ //Swap if necessary
        console.log("Swapping connection vars for algorithm");
        var tmp = cons[i].e1;
        cons[i].e1 = cons[i].e2;
        cons[i].e2 = tmp;
      }
      if(rects[cons[i].e2].score > Number(score + cons[i].w)){
        console.log("rect " + cons[i].e2 + "'s score " + rects[cons[i].e2].score + " is higher then the new score of " + Number(score + cons[i].w));
        rects[cons[i].e2].score = score + cons[i].w;
        if(rects[cons[i].e2].connector == undefined){
          console.log("rect " + cons[i].e2 + " has no other connection so far... Setting up connector and make the connection green");
          rects[cons[i].e2].connector = cons[i].id;
          //console.log(rects[cons[i].e2].connector);
          console.log("i: " + Number(i));
          console.log("cons[i].id: " + Number(cons[i].id));
          console.log(connections);
          connections[cons[i].id].color = color(0, 255, 0);
        } else {
          console.log("rect " + cons[i].e2 + " had another connection. Make old connection red; replace it with new connection and make this new connection green");
          connections[rects[cons[i].e2].connector].color = color(255, 0, 0);
          rects[cons[i].e2].connector = cons[i].id;
          connections[rects[cons[i].e2].connector].color = color(0, 255, 0);
        }
        rects[val].color = color(0,255,0);
      } else {
        console.log("Keeping old score of rect " + cons[i].e2);
      }
      console.log("Pop out the connection that was tested");
      console.log(" before pop: " + connections);
      popcon(cons[i].id);
      console.log(" after pop: " + connections);
      i--;
    }
  }
  console.log("Searching for the next lowest Vertex that has not been visited");
  var low = Number.MAX_SAFE_INTEGER;
  var tmp = undefined;
  for(x in rects){
    if(!rects[x].visited){
      if(rects[x].score < low){
        console.log(x + " is the next rect!");
        low = rects[x].score;
        tmp = x;
      }
    }
  }
  if(tmp != undefined){
    dijkstra(tmp);
  }
  console.log("DONE");
}

function popcon(val){
  for(i in cons){
    if(cons[i].id == val){
      cons.splice(i, 1);
      return;
    }
  }
}
