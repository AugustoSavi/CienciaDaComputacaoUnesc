


function Derivacao(sentencas) {

  var sentenca = sentencas[0].derivacao[0];

  console.log(`A sentença inicial é: ${sentenca} e seu tamanho é ${sentenca.length}`)

  do {

    for (let i = sentenca.length - 1; i >= 0;) {

      if (sentenca[i] === sentenca[i].toUpperCase()) {

        let posderivacao = sentencas.map(function (e) {
          return e.letra;
        }).indexOf(sentenca[i])

        let stringaux = String(sentenca)
          .replace(String(sentenca[i]),
            sentencas[posderivacao]
              .derivacao[getRandomInt(0, sentencas[posderivacao].derivacao.length - 1)]
          );

        sentenca = stringaux;
        i++;
        
        console.log(sentenca);
      }
      i--;
    }

  } while (sentenca != sentenca.toLowerCase());

  console.log(`a sentença final é ${sentenca} e seu tamanho é ${sentenca.length}`)
  return sentenca;

}

function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

export default Derivacao;
