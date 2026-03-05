--4
Select * From book where PublisherID = 
(Select PublisherID from Publisher where name = 'Deitel');
--5
Select * from book where publisherid =
(Select PublisherID from publisher where name = 'Pearson')
ORDER BY name DESC;
--6
Select * from book where author = 'S.Hanson' and PublisherID = 
(Select PublisherID from Publisher where name = 'Pearson');
--7
Select * from book where price > 80 and PublisherID = 
(Select PublisherID from publisher where name = 'Pearson');
--8
Select * from book where price BETWEEN 30 and 70 and author = 'J.Wenton' and
PublisherID =
(Select PublisherID from Publisher where name = 'Pearson');
--9
Select * from book where publisheddate > '1 March 2016' and PublisherID =
(Select PublisherID from Publisher where name = 'Deitel');
--10
Select COUNT(*) AS NumOfBook 
from book 
where PublisherID =
(Select PublisherID from Publisher where name = 'Deitel');
--11
Select SUM(price) AS TotalPrice
From book
where PublisherID = 
(Select PublisherID from publisher where name = 'Pearson');
--12
Select AVG(price) AS AvgPrice
From book
where PublisherID = 
(Select PublisherID from publisher where name = 'Pearson');
--13
Select * From book where publisherID = 
(Select PublisherID from publisher where address = 'Bukit Jalil')
ORDER BY name ASC;
--14
Select * From book where publisherID = 
(Select PublisherID from publisher where address = 'Puchong');
--15
Select * From book where publisheddate > '30 January 2016' and publisherID =
(Select PublisherID from publisher where name = 'Pearson');
--16
Select * From publisher where publisherID IN
(Select PublisherID from book WHERE author = 'K.Vince');
--17
UPDATE publisher 
SET address = 'Shah Alam' 
where publisherID =
(Select PublisherID from book where name = 'Biology'); 
--18
Select * 
From publisher
Where NOT EXISTS --or NOT IN
(Select publisherID From 
book WHERE book.publisherID = publisher.publisherID);
--19
Select PublisherID,COUNT(name) AS NumOfBooks
From book 
GROUP BY PublisherID
HAVING COUNT(name) > 1;

Select * From publisher;
Select * From book;