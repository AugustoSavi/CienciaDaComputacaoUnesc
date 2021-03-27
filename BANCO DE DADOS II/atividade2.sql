CREATE DATABASE `petshop`;

USE `petshop`;

CREATE TABLE `clinicas` (
  `nclin` int PRIMARY KEY AUTO_INCREMENT,
  `andar` numeric(3) NOT NULL,
  `capacidade` smallint
);

CREATE TABLE `veterinarios` (
  `codv` int PRIMARY KEY AUTO_INCREMENT,
  `nome` varchar(40) NOT NULL,
  `idade` smallint NOT NULL,
  `especialidade` char(20),
  `CPF` numeric(11) UNIQUE,
  `cidade` varchar(30),
  `nclin` int
);

CREATE TABLE `pet` (
  `codp` int PRIMARY KEY AUTO_INCREMENT,
  `nome` varchar(40) NOT NULL,
  `idade` smallint NOT NULL,
  `cidade` char(30),
  `CPFD` numeric(11) UNIQUE,
  `doenca` varchar(40) NOT NULL,
  `animal` char(30) NOT NULL,
  `raca` char(30)
);

CREATE TABLE `funcionarios` (
  `codf` int PRIMARY KEY AUTO_INCREMENT,
  `nome` varchar(40) NOT NULL,
  `idade` smallint,
  `CPF` numeric(11) UNIQUE,
  `cidade` varchar(30),
  `salario` numeric(10),
  `cargo` varchar(20)
);

CREATE TABLE `consultas` (
  `codv` int,
  `codp` int,
  `data` date,
  `hora` time
);

ALTER TABLE `veterinarios` ADD FOREIGN KEY (`nclin`) REFERENCES `clinicas` (`nclin`);

ALTER TABLE `consultas` ADD FOREIGN KEY (`codv`) REFERENCES `veterinarios` (`codv`);

ALTER TABLE `consultas` ADD FOREIGN KEY (`codp`) REFERENCES `pet` (`codp`);

ALTER TABLE `funcionarios` ADD  `nclin` int;

CREATE INDEX idx_CPF ON `veterinarios`(`CPF`);


CREATE INDEX idx_DOENCA ON `pet`(`doenca`);


SHOW COLUMNS FROM clinicas;

SHOW COLUMNS FROM veterinarios;
SHOW INDEXES FROM veterinarios;

SHOW COLUMNS FROM pet;
SHOW INDEXES FROM pet;

SHOW COLUMNS FROM funcionarios;

SHOW COLUMNS FROM consultas;
