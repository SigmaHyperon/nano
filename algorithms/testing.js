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
var waitx = 0;
var activealgorithm = 0;
var showinfo = 0;
var rec = 1;

function setup() {
  createCanvas(windowWidth, windowHeight);
  background(128);
}

function draw() {
  textAlign(CENTER, CENTER);
  background(128);
  for (i in connections) {
    fill(connections[i].color);
    stroke(connections[i].color);
    connections[i].xs = allElements[connections[i].e1].x + (boxSize / 2);
    connections[i].ys = allElements[connections[i].e1].y + (boxSize / 2);
    connections[i].xe = allElements[connections[i].e2].x + (boxSize / 2);
    connections[i].ye = allElements[connections[i].e2].y + (boxSize / 2);

    strokeWeight(5);
    line(connections[i].xs, connections[i].ys, connections[i].xe, connections[i].ye);
    textSize(25);
    var point = {};
    point = getTextPosition(connections[i]);
    noStroke();
    fill(0, 0, 255);
    text(connections[i].w.toString(), point.x, point.y, 0, 100);
  }
  stroke(0);
  for (i in rects) {
    fill(rects[i].color);
    strokeWeight(1);
    rect(rects[i].x, rects[i].y, boxSize, boxSize);
    fill(0);
    textSize(40);
    text(rects[i].id.toString(), rects[i].x, rects[i].y, boxSize, boxSize);
  }
}

function getTextPosition(val) {
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
          if (index == undefined) {
            index = i;
            break;
          }
        }
      }
    }
    if (index != undefined) {
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
            if (ce1 == undefined) {
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
  for (i in connections) {
    if (connections[i].e1 == ce1.i && connections[i].e2 == ce2.i || connections[i].e1 == ce2.i && connections[i].e2 == ce1.i) {
      ce1 = undefined;
      ce2 = undefined;
      return;
    }
  }
  if (ce1.i != ce2.i) {
    var myline = {};
    myline.elem = 'C';
    myline.xs = ce1.x + (boxSize / 2);
    myline.ys = ce1.y + (boxSize / 2);
    myline.xe = ce2.x + (boxSize / 2);
    myline.ye = ce2.y + (boxSize / 2);
    myline.e1 = Number(ce1.i);
    myline.e2 = Number(ce2.i);
    var w = prompt("Enter weight of connection (weight >0)", "");
    if (w <= 0) {
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

function mouseReleased() {
  index = undefined;
}

function keyPressed() {
  //console.log(keyCode);
  if (keyCode == 191) {
    var x = prompt("Please enter your command! ('help' for more information)", "");
    if (x == "help") {
      alert("dijkstra - Show Dijkstras Algorithm\ni - Show informationpanel for algorithm (not in commandline!)");
    }
    if (x == "dijkstra") {
      activealgorithm = 1;
      calcAlgorithm(activealgorithm);
    }
  }
  if (keyCode == 88) {
    if (showinfo == 0) {
      showinfo = 1;
      document.getElementById('idpan').style.display = "block";
    } else {
      stepper = 1;
      showinfo = 0;
      document.getElementById('idpan').style.display = "none";
    }
  }
  if (keyCode == 86) {
    var r = {};
    r.elem = 'R';
    r.x = mouseX;
    r.y = mouseY;
    r.color = color(128, 128, 255);

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

function calcAlgorithm(val) {
  if (val == 1) {
    calcDijkstra();
  }
}

function calcDijkstra() {
  var s = prompt("Please enter the startnode-number!", "0");
  waitx = prompt("How long should each action take? (in ms)", "1");
  alert("Log will be found with key 'x'!");
  if (waitx <= 0) {
    waitx = 1;
  }
  if (s >= rects.length - 1) {
    alert("Vertex not found!");
    return;
  }
  addinfopan("Settings all nodes to maximum score! Setting start node to score of 0.");
  for (i in rects) {
    rects[i].score = Number.MAX_SAFE_INTEGER;
    rects[i].visited = false;
  }
  rects[s].score = Number(0);
  for (i in connections) {
    cons.push(connections[i]);
  }
  dijkstra(s);
}

async function dijkstra(val) {
  if (val > rects.length - 1) {
    addinfopan("There are no more nodes left!");
    return;
  }
  await sleep(waitx);
  addinfopan("Setting var 'score' to " + rects[val].score + " of rect #" + val);
  var score = Number(rects[val].score);
  await sleep(waitx);
  addinfopan("Save that rect #" + val + " has been visited");
  rects[val].visited = true;
  rects[val].color = color(0, 255, 0);
  await sleep(waitx);
  var l = cons.length;
  var c = 1;
  for (var i = 0; i < cons.length; i++) {
    addinfopan("Checking connection " + c + " of " + l);
    await sleep(waitx);
    if (cons[i].e1 == val || cons[i].e2 == val) { //if connection connects to actual point;
      addinfopan("Connection is somehow connecting with rect #" + val);
      await sleep(waitx);
      if (cons[i].e1 != val) { //Swap if necessary
        addinfopan("Swapping connection vars for algorithm");
        await sleep(waitx);
        var tmp = cons[i].e1;
        cons[i].e1 = cons[i].e2;
        cons[i].e2 = tmp;
      }
      if (rects[cons[i].e2].score > Number(score + cons[i].w)) {
        addinfopan("rect #" + cons[i].e2 + "'s score " + rects[cons[i].e2].score + " is higher then the new score of " + Number(score + cons[i].w));
        addinfopan("Set new score...");
        rects[cons[i].e2].score = score + cons[i].w;
        await sleep(waitx);
        if (rects[cons[i].e2].connector == undefined) {
          addinfopan("rect #" + cons[i].e2 + " has no other connection so far... Setting up connector and make the connection green");
          rects[cons[i].e2].connector = cons[i].id;
          connections[cons[i].id].color = color(0, 255, 0);
        } else {
          addinfopan("rect #" + cons[i].e2 + " had another connection. Make old connection red; replace it with new connection and make this new connection green");
          connections[rects[cons[i].e2].connector].color = color(255, 0, 0);
          rects[cons[i].e2].connector = cons[i].id;
          connections[rects[cons[i].e2].connector].color = color(0, 255, 0);
        }
        await sleep(waitx);
      } else {
        addinfopan("Keeping old score of rect " + cons[i].e2);
      }
      addinfopan("Removing checked connection from temporary array");
      popcon(cons[i].id);
      i--;
      await sleep(waitx);
    }
    addinfopan("connection #" + c + " had been checked");
    c++;
    await sleep(waitx);
  }
  addinfopan("Searching for the next lowest rect that has not been visited");
  var low = Number.MAX_SAFE_INTEGER;
  var tmp = undefined;
  await sleep(waitx);
  for (x in rects) {
    if (!rects[x].visited) {
      if (rects[x].score < low) {
        low = rects[x].score;
        tmp = x;
      }
    }
  }
  await sleep(waitx);
  addinfopan(x + " is the next rect!");
  if (tmp != undefined) {
    rec++;
    addinfopan("Recursive call of function");
    await sleep(waitx);
    dijkstra(tmp);
  }
  addinfopan("Done Recursive step #" + rec--);
  await sleep(waitx);
}

function popcon(val) {
  for (i in cons) {
    if (cons[i].id == val) {
      cons.splice(i, 1);
      return;
    }
  }
}

function addinfopan(val) {
  document.getElementById('idpan').innerHTML += val + "<br>";
}

function sleep(ms){
  return new Promise(resolve => setTimeout(resolve, ms));
}
