---4
SELECT *
FROM Book
INNER JOIN Publisher
ON Book.PublisherID = Publisher.PublisherID;

---5
SELECT *
FROM Publisher
LEFT JOIN Book
ON Publisher.PublisherID = Book.PublisherID
ORDER BY Publisher.Name;

---6
SELECT *
FROM Book
RIGHT JOIN Publisher
ON Book.PublisherID = Publisher.PublisherID
ORDER BY Book.Name;

---7
SELECT *
FROM Publisher
FULL OUTER JOIN Book
ON Book.PublisherID = Publisher.PublisherID
---WHERE
ORDER BY Book.Name;

---8
SELECT PublisherID, Name FROM Publisher
UNION ---UNION ALL (to allow duplicates)
SELECT BookID, Name FROM Book;

---9
SELECT *
FROM Book
INNER JOIN Publisher
ON Book.PublisherID = Publisher.PublisherID
WHERE Publisher.Name = 'Deitel'
ORDER BY Book.Name;

---10
SELECT *
FROM Book
INNER JOIN Publisher
ON Book.PublisherID = Publisher.PublisherID
WHERE Publisher.Name = 'Pearson' AND Book.Author = 'S.Hanson'
ORDER BY Book.Name;

--11
SELECT *
FROM Book
INNER JOIN Publisher
ON Book.PublisherID = Publisher.PublisherID
WHERE Publisher.Name = 'Pearson' AND Book.Price BETWEEN 30 AND 70 AND Book.Author = 'J.Wenton'
ORDER BY Book.Name;

--12
SELECT * 
FROM Book
INNER JOIN Publisher
ON Book.PublisherID = Publisher.PublisherID
WHERE Publisher.Address = 'Bukit Jalil'
ORDER BY Book.Name;

--13
SELECT * 
FROM Publisher
INNER JOIN Book
ON Publisher.PublisherID = Book.PublisherID
WHERE Book.PublishedDate BETWEEN '1 January 2016' AND '1 March 2016'
ORDER BY Book.Name;

--14
SELECT * 
FROM Book
FULL JOIN Publisher
ON Book.PublisherID = Publisher.PublisherID
WHERE NOT Book.Author = 'K.Vince'
ORDER BY Book.Name;

--15
SELECT * 
FROM Book
FULL JOIN Publisher
ON Book.PublisherID = Publisher.PublisherID
WHERE Book.PublishedDate > '1 January 2016'
ORDER BY Book.Name;

