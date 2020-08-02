-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`direcao`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`direcao` (
  `codigo_direcao` INT NOT NULL,
  `conexao_banco_origem` VARCHAR(45) NULL,
  `usuario_origem` VARCHAR(45) NULL,
  `senha_origem` VARCHAR(45) NULL,
  `conexao_banco_destino` VARCHAR(45) NULL,
  `usuario_destino` VARCHAR(45) NULL,
  `senha_destino` VARCHAR(45) NULL,
  `habilitado` VARCHAR(45) NULL,
  PRIMARY KEY (`codigo_direcao`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`log_repliador_tabelas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`log_repliador_tabelas` (
  `codigo_log_repliador_tabelas` INT NOT NULL,
  `codigo_execucao` INT NULL,
  `data_inicial` DATE NULL,
  `data_final` DATE NULL,
  `linhas` INT NULL,
  `mensagem` VARCHAR(45) NULL,
  `sucesso` TINYINT NULL,
  `direcao_codigo_direcao` INT NOT NULL,
  PRIMARY KEY (`codigo_log_repliador_tabelas`),
  INDEX `fk_log_repliador_tabelas_direcao_idx` (`direcao_codigo_direcao` ASC),
  CONSTRAINT `fk_log_repliador_tabelas_direcao`
    FOREIGN KEY (`direcao_codigo_direcao`)
    REFERENCES `mydb`.`direcao` (`codigo_direcao`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`log_replicacao`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`log_replicacao` (
  `codigo_log_replicacao` INT NOT NULL,
  `data_inicial` DATE NULL,
  `data_final` DATE NULL,
  `banco_origem` VARCHAR(45) NULL,
  `banco_destino` VARCHAR(45) NULL,
  `sucesso` TINYINT NULL,
  `log_repliador_tabelas_codigo_log_repliador_tabelas` INT NOT NULL,
  PRIMARY KEY (`codigo_log_replicacao`),
  INDEX `fk_log_replicacao_log_repliador_tabelas1_idx` (`log_repliador_tabelas_codigo_log_repliador_tabelas` ASC) VISIBLE,
  CONSTRAINT `fk_log_replicacao_log_repliador_tabelas1`
    FOREIGN KEY (`log_repliador_tabelas_codigo_log_repliador_tabelas`)
    REFERENCES `mydb`.`log_repliador_tabelas` (`codigo_log_repliador_tabelas`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`processo`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`processo` (
  `codigo_processo` INT NOT NULL,
  `processo` VARCHAR(45) NULL,
  `descricao` VARCHAR(45) NULL,
  `habilitado` TINYINT NULL,
  `direcao_codigo_direcao` INT NOT NULL,
  PRIMARY KEY (`codigo_processo`),
  INDEX `fk_processo_direcao1_idx` (`direcao_codigo_direcao` ASC) VISIBLE,
  CONSTRAINT `fk_processo_direcao1`
    FOREIGN KEY (`direcao_codigo_direcao`)
    REFERENCES `mydb`.`direcao` (`codigo_direcao`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`sequencia_tabelas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`sequencia_tabelas` (
  `codigo_sequencia_tabelas` INT NOT NULL,
  `tabela_origem` VARCHAR(45) NULL,
  `tabela_destino` VARCHAR(45) NULL,
  `ordem` INT NULL,
  `habilitado` VARCHAR(45) NULL,
  `sequencia_tabelascol` VARCHAR(45) NULL,
  `processo_codigo_processo` INT NOT NULL,
  PRIMARY KEY (`codigo_sequencia_tabelas`),
  INDEX `fk_sequencia_tabelas_processo1_idx` (`processo_codigo_processo` ASC) VISIBLE,
  CONSTRAINT `fk_sequencia_tabelas_processo1`
    FOREIGN KEY (`processo_codigo_processo`)
    REFERENCES `mydb`.`processo` (`codigo_processo`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;

