const bodyParser = require('body-parser');
const cookieParser = require('cookie-parser');
const express = require('express');
const request = require('request');
var path = require('path');

const app = express();
const PORT = 5000;
const PUBLIC_PATH = 'views';
const fileOptions = {
    root: path.join(__dirname)
};

let heroes;
let ganhadoresDaRodada = [];

app.use(express.json());
app.use(cookieParser());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.urlencoded({ extended: true }));

// Pagina inicial
app.get('/home', function (req, res) {
    res.sendFile(`${PUBLIC_PATH}/index.html`, fileOptions);
});

// Pagina de login
app.get('/', function (req, res) {
    res.sendFile(`${PUBLIC_PATH}/login.html`, fileOptions);
});

app.post('/login', cookieLoginHandler, function (req, res) {
    res.sendFile(`${PUBLIC_PATH}/404.html`, fileOptions);
});

// Pagina de cadastro-personagem
app.get('/cadastro-personagens', getCookie, function (req, res) {
    res.sendFile(`${PUBLIC_PATH}/cadastro-personagens.html`, fileOptions);
});

// Pagina Game
app.get('/game', getCookie, function (req, res) {
    res.sendFile(`${PUBLIC_PATH}/game.html`, fileOptions);
});

// EndPoint retorna as 20 cartas
app.get('/game/cartas', getCookie, function (req, res) {
    res.send(getVinteCartas());
});

// Endpoint para setar o ganhador 
app.post('/game/ganhador', getCookie, function (req, res) {
    if (ganhadoresDaRodada.length < 9) {
        ganhadoresDaRodada.push(req.body);
        res.status(200).end();
    }
    else {
        res.status(403).end();
    }
});

// manda a url da pagina do ganhador
app.get('/game/ganhador', getCookie, function (req, res) {
    res.send({rota:`/game/${getFileGanhador()}`});
});

// Retorna a pagina do ganhador
app.get('/game/jogador-numero-one-ganhou', getCookie, function (req, res) {
    res.sendFile(`${PUBLIC_PATH}/jogador-numero-one-ganhou.html`, fileOptions);
});

app.get('/game/jogador-numero-two-ganhou', getCookie, function (req, res) {
    res.sendFile(`${PUBLIC_PATH}/jogador-numero-two-ganhou.html`, fileOptions);
});

app.get('/game/houve-mais-empate', getCookie, function (req, res) {
    res.sendFile(`${PUBLIC_PATH}/houve-mais-empate.html`, fileOptions);
});


// paginas forbidden
app.get('*', function (req, res) {
    res.contentType('application/json');
    res.status(403).send({ "error": "forbidden" });
});

// server
app.listen(PORT, function () {
    console.log(`server started: http://localhost:${PORT}`);
    initHeroes();
});


function getFileGanhador() {
    let numeroVitoriasPlayerOne = ganhadoresDaRodada.filter(ganhador => ganhador.ganhador === 0).length;
    let numeroVitoriasPlayerTwo = ganhadoresDaRodada.filter(ganhador => ganhador.ganhador === 1).length;
    let numeroEmplates = ganhadoresDaRodada.filter(ganhador => ganhador.ganhador === 2).length;
    
    ganhadoresDaRodada = [];

    if (numeroVitoriasPlayerOne > numeroVitoriasPlayerTwo) {
        return 'jogador-numero-one-ganhou';
    } else if (numeroVitoriasPlayerTwo > numeroVitoriasPlayerOne) {
        return 'jogador-numero-two-ganhou';
    } else if ((numeroEmplates > numeroVitoriasPlayerOne && numeroEmplates > numeroVitoriasPlayerTwo) || numeroVitoriasPlayerOne === numeroVitoriasPlayerTwo) {
        return 'houve-mais-empate';
    }
}

// Valida o usuario
function isValidUser({ usuario, senha }) {
    if (usuario && senha) {
        return usuario === 'root' && senha === 'unesc@1234';
    }
    return false;
}

// Carrega os heroes
function initHeroes() {
    request('https://akabab.github.io/superhero-api/api/all.json', function (error, response, body) {
        if (!error) {
            heroes = JSON.parse(body);
            console.log(`Heroes adicionados: ${heroes.length}`);
        }
    });
}

// Cookie handler 
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

function getVinteCartas() {
    let cartasSorteadas = [[], []];

    do {
        cartasSorteadas[0].push(heroes[Math.floor(Math.random() * heroes.length)]);

        cartasSorteadas[0] = cartasSorteadas[0].reduce((acc, current) => {
            const x = acc.find(item => item.id === current.id);
            if (!x) {
                return acc.concat([current]);
            } else {
                return acc;
            }
        }, []);
    } while (cartasSorteadas[0].length < 10);

    do {
        cartasSorteadas[1].push(heroes[Math.floor(Math.random() * heroes.length)]);

        cartasSorteadas[1] = cartasSorteadas[1].reduce((acc, current) => {
            const x = acc.find(item => item.id === current.id);
            if (!x) {
                return acc.concat([current]);
            } else {
                return acc;
            }
        }, []);
    } while (cartasSorteadas[1].length < 10);

    return cartasSorteadas;
}