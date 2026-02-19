DATABASE BANK;
USE BANK;

 Bank table
CREATE TABLE Bank (
    B_name VARCHAR(100) PRIMARY KEY,
    F_name VARCHAR(100),
    Address VARCHAR(255)
);

Branch table
CREATE TABLE Branch (
    Branch_Code INT PRIMARY KEY,
    B_name VARCHAR(100),
    Branch_Name VARCHAR(100),
    Branch_Address VARCHAR(255),
    Branch_Mobile_No VARCHAR(15),
    FOREIGN KEY (B_name) REFERENCES Bank(B_name)
);

Customer table
CREATE TABLE Customer (
    Mobile_No VARCHAR(15) PRIMARY KEY,
    Name VARCHAR(100),
    Address VARCHAR(255),
    Account_Type ENUM('Saving', 'Current'),
    Amount DECIMAL(10, 2),
    Branch_Code INT,
    FOREIGN KEY (Branch_Code) REFERENCES Branch(Branch_Code)
);

-Employee table
CREATE TABLE Employee (
    Emp_ID INT PRIMARY KEY AUTO_INCREMENT,
    Name VARCHAR(100),
    Mobile_No VARCHAR(15),
    Branch_Code INT,
    FOREIGN KEY (Branch_Code) REFERENCES Branch(Branch_Code)
);

 Loan table
CREATE TABLE Loan (
    Loan_No INT PRIMARY KEY AUTO_INCREMENT,
    Mobile_No VARCHAR(15),
    Amount DECIMAL(10, 2),
    Payment_No INT,
    Payment_Date DATE,
    FOREIGN KEY (Mobile_No) REFERENCES Customer(Mobile_No)
)
