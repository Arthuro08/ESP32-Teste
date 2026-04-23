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

INSERT INTO Clientes (Nome, Email, DataNascimento) VALUES 
('Ana Souza', 'ana.souza@email.com', '1990-05-15'),
('Carlos Mendes', 'carlos.mendes@email.com', '1985-09-22'),
('Fernanda Lima', 'fernanda.lima@email.com', '1995-03-10');

-- Inserindo pedidos de teste
INSERT INTO Pedidos (ClienteID, ValorTotal) VALUES
(1, 250.75),
(2, 500.00),
(1, 150.00),
(3, 320.30);

