var wSocket = new WebSocket('ws://localhost:1234');

wSocket.onOpen = function(evt) {
alert('connected...');
};

wSocket.onClose = function(evt) {
alert('close...');
};

wSocket.onMessage = function(evt) {
alert(evt.value);
};

wSocket.onError = function(evt) {
alert('caught an error...');
};

function enviar() {
var txt = document.getElementById('txt');
var val = txt.value;
wSocket.send(val);
}
