--4
SELECT TOP 2 * FROM publisher;
--5
SELECT TOP 3 * FROM book where price < 130;
--6
SELECT MIN(price) AS LowestPrice
FROM book;
--7
SELECT name,price AS LowestPrice
FROM book
WHERE price = (SELECT MIN(price) FROM book);
--8
SELECT MIN(name) AS explainwhy
FROM book;
--9
SELECT MAX(price) AS HighestPrice
FROM book; 
--10
SELECT name,price AS HighestPrice
FROM book
WHERE price = (SELECT MAX(price) FROM book);
--11
SELECT MAX(name) AS Explainwhy2
FROM book;
--12
SELECT SUM(price) AS TotalPrice
FROM book;
--13
SELECT AVG(price) AS AveragePrice
FROM book;
--14
SELECT name,price AS HigherPriceThanAvgPrice
FROM book
WHERE price > (SELECT AVG(price) FROM book);
--15
SELECT COUNT(*) AS TotalBooks
FROM book;
--16
SELECT COUNT(*) AS VinceClassics
FROM book
WHERE author = 'K.Vince';
--17
SELECT COUNT(*) AS BooksCostMoreThanRM60
FROM book
WHERE price > 60;
--18
SELECT COUNT(*) AS BooksCostMoreThanAVG
FROM book
WHERE price > (SELECT AVG(price) FROM book);
--19
SELECT author AS Author, COUNT(*) AS TotalBooksByAuthor
FROM book
GROUP BY author
ORDER BY COUNT(*) ASC;
--20
SELECT PublisherID, COUNT(*) AS TotalBooksByPublisher
FROM book
GROUP BY PublisherID
ORDER BY COUNT(*) ASC;
--21
SELECT author,SUM(price) AS BookPriceByAuthor
FROM book
GROUP BY author
ORDER BY SUM(price) ASC;
--22
SELECT PublisherID,SUM(price) AS BookPriceByPublisher
FROM book
GROUP BY PublisherID
ORDER BY SUM(price) ASC;

--23
--UPDATE book SET price = price + 10 where name = 'Maths'; 
--24
--UPDATE book SET price = price - 20 where name = 'Biology'; 
--25
--UPDATE book SET price = price + price * 0.10 where name = 'English'; 
--26
--UPDATE book SET price = price/2 where name = 'Science'; 