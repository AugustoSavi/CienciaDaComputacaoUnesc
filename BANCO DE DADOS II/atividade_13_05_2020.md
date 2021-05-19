# parte 1
### A) Para que um trajeto seja consistente, a cidade de origem deste trajeto deve ser igual à cidade de origem cadastrada no primeiro segmento do respectivo trajeto. Escreva uma consulta SQL que valide se um trajeto possui o primeiro segmento consistente ou não;

```
SELECT T.trajetoid
 FROM trajeto T, segmento S, estrada E
 WHERE T.trajetoid = S.trajetoid AND S.estradaid = E.estradaid AND
T.cidade_origem <> E.cidade_origem AND S.ordem = 1;

```
### B. Retorne os trajetos de menor quilometragem entre cada origem/destino diferente. Esta consulta deve apresentar para cada um dos trajetos selecionados: cidade origem, cidade destino, menor quilometragem entre elas. A quilometragem de cada trajeto é calculada pela soma da quilometragem de todas as estradas (segmentos de estrada) que compõem o trajeto.
```
CREATE VIEW total_trajeto AS
SELECT T.trajetoid trajid, T.cidade_origem origem, T.cidade_destino destino, SUM(E.extensao_km)
extensao
 FROM trajeto T, segmento S, estrada E
 WHERE T.trajetoid = S.trajetoid AND S.estradaid = E.estradaid
 GROUP BY T.trajetoid, T.cidade_origem, T.cidade_destino;

SELECT origem, destino, MIN(extensao)
 FROM TotalTrajeto
 GROUP BY origem, destino;

```

# parte 2
### Considerando que foi acrescentado na tabela de Trajetos um campo km_total que contém a quilometragem total do trajeto. Escreva: A. Uma stored procedure que dada o id do trajeto calcule a distância total dos segmentos de estrada (tabela estrada) e atualize o valor de km_total no trajeto respectivo;

```
UPDATE Trajeto T
 SET T.extensao_km =
 (SELECT SUM(E.extensao_km)
 FROM Segmento S, Estrada E
 WHERE T.trajetoid = S.trajetoid AND
 S.estradaid = E.estradaid);

```

# parte 3

### Proponha uma normalização (até a 3ª forma normal no mínimo) para o modelo apresentado;
```
CREATE TABLE `cidade` (
  `cidadeid` int PRIMARY KEY AUTO_INCREMENT,
  `nome` varchar(100)
);

CREATE TABLE `estrada` (
  `estradaid` int PRIMARY KEY AUTO_INCREMENT,
  `nome` varchar(100),
  `fk_cidade_origem` int,
  `fk_cidade_destino` int,
  `extensao_km` int
);

CREATE TABLE `segmento` (
  `segmentoid` int PRIMARY KEY AUTO_INCREMENT,
  `fk_trajetoid` int,
  `fk_estradaid` int,
  `ordem` int
);

CREATE TABLE `trajeto` (
  `trajetoid` int PRIMARY KEY AUTO_INCREMENT,
  `fk_cidade_origem` int,
  `fk_cidade_destino` int
);

ALTER TABLE `trajeto` ADD FOREIGN KEY (`fk_cidade_origem`) REFERENCES `cidade` (`cidadeid`);

ALTER TABLE `trajeto` ADD FOREIGN KEY (`fk_cidade_destino`) REFERENCES `cidade` (`cidadeid`);

ALTER TABLE `estrada` ADD FOREIGN KEY (`fk_cidade_origem`) REFERENCES `cidade` (`cidadeid`);

ALTER TABLE `estrada` ADD FOREIGN KEY (`fk_cidade_destino`) REFERENCES `cidade` (`cidadeid`);

ALTER TABLE `segmento` ADD FOREIGN KEY (`fk_estradaid`) REFERENCES `estrada` (`estradaid`);

ALTER TABLE `segmento` ADD FOREIGN KEY (`fk_trajetoid`) REFERENCES `trajeto` (`trajetoid`);
```