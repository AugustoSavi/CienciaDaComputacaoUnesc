import Derivacao from './src/logicaDerivacao.js';


var sentencas = [
    {
      letra: 'S',
      derivacao: ['ABC']
    },
    {
      letra: 'A',
      derivacao: ['BaB', 'c']
    },
    {
      letra: 'B',
      derivacao: ['b', 'bb']
    },
    {
      letra: 'C',
      derivacao: ['a']
    },
    {
      letra:'E',
      derivacao:['e','B']
    }
];

Derivacao(sentencas)


var sentencas1 = [
  {
    letra: 'S',
    derivacao: ['ABE']
  },
  {
    letra: 'A',
    derivacao: ['AaE','B']
  },
  {
    letra: 'B',
    derivacao: ['B', 'b']
  },
  {
    letra:'E',
    derivacao:['e','A']
  }
];

Derivacao(sentencas1);
