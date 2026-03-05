--4
/*Select * from publisher
WHERE name LIKE 'r%';
--5
Select * from publisher
WHERE name LIKE '%n';
--6
Select * from book
WHERE name LIKE '_a%';
--7
Select * from book
WHERE name LIKE 'b__%';
--8
Select * from book
WHERE name LIKE '%i%' OR name LIKE 'i%' OR name LIKE '%i';
--9
Select * from book
WHERE name LIKE 'e%' AND name LIKE '%h';

--10
Select * from book
WHERE author LIKE '%n%' OR author LIKE 'n%' OR author LIKE '%n'
ORDER BY author ASC, price DESC;

--11
Select * from book
WHERE author LIKE '%__e'
ORDER BY name DESC;


--12
Select * from publisher
WHERE address IN ('Puchong', 'Subang');

--13
Select * from book
WHERE price IN (50,100);

--14
Select * from book
WHERE name IN ('Maths','Science','English')
ORDER BY price ASC;*/

--15
/*UPDATE publisher
SET address = 'Serdang'
WHERE name = 'Pearson';

--16
UPDATE book
SET price = 99
WHERE name = 'English';

--17
UPDATE book
SET publisheddate = '3 September 2017'
WHERE name = 'Science';

--18
UPDATE book
SET price = 98, publisheddate = '29 April 2019'
WHERE name = 'English';*/

--19
/*ALTER TABLE book
ALTER COLUMN name varchar(50);
Select * from book;

--20
ALTER TABLE publisher
ADD Telephone integer;
Select * from publisher;*/

--21
/*EXEC sp_rename 'publisher.Telephone', ContactNumber;
Select * from publisher;*/

--22
/*ALTER TABLE publisher
DROP COLUMN ContactNumber;
Select * from publisher;*/


--23
/*DELETE FROM book WHERE name ='Biology' AND author = 'K.Vince';

--24
DELETE FROM book WHERE name ='Maths' AND author = 'J.Wenton';*/


--25
/*CREATE TABLE Customer (
	ID varchar(255),
    Name varchar(255),
);
Select * from Customer;
DROP TABLE Customer;*/

--26
--CREATE DATABASE MyDatabase;
--DROP DATABASE MyDatabase;














































