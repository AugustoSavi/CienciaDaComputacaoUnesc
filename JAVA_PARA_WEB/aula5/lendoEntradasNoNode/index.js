const readline = require("readline")

const bash = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

bash.question("Qual a cor da sua camisa?", (resposta)=>{
    console.log(resposta);
})