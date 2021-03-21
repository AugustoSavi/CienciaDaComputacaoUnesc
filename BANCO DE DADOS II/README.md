# Acesse https://www.db-fiddle.com/ e cole o conteudo de sqltodbfiddle

## script andes.sql 

---

**Query #1**

    SHOW TABLES from `andes`;

| Tables_in_andes       |
| --------------------- |
| categorias            |
| clientes              |
| departamentos         |
| estados               |
| fornecedores          |
| fornecedores_contatos |
| franquias             |
| pedidos               |
| pedidos_item          |
| pedidos_status        |
| produtos              |
| transportadoras       |

---
**Query #2**

    SHOW COLUMNS FROM `categorias`;

| Field         | Type        | Null | Key | Default | Extra |
| ------------- | ----------- | ---- | --- | ------- | ----- |
| CategoriaID   | int(3)      | YES  |     |         |       |
| NomeCategoria | varchar(50) | YES  |     |         |       |

---
**Query #3**

    SHOW COLUMNS FROM `clientes`;

| Field       | Type        | Null | Key | Default | Extra          |
| ----------- | ----------- | ---- | --- | ------- | -------------- |
| ClienteID   | int(8)      | NO   | PRI |         | auto_increment |
| NomeCliente | varchar(50) | YES  |     |         |                |
| Endereco    | varchar(50) | YES  |     |         |                |
| Cidade      | varchar(50) | YES  |     |         |                |
| Estado      | tinyint(3)  | YES  |     |         |                |
| CEP         | varchar(10) | YES  |     |         |                |
| Email       | varchar(50) | YES  |     |         |                |
| Usuario     | varchar(10) | YES  |     |         |                |
| Senha       | varchar(10) | YES  |     |         |                |
| Nivel       | varchar(10) | YES  |     |         |                |

---
**Query #4**

    SHOW COLUMNS FROM `departamentos`;

| Field            | Type        | Null | Key | Default | Extra          |
| ---------------- | ----------- | ---- | --- | ------- | -------------- |
| departamentoID   | int(11)     | NO   | PRI |         | auto_increment |
| nomedepartamento | varchar(50) | YES  |     |         |                |

---
**Query #5**

    SHOW COLUMNS FROM `estados`;

| Field     | Type                | Null | Key | Default | Extra          |
| --------- | ------------------- | ---- | --- | ------- | -------------- |
| codestado | tinyint(3) unsigned | NO   | PRI |         | auto_increment |
| nome      | char(20)            | YES  |     | 0       |                |
| sigla     | char(2)             | YES  |     |         |                |

---
**Query #6**

    SHOW COLUMNS FROM `fornecedores`;

| Field          | Type        | Null | Key | Default | Extra |
| -------------- | ----------- | ---- | --- | ------- | ----- |
| FornecedorID   | int(8)      | YES  |     |         |       |
| NomeFornecedor | varchar(50) | YES  |     |         |       |
| Endereco       | varchar(50) | YES  |     |         |       |
| Cidade         | varchar(50) | YES  |     |         |       |
| Estado         | varchar(2)  | YES  |     |         |       |
| Telefone       | varchar(14) | YES  |     |         |       |

---
**Query #7**

    SHOW COLUMNS FROM `fornecedores_contatos`;

| Field          | Type        | Null | Key | Default | Extra          |
| -------------- | ----------- | ---- | --- | ------- | -------------- |
| contatoID      | int(11)     | NO   | PRI |         | auto_increment |
| fornecedorID   | int(11)     | YES  |     |         |                |
| departamentoID | int(11)     | YES  |     |         |                |
| nome           | varchar(50) | YES  |     |         |                |
| telefone       | varchar(15) | YES  |     |         |                |
| email          | varchar(50) | YES  |     |         |                |

---
**Query #8**

    SHOW COLUMNS FROM `franquias`;

