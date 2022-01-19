function expandAlgoViz() {
    console.log("expandAlgoViz yeah");
    const node = document.getElementsByClassName('fa-expand')[0];
    mouseEventOn(node, "click");
}

function compressAlgoViz() {
    console.log("compressAlgoViz yeah");
    const node = document.getElementsByClassName('fa-compress')[0];
    mouseEventOn(node, "click");
}

function mouseEventOn(node, type) {
    const evt = new MouseEvent("click", {
        view: window,
        bubbles: true,
        cancelable: true,
    });
    node.dispatchEvent(evt);
}

function enterFullscreen() {
    console.log("enterFullscreen yeah");
    document.head.requestFullscreen();
}

function exitFullscreen() {
    console.log("exitFullscreen yeah");
    document.exitFullscreen();
}