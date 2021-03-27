# Acesse o [banco teste de full join online aqui](https://www.db-fiddle.com/f/urBBrBP8Ee2raTqpViGeLf/1)

**Schema (MySQL v8.0)**

    CREATE TABLE `clientes` (
      `ClienteID` int(11) NOT NULL auto_increment,
      `NomeCliente` varchar(50) default NULL,
      PRIMARY KEY  (`ClienteID`)
    ) AUTO_INCREMENT=1;
    
    insert  into `clientes`(`ClienteID`,`NomeCliente`) values 
    (1,'Bob'),
    (2,'Lee'),
    (3,'Jane'),
    (4,'Mary'),
    (5,'Adriaan'),
    (6,'Yeshe'),
    (7,'Charmian'),
    (8,'Tex'),
    (9,'James'),
    (10,'Scott'),
    (11,'Mavis'),
    (12,'Morton'),
    (13,'Monica'),
    (14,'Amos'),
    (15,'Pietro'),
    (16,'Amosa'),
    (17,'Marvin'),
    (18,'Duncan'),
    (19,'Brandon'),
    (20,'Raul'),
    (21,'Jean'),
    (23,'Augusto');
    
    CREATE TABLE `pedidos` (
      `pedidoID` int(11) NOT NULL auto_increment,
      `clienteID` int(11),
      `data_pedido` date NOT NULL,
      `data_saida` date default NULL,
      `data_entrega` date default NULL,
      `valor_pedido` decimal(10,2) NOT NULL,
      PRIMARY KEY  (`pedidoID`)
    ) AUTO_INCREMENT=1;
    
    insert  into `pedidos`(`pedidoID`,`clienteID`,`data_pedido`,`data_saida`,`data_entrega`,`valor_pedido`) values 
    (1,1,'2006-11-19','2006-11-19','2006-11-24','480.00'),
    (2,2,'2006-11-19','2006-11-24','2006-11-29','295.00'),
    (3,3,'2006-12-20','2006-12-20','2006-12-25','650.00'),
    (4,4,'2007-12-22','2007-12-23','2007-12-29','240.00'),
    (5,5,'2007-01-21','2007-01-22','2007-01-28','600.00'),
    (6,6,'2007-01-21','2007-01-22','2007-01-27','2720.00'),
    (7,7,'2007-01-24','2007-01-25','2007-01-28','260.00'),
    (8,8,'2007-01-27','2007-01-29','2007-01-31','1840.00'),
    (9,9,'2007-02-01','2007-02-01','2007-02-01','780.00'),
    (10,10,'2007-02-01','2007-02-01','2007-02-01','2240.00'),
    (11,11,'2007-02-03','2007-02-03','2007-02-08','1500.00'),
    (12,12,'2007-02-03','2007-02-03','2007-02-09','450.00'),
    (13,13,'2007-03-18','2007-03-26','2007-03-30','800.00'),
    (14,14,'2007-03-25','2007-03-25','2007-03-26','380.00'),
    (15,15,'2007-04-02','2007-04-05','2007-04-09','475.00'),
    (16,16,'2007-04-05','2007-04-05','2007-04-11','290.00'),
    (17,17,'2007-04-19','2007-04-19','2007-04-19','810.00'),
    (18,18,'2007-05-01','2007-02-12','2007-02-17','445.00'),
    (19,19,'2007-05-04','2007-05-05','2007-05-07','295.00'),
    (20,20,'2007-06-10','2007-06-10','2007-06-11','475.00'),
    (21,null,'2007-06-10','2007-06-10','2007-06-11','555.00'),
    (22,22,'2007-06-10','2007-06-10','2007-06-11','657.00');
    

---

**Query #1**

    select * from clientes;

| ClienteID | NomeCliente |
| --------- | ----------- |
| 1         | Bob         |
| 2         | Lee         |
| 3         | Jane        |
| 4         | Mary        |
| 5         | Adriaan     |
| 6         | Yeshe       |
| 7         | Charmian    |
| 8         | Tex         |
| 9         | James       |
| 10        | Scott       |
| 11        | Mavis       |
| 12        | Morton      |
| 13        | Monica      |
| 14        | Amos        |
| 15        | Pietro      |
| 16        | Amosa       |
| 17        | Marvin      |
| 18        | Duncan      |
| 19        | Brandon     |
| 20        | Raul        |
| 21        | Jean        |
| 23        | Augusto     |

---
**Query #2**

    select * from pedidos;