| Field        | Type          | Null | Key | Default | Extra          |
| ------------ | ------------- | ---- | --- | ------- | -------------- |
| franquiaID   | int(11)       | NO   | PRI |         | auto_increment |
| NomeGerente  | varchar(50)   | NO   |     |         |                |
| Endereco     | varchar(50)   | NO   |     |         |                |
| Cidade       | varchar(50)   | NO   |     |         |                |
| EstadoID     | tinyint(1)    | NO   |     |         |                |
| Telefone     | varchar(15)   | YES  |     |         |                |
| DataAbertura | date          | NO   |     |         |                |
| Faturamento  | decimal(10,2) | NO   |     |         |                |
| Mapa         | varchar(50)   | YES  |     |         |                |

---
**Query #9**

    SHOW COLUMNS FROM `pedidos`;

| Field            | Type          | Null | Key | Default | Extra          |
| ---------------- | ------------- | ---- | --- | ------- | -------------- |
| pedidoID         | int(11)       | NO   | PRI |         | auto_increment |
| clienteID        | int(11)       | NO   |     |         |                |
| transportadoraID | int(11)       | YES  |     |         |                |
| data_pedido      | date          | NO   |     |         |                |
| data_saida       | date          | YES  |     |         |                |
| data_entrega     | date          | YES  |     |         |                |
| status_pedido    | tinyint(3)    | NO   |     |         |                |
| valor_pedido     | decimal(10,2) | NO   |     |         |                |
| conhecimento     | varchar(20)   | YES  |     |         |                |

---
**Query #10**

    SHOW COLUMNS FROM `pedidos_item`;

| Field         | Type          | Null | Key | Default | Extra |
| ------------- | ------------- | ---- | --- | ------- | ----- |
| pedidoID      | int(11)       | YES  |     |         |       |
| produtoID     | int(11)       | YES  |     |         |       |
| precounitario | decimal(10,2) | YES  |     |         |       |
| quantidade    | smallint(5)   | YES  |     |         |       |

---
**Query #11**

    SHOW COLUMNS FROM `pedidos_status`;

| Field      | Type        | Null | Key | Default | Extra          |
| ---------- | ----------- | ---- | --- | ------- | -------------- |
| statusID   | int(11)     | NO   | PRI |         | auto_increment |
| nomestatus | varchar(50) | NO   |     |         |                |

---
**Query #12**

    SHOW COLUMNS FROM `produtos`;

| Field             | Type          | Null | Key | Default | Extra          |
| ----------------- | ------------- | ---- | --- | ------- | -------------- |
| ProdutoID         | int(11)       | NO   | PRI |         | auto_increment |
| NomeProduto       | varchar(50)   | YES  |     |         |                |
| Descricao         | longtext      | YES  |     |         |                |
| CodigoBarra       | varchar(15)   | YES  |     |         |                |
| TempoEntrega      | tinyint(3)    | YES  |     |         |                |
| PrecoRevenda      | decimal(10,2) | YES  |     |         |                |
| PrecoUnitario     | decimal(10,2) | YES  |     |         |                |
| UnidadesEmEstoque | mediumint(4)  | YES  |     |         |                |
| ImagemGrande      | varchar(100)  | YES  |     |         |                |
| ImagemPequena     | varchar(100)  | YES  |     |         |                |
| Descontinuado     | tinyint(1)    | YES  |     | 0       |                |
| FornecedorID      | tinyint(3)    | YES  |     |         |                |
| CategoriaID       | tinyint(3)    | YES  |     |         |                |

---
**Query #13**

    SHOW COLUMNS FROM `transportadoras`;

| Field              | Type        | Null | Key | Default | Extra          |
| ------------------ | ----------- | ---- | --- | ------- | -------------- |
| transportadoraID   | int(11)     | NO   | PRI |         | auto_increment |
| nometransportadora | varchar(50) | YES  |     |         |                |
| endereco           | varchar(50) | YES  |     |         |                |
| telefone           | varchar(50) | YES  |     |         |                |
| cidade             | varchar(50) | YES  |     |         |                |
| estadoID           | tinyint(3)  | YES  |     |         |                |
| cep                | varchar(10) | YES  |     |         |                |
| cnpj               | varchar(19) | YES  |     |         |                |

---
