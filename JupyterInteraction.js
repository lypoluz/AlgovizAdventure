function expandAlgoViz() {
    const node = document.getElementsByClassName('fa-expand')[0];
    mouseEventOn(node, "click");
}

function compressAlgoViz() {
    const node = document.getElementsByClassName('fa-compress')[0];
    mouseEventOn(node, "click");
}

function focusGame() {
    const node = document.getElementById('_0');
    mouseEventOn(node, "click");
}

function enterFullscreen() {
    document.head.requestFullscreen();
}

function exitFullscreen() {
    document.exitFullscreen();
}


function mouseEventOn(node, type="click") {
    const evt = new MouseEvent(type, {
        view: window,
        bubbles: true,
        cancelable: true,
    });
    node.dispatchEvent(evt);
}
