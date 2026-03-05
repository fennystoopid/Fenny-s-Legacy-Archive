CREATE TABLE publisher(
publisherid nvarchar(50) PRIMARY KEY,
name nvarchar(50),
address nvarchar(50),
);

CREATE TABLE book(
bookid nvarchar(50) Not Null,
name nvarchar(50),
author nvarchar(50),
price decimal(10,2),
publisheddate date,
publisherid nvarchar(50) FOREIGN KEY references publisher(publisherid)
Primary Key (bookid)
);

insert into publisher
(PublisherID,Name,Address)
values
('P01','Pearson','Bukit Jalil'),
('P02','Deitel','Puchong'),
('P03','Rainbow','Subang'),
('P04','Machill','Kuala Lumpur');

insert into book
(BookID,Name,Author,Price,PublishedDate,PublisherID)
values
('B01','Maths','J.Wenton',50.60,'10 Jan 2016','P01'),
('B02','Science','S.Hanson',100.00,'12 Feb 2016','P01'),
('B03','English','K.Vince',89.30,'9 March 2016','P02'),
('B04','Biology','K.Vince',150.80,'24 April 2016','P03'),
('B05','Computing','J.Denzin',NULL,NULL,NULL);

Select * from publisher;
Select * from book;