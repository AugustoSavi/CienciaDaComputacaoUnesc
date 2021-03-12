CREATE TABLE `cotacao` (
  `idCotacao` int NOT NULL AUTO_INCREMENT,
  `vlCotacao` double DEFAULT NULL,
  `dtCotacao` datetime DEFAULT NULL,
  PRIMARY KEY (`idCotacao`)
)


SELECT pedidoid as Pedido, 
data_pedido as 'Data', 
valor_pedido as 'Valor R$',
Round(
(select p.valor_pedido / vlcotacao from cotacao where dtCotacao <= p.data_pedido limit 1),
 2) as 'Valor  US$'
from pedidos p;