| pedidoID | clienteID | data_pedido | data_saida | data_entrega | valor_pedido |
| -------- | --------- | ----------- | ---------- | ------------ | ------------ |
| 1        | 1         | 2006-11-19  | 2006-11-19 | 2006-11-24   | 480.00       |
| 2        | 2         | 2006-11-19  | 2006-11-24 | 2006-11-29   | 295.00       |
| 3        | 3         | 2006-12-20  | 2006-12-20 | 2006-12-25   | 650.00       |
| 4        | 4         | 2007-12-22  | 2007-12-23 | 2007-12-29   | 240.00       |
| 5        | 5         | 2007-01-21  | 2007-01-22 | 2007-01-28   | 600.00       |
| 6        | 6         | 2007-01-21  | 2007-01-22 | 2007-01-27   | 2720.00      |
| 7        | 7         | 2007-01-24  | 2007-01-25 | 2007-01-28   | 260.00       |
| 8        | 8         | 2007-01-27  | 2007-01-29 | 2007-01-31   | 1840.00      |
| 9        | 9         | 2007-02-01  | 2007-02-01 | 2007-02-01   | 780.00       |
| 10       | 10        | 2007-02-01  | 2007-02-01 | 2007-02-01   | 2240.00      |
| 11       | 11        | 2007-02-03  | 2007-02-03 | 2007-02-08   | 1500.00      |
| 12       | 12        | 2007-02-03  | 2007-02-03 | 2007-02-09   | 450.00       |
| 13       | 13        | 2007-03-18  | 2007-03-26 | 2007-03-30   | 800.00       |
| 14       | 14        | 2007-03-25  | 2007-03-25 | 2007-03-26   | 380.00       |
| 15       | 15        | 2007-04-02  | 2007-04-05 | 2007-04-09   | 475.00       |
| 16       | 16        | 2007-04-05  | 2007-04-05 | 2007-04-11   | 290.00       |
| 17       | 17        | 2007-04-19  | 2007-04-19 | 2007-04-19   | 810.00       |
| 18       | 18        | 2007-05-01  | 2007-02-12 | 2007-02-17   | 445.00       |
| 19       | 19        | 2007-05-04  | 2007-05-05 | 2007-05-07   | 295.00       |
| 20       | 20        | 2007-06-10  | 2007-06-10 | 2007-06-11   | 475.00       |
| 21       |           | 2007-06-10  | 2007-06-10 | 2007-06-11   | 555.00       |
| 22       | 22        | 2007-06-10  | 2007-06-10 | 2007-06-11   | 657.00       |


**Query inner join**

    SELECT c.nomecliente, p.valor_pedido from 
    clientes as c inner join pedidos as p
    on c.clienteid = p.clienteid;

| nomecliente | valor_pedido |
| ----------- | ------------ |
| Bob         | 480.00       |
| Lee         | 295.00       |
| Jane        | 650.00       |
| Mary        | 240.00       |
| Adriaan     | 600.00       |
| Yeshe       | 2720.00      |
| Charmian    | 260.00       |
| Tex         | 1840.00      |
| James       | 780.00       |
| Scott       | 2240.00      |
| Mavis       | 1500.00      |
| Morton      | 450.00       |
| Monica      | 800.00       |
| Amos        | 380.00       |
| Pietro      | 475.00       |
| Amosa       | 290.00       |
| Marvin      | 810.00       |
| Duncan      | 445.00       |
| Brandon     | 295.00       |
| Raul        | 475.00       |


**Query left join**

    SELECT c.nomecliente, p.valor_pedido from 
    clientes as c left join pedidos as p
    on c.clienteid = p.clienteid;

| nomecliente | valor_pedido |
| ----------- | ------------ |
| Bob         | 480.00       |
| Lee         | 295.00       |
| Jane        | 650.00       |
| Mary        | 240.00       |
| Adriaan     | 600.00       |
| Yeshe       | 2720.00      |
| Charmian    | 260.00       |
| Tex         | 1840.00      |
| James       | 780.00       |
| Scott       | 2240.00      |
| Mavis       | 1500.00      |
| Morton      | 450.00       |
| Monica      | 800.00       |
| Amos        | 380.00       |
| Pietro      | 475.00       |
| Amosa       | 290.00       |
| Marvin      | 810.00       |
| Duncan      | 445.00       |
| Brandon     | 295.00       |
| Raul        | 475.00       |
| Jean        | null         |
| Augusto     | null         |


**Query right join**

    SELECT c.nomecliente, p.valor_pedido from 
    clientes as c right join pedidos as p
    on c.clienteid = p.clienteid;

| nomecliente | valor_pedido |
| ----------- | ------------ |
| Bob         | 480.00       |
| Lee         | 295.00       |
| Jane        | 650.00       |
| Mary        | 240.00       |
| Adriaan     | 600.00       |
| Yeshe       | 2720.00      |
| Charmian    | 260.00       |
| Tex         | 1840.00      |
| James       | 780.00       |
| Scott       | 2240.00      |
| Mavis       | 1500.00      |
| Morton      | 450.00       |
| Monica      | 800.00       |
| Amos        | 380.00       |
| Pietro      | 475.00       |
| Amosa       | 290.00       |
| Marvin      | 810.00       |
| Duncan      | 445.00       |
| Brandon     | 295.00       |
| Raul        | 475.00       |
| null        | 555.00       |
| null        | 657.00       |


**Query full join**

    SELECT c.nomecliente, p.valor_pedido from 
    clientes as c left join pedidos as p
    on c.clienteid = p.clienteid
    UNION
    SELECT c.nomecliente, p.valor_pedido from 
    clientes as c right join pedidos as p
    on c.clienteid = p.clienteid;

| nomecliente | valor_pedido |
| ----------- | ------------ |
| Bob         | 480.00       |
| Lee         | 295.00       |
| Jane        | 650.00       |
| Mary        | 240.00       |
| Adriaan     | 600.00       |
| Yeshe       | 2720.00      |
| Charmian    | 260.00       |
| Tex         | 1840.00      |
| James       | 780.00       |
| Scott       | 2240.00      |
| Mavis       | 1500.00      |
| Morton      | 450.00       |
| Monica      | 800.00       |
| Amos        | 380.00       |
| Pietro      | 475.00       |
| Amosa       | 290.00       |
| Marvin      | 810.00       |
| Duncan      | 445.00       |
| Brandon     | 295.00       |
| Raul        | 475.00       |
| Jean        | null         |
| Augusto     | null         |
| null        | 555.00       |
| null        | 657.00       |

---