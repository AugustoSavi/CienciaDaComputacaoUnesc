const bodyParser = require('body-parser');
const request = require('request');
const express = require('express');
const app = express();
const PORT = 5000;
let heroes = [];

app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static('public'));
app.use(express.json());
app.use(express.urlencoded({
    extended: true
}));

app.post('/q', function (req, res) {
    res.contentType('application/json');
    let hero;
    if (req.body.name) {
        hero = getHerobyName(req.body.name);
    }
    if (hero.length) {
        console.log("encontrado");
        res.send(hero);
    }
    else {
        console.log("não encontrado");
        res.send({"error":'SuperHero não encontrado'});
    }
});

function getHerobyName(heroName) {
    console.log(`Procurando pelo heroi: ${heroName}`)
    return heroes.filter(hero => hero.name === heroName);
}

function initHeroes() {
    request('https://akabab.github.io/superhero-api/api/all.json', function (error, response, body) {
        if (!error) {
            heroes = JSON.parse(body);
            console.log(`Heroes adicionados: ${heroes.length}`);
        }
    });
}

app.listen(PORT, function () {
    console.log(`server started: http://localhost:${PORT}`);
    initHeroes();
});