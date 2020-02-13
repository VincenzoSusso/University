-- Database
CREATE DATABASE Exercise;

USE Exercise;

-- Tables
CREATE TABLE Employees (
    Code SMALLINT PRIMARY KEY,
    Name VARCHAR(256),
    Age SMALLINT NOT NULL,
    Salary SMALLINT NOT NULL,
    
    CHECK(Age >= 18 AND Age <= 100)
);

CREATE TABLE Supervision (
    Employee SMALLINT PRIMARY KEY REFERENCES Employees(Code),
    Head SMALLINT NOT NULL
);

-- Insertion
INSERT INTO Employees VALUES (101, "Mario Rossi", 34, 4000);
INSERT INTO Employees VALUES (103, "Mario Bianchi", 23, 3500);
INSERT INTO Employees VALUES (104, "Luigi Neri", 38, 6100);
INSERT INTO Employees VALUES (105, "Nico Bini", 44, 3800);
INSERT INTO Employees VALUES (210, "Marco Celli", 49, 6000);
INSERT INTO Employees VALUES (231, "Siro Bisi",50, 6000);
INSERT INTO Employees VALUES (252, "Nico Bini", 44, 7000);
INSERT INTO Employees VALUES (301, "Sergio Rossi", 34, 7000);
INSERT INTO Employees VALUES (375, "Mario Rossi", 50, 6500);

INSERT INTO Supervision VALUES (101, 210);
INSERT INTO Supervision VALUES (103, 210);
INSERT INTO Supervision VALUES (104, 210);
INSERT INTO Supervision VALUES (105, 231);
INSERT INTO Supervision VALUES (210, 301);
INSERT INTO Supervision VALUES (231, 301);
INSERT INTO Supervision VALUES (252, 375);

-- Queries
-- 1) Find code, name, surname, age and salary of the employees earning more than 4000 Euros
SELECT * FROM Employees WHERE Salary > 4000;

-- 2) Find code, name, surname and age of the employees earning more than 4000 Euros
SELECT Code, Name, Age FROM Employees WHERE Salary > 4000;

-- 3) Find the codes of the heads of the employees which earn more than 4000 Euros
SELECT DISTINCT head FROM Supervision JOIN Employees ON head = code WHERE Salary > 4000;

-- 4) Find name, surname and salary of the heads of the employees which earn more than 4000 Euros
SELECT DISTINCT chief.Name, chief.Salary FROM Employees worker JOIN Supervision ON worker.Code = Employee JOIN Employees chief ON Head = chief.Code WHERE worker.Salary > 4000;

-- 5) Find the employees which earn more than their respective heads. Show: code, name, surname and salary of such emplyees and their heads
SELECT DISTINCT worker.Code as WorkerCode, worker.name as WorkerName, worker.salary as WorkerSalary, chief.code as ChiefCode FROM Employees worker JOIN Supervision ON worker.Code = Employee JOIN Employees chief ON Head = chief.Code WHERE worker.Salary > chief.Salary;

-- 6) Find code, name and surname of the heads whose employees all earn more than 4000 euros
SELECT DISTINCT code, name FROM Supervision JOIN Employees ON head = code WHERE code NOT IN (SELECT head FROM Employees JOIN Supervision on code = employee WHERE salary <= 4000);