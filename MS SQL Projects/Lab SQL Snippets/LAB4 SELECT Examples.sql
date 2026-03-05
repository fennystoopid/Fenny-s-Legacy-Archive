--4
Select * from publisher;
--5
Select name, author from book;
--6
Select * from book where author = 'K.Vince';
--7
Select * from book where publisherid = 'P01';
--8
Select * from book where price > 100;
--9
Select * from book where price <= 100;
--10
Select * from book where price BETWEEN 100 AND 200;
--11
Select * from book where price NOT BETWEEN 100 AND 200;
--12
Select * from book where author = 'S.Hanson' AND price = 100;
--13
Select * from book where author = 'J.Wenton' AND price = 30;
--14
Select * from book where author = 'K.Vince' OR price BETWEEN 50 AND 100;
--15
Select * from book where author = 'K.Vince' OR price NOT BETWEEN 50 AND 100;
--16
Select * from publisher
ORDER BY name ASC;
--17
Select * from book
ORDER BY name DESC;
--18
Select * from book where author = 'K.Vince'
ORDER BY name DESC;
--19
Select * from book where author != 'J.Wenton' AND price > 30
ORDER BY price DESC;
--20
Select * from book where name != 'Science'
ORDER BY author ASC, price DESC;
--21
Select * from book where publisherid != 'P01'
ORDER BY price ASC;
--22
Select * from book where author != 'S.Hanson' OR price NOT BETWEEN 90 AND 160
ORDER BY price ASC;







