CREATE DATABASE Esp32_Data
GO
USE Esp32_Data

CREATE TABLE Professor (
    Prontuario int PRIMARY KEY NOT NULL,
    Nome varchar(50) NOT NULL,
);

CREATE TABLE Grade_Professor (
    ID_Grade INT PRIMARY KEY IDENTITY(1,1),
    Prontuario_ID INT NOT NULL,
    DiaSemana varchar(100) NOT NULL,
    HorarioInicio TIME NOT NULL,
    HorarioFim TIME NOT NULL,
    CONSTRAINT FK_Grade_Professor FOREIGN KEY (Prontuario_ID) REFERENCES Professor(Prontuario)
);

CREATE TABLE Chave (
    ID_Chave int PRIMARY KEY NOT NULL,
    Especificação varchar(100) NOT NULL,
    Sala varchar(5) NOT NULL,
);

CREATE TABLE Liberacao (
    ID_Liberacao int PRIMARY KEY IDENTITY(1,1) NOT NULL,
    DataAcesso DATETIME DEFAULT GETDATE() NOT NULL,
    DataLimite date NOT NULL,
    Prontuario_ID int NOT NULL,
    Chave_ID int NOT NULL,
    CONSTRAINT FK_Prontuario FOREIGN KEY (Prontuario_ID) REFERENCES Professor(Prontuario),
    CONSTRAINT FK_Chave FOREIGN KEY (Chave_ID) REFERENCES Chave(ID_Chave),
)

SELECT * FROM Professor;

SELECT * FROM Chave;

SELECT * FROM Liberacao;

INSERT INTO Chave(Sala, Chave) VALUES
(243, 243)

