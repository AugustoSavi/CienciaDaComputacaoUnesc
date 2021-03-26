CREATE VIEW vw_atividade AS
SELECT c.nomecliente AS `Nome cliente`, p.valor_pedido AS `Valor pedido`, cotacao_dolar(p.valor_pedido, p.data_pedido) AS `cotação Dolar`FROM  pedidos AS p INNER JOIN clientes AS c WHERE c.clienteid = p.clienteid;
                      
select * from vw_atividade;
