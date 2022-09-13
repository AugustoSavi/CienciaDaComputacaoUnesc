const bodyParser = require('body-parser');
const cookieParser = require('cookie-parser');
const express = require('express');
const request = require('request');
var path = require('path');

const app = express();
const PORT = 5000;
const PUBLIC_PATH = 'public';
const fileOptions = {
    root: path.join(__dirname)
};

app.use(express.json());
app.use(cookieParser());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.urlencoded({ extended: true }));

// Pagina inicial
app.get('/', function (req, res) {
    res.sendFile(`${PUBLIC_PATH}/index.html`, fileOptions);
});

// Pagina de login
app.get('/login', function (req, res) {
    res.sendFile(`${PUBLIC_PATH}/login.html`, fileOptions);
});

app.post('/login', cookieLoginHandler, function (req, res) {
    res.sendFile(`${PUBLIC_PATH}/404.html`, fileOptions);
});

// Pagina de cadastro-personagem
app.get('/cadastro-personagens', getCookie, function (req, res) {
    res.sendFile(`${PUBLIC_PATH}/cadastro-personagens.html`, fileOptions);
});

// paginas forbidden
app.get('*', function (req, res) {
    res.contentType('application/json');
    res.status(403).send({ "error": "forbidden" });
});

app.listen(PORT, function () {
    console.log(`server started: http://localhost:${PORT}`);
    initHeroes();
});

function isValidUser({ usuario, senha }) {
    if (usuario && senha) {
        return usuario === 'root' && senha === 'unesc@1234';
    }
    return false;
}

function initHeroes() {
    request('https://akabab.github.io/superhero-api/api/all.json', function (error, response, body) {
        if (!error) {
            heroes = JSON.parse(body);
            console.log(`Heroes adicionados: ${heroes.length}`);
        }
    });
}

function cookieLoginHandler(req, res, next) {
    if (isValidUser(req.body)) {
        setCookie(res, req.body);
        return res.sendFile(`${PUBLIC_PATH}/sucess.html`, fileOptions);
    }
    next();
}

function setCookie(res, value) {
    let options = {
        maxAge: 1000 * 60 * 15, // would expire after 1 minutes
        httpOnly: true, // The cookie only accessible by the web server
    }

    // Set cookie
    res.cookie('login', JSON.stringify(value), options);
}

function getCookie(req, res, next) {
    if (req.cookies.login) {
        let login = JSON.parse(req.cookies.login);
        if (isValidUser(login)) {
            next();
        } else {
            res.sendFile(`${PUBLIC_PATH}/login.html`, fileOptions);
        }
    } else {
        res.sendFile(`${PUBLIC_PATH}/login.html`, fileOptions);
    }
}