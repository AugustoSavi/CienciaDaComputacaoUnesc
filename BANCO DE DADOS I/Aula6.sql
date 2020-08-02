CREATE TABLE IF NOT EXISTS Login(
  idLogin INT NOT NULL AUTO_INCREMENT,
  login VARCHAR(45) NOT NULL,
  senha VARCHAR(45) NOT NULL,
  PRIMARY KEY (idLogin))




CREATE TABLE IF NOT EXISTS Usuario(
  idUsuario INT NOT NULL,
  Nome VARCHAR(45) NOT NULL,
  Data_Nascimeto VARCHAR(45) NOT NULL,
  Cidade VARCHAR(45) NOT NULL,
  Bairro VARCHAR(45) NOT NULL,
  Rua VARCHAR(45) NOT NULL,
  FKLogin_idLogin INT NOT NULL,
  PRIMARY KEY (idUsuario),
  INDEX fk_Usuario_Login_idx (FKLogin_idLogin),
  CONSTRAINT fk_Usuario_Login
  FOREIGN KEY (FKLogin_idLogin)
  REFERENCES Login (idLogin))
  
  
INSERT INTO login (login,senha)
VALUES ("augusto","aug!@#");

INSERT INTO usuario (Nome,Data_Nascimeto, Cidade,Bairro,Rua,FKLogin_idLogin)
VALUES ("Augusto Savi","1999-11-02","Criciuma","Pinheirinho","Bortolo Pavan",1);

INSERT INTO login (login,senha)
VALUES ("hassan","hass123");

INSERT INTO usuario (Nome,Data_Nascimeto, Cidade,Bairro,Rua,FKLogin_idLogin)
VALUES ("Hassan souki","1998-10-18","Criciuma","Centro","centenario",2);

SELECT * FROM Login WHERE  = 'augusto' and senha = "aug!@#";
