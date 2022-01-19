function expandAlgoViz() {
    const node = document.getElementsByClassName('fa-expand')[0];
    mouseEventOn(node, "click");
}

function compressAlgoViz() {
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
    document.head.requestFullscreen();
}

function exitFullscreen() {
    document.exitFullscreen();
}