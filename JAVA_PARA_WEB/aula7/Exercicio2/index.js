const express = require('express');
const fs = require('fs');
var path = require('path');

const app = express();
const PORT = 5000;
const FILE_PATH = 'public/'

app.get('/imagens/:name', function (req, res) {
    var options = {
        root: path.join(__dirname)
    };

    console.log(`${FILE_PATH}${req.params.name}.jpg`)
    if (req.params.name && fs.existsSync(`${FILE_PATH}${req.params.name}.jpg`)) {
        res.sendFile(`${FILE_PATH}${req.params.name}.jpg`, options);
    } else {
        res.status(404).send(`Imagem não encontrada: ${req.params.name}`);
    }
});

app.get('*', function(req, res){
    res.status(404).send('Rota não encontrada');
});

app.listen(PORT, function () {
    console.log(`server started: http://localhost:${PORT}`);
});