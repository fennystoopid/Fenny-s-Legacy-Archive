CREATE TABLE supplier(
supplierid nvarchar(50) PRIMARY KEY,
name nvarchar(50),
address nvarchar(50),
);

CREATE TABLE products(
productid nvarchar(50) PRIMARY KEY,
name nvarchar(50),
price decimal(10,2),
quantityinstock integer,
);

CREATE TABLE supplies(
suppliesid nvarchar(50) PRIMARY KEY,
supplierid nvarchar(50) FOREIGN KEY references supplier(supplierid),
productid nvarchar(50) FOREIGN KEY references products(productid),
supplieddate date,
quantitysupplied integer,
);

insert into Supplier
(SupplierID,Name,Address)
values
('S01','ABC Company','Penang'),
('S02','XYZ Company','Johor'),
('S03','HJK Company','Selangor'),
('S04','PQR Company','Selangor');

insert into Products
(ProductID,Name,Price,QuantityInStock)
values
('P01','Keyboard',103.55,60),
('P02','Mouse',30.90,70),
('P03','Monitor',200.00,80),
('P04','Pendrive',40.30,50);

insert into Supplies
(SuppliesID,SupplierID,ProductID,SuppliedDate,QuantitySupplied)
values
('001','S01','P01','11 Jan 17',100),
('002','S01','P02','22 Feb 17',200),
('003','S01','P03',NULL,300),
('004','S02','P03','30 April 17',400);


Select * from supplier;
Select * from products;
Select * from supplies;