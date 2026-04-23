CREATE TABLE Clientes (
    ID INT IDENTITY(1,1) PRIMARY KEY,
    Nome NVARCHAR(100) NOT NULL,
    Email NVARCHAR(100) UNIQUE NOT NULL,
    DataNascimento DATE
);

CREATE TABLE HistoricoClientes (
    ID INT IDENTITY(1,1) PRIMARY KEY,
    ClienteID INT,
    NomeAntigo NVARCHAR(100),
    NomeNovo NVARCHAR(100),
    DataModificacao DATETIME,
    FOREIGN KEY (ClienteID) REFERENCES Clientes(ID)
);

CREATE TABLE Pedidos (
    ID INT IDENTITY(1,1) PRIMARY KEY,
    ClienteID INT,
    DataPedido DATETIME DEFAULT GETDATE(),
    ValorTotal DECIMAL(10,2),
    FOREIGN KEY (ClienteID) REFERENCES Clientes(ID)
);
