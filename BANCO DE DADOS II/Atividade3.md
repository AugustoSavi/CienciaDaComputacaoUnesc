Utilizando a base de dados NorthWind, desenvolva um script que empregue o uso de algum tipo de JOIN (LEFT, INNER, RIGHT, OUTER, UNION). Este script deverá permitir consultar os 3 funcionários com maior volume de vendas. Para isso a consulta deverá exibir o nome, data de admissão e o montante total de vendas.

```
SET GLOBAL sql_mode=(SELECT REPLACE(@@sql_mode,'ONLY_FULL_GROUP_BY',''));

select func.nome as "Nome", func.DataAdmissao as "Data admissão", SUM(det.PrecoUnitario * det.Quantidade - det.Desconto) as 'Total vendas'
from funcionarios func  inner join ordens o on func.IDFuncionario = o.IDFuncionario
inner join ordens_detalhes det on det.IDOrdem = o.IDOrdem
group by func.nome
order by 'Total vendas' desc
limit 3;
```
