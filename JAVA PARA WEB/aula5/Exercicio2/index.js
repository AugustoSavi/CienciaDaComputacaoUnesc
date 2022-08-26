const readline = require("readline-sync")
const axios = require('axios');
const fs = require('fs');

let heroes = []
let numbers = [];
let exit = true;
const FILE_PATH = 'heroes_file.json'

// number question
function questionNumber() {
    let readlineNumber = readline.question("Informe um numero entre 1 e 731: ");
    let number = Number(readlineNumber);
    if (Number.isInteger(Number(number)) && number >= 1 && number <= 731) {
        numbers.push(Number(readlineNumber));
    }
}

// exit question
function questionExit() {
    let resposta = readline.question("Deseja inserir outro valor?(y,n)\n");
    exit = resposta.toUpperCase() === 'Y' ? true : false;
}

// retorna a promise da request do hero
function handleRequest(number) {
    return axios.get(`https://akabab.github.io/superhero-api/api/id/${number}.json`);
}

// função para verificar se o arquivo existe ou não,
// se não existir cria o arquivo
function readOrCreateFile(){
    if (fs.existsSync(FILE_PATH)) {
        return heroes = readFile();
    }
    return writeFile([]);
}

// le do arquivo
function readFile(){
    let rawdata = fs.readFileSync(FILE_PATH);
    let heroes = JSON.parse(rawdata);
    return heroes;
}

// escreve no arquivo
function writeFile(data){
    fs.writeFileSync(FILE_PATH, JSON.stringify(data));
}

// retorna o heroes sem objetos duplicados
function getUniqueListBy(arr, key) {
    return [...new Map(arr.map(item => [item[key], item])).values()];
}

// gera o json
function generateJSON() {
    heroes = getUniqueListBy(heroes, 'id');

    if (heroes.length) {
        writeFile(heroes);
    }
}

// faz as requisições do hero
function getHeroes() {
    let promises = [];
    if (numbers.length) {
        for (number of numbers) {
            console.log(`Bucando o hero de id: ${number}`)
            promises.push(handleRequest(number));
        }

        Promise.all(promises)
            .then(values => {
                values.forEach(value => {
                    heroes.push(value.data);
                })
            })
            .catch(err => console.log(`Erro na requisição: ${err}`))
            .finally(generateJSON)
    }
}

// inicia o programa
readOrCreateFile();

do {
    questionNumber();
    questionExit();
} while (exit)

getHeroes();