const argvs = process.argv

let numbers = argvs.filter((number) => Number.isInteger(Number(number)))
    .map(function (item) {
        return parseInt(item);
    })
    .filter((n) => n % 2 === 0)

if (numbers.length) {
    console.log(numbers.reduce(function (acumulador, valorAtual, index, array) {
        return acumulador + valorAtual;
    }))
}

