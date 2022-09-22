const bodyParser = require('body-parser');
const express = require('express');
var path = require('path');

const app = express();
const PORT = 5000;
const PUBLIC_PATH = 'public';
const fileOptions = {
    root: path.join(__dirname)
};

app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.json());
app.use(express.urlencoded({
    extended: true
}));

app.get('/login', function (req, res) {
    
    res.sendFile(`${PUBLIC_PATH}/login.html`, fileOptions);
});

app.post('/login', function (req, res) {
    if(isValidUser(req.body)) {
        return res.sendFile(`${PUBLIC_PATH}/sucess.html`, fileOptions);
    }
    return res.sendFile(`${PUBLIC_PATH}/404.html`, fileOptions);
})

app.get('*', function(req, res){
    res.contentType('application/json');
    res.status(403).send({"error": "forbidden"});
});

app.listen(PORT, function () {
    console.log(`server started: http://localhost:${PORT}`);
});

function isValidUser({usuario, senha}){
    if(usuario && senha){
        return usuario === 'root' && senha === 'unesc@1234';
    }
    return false;
}