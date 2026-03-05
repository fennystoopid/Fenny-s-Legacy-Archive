---4
insert into book
(BookID,Name,Author,Price,PublishedDate,PublisherID)
values
('B06','Computing','J.Denzin',NULL,NULL,NULL);

----5
DELETE FROM publisher where name = 'Deitel';

Select * from publisher;

---6
DELETE FROM publisher where name = 'MacHill';

Select * from publisher;

---7
DELETE FROM book;