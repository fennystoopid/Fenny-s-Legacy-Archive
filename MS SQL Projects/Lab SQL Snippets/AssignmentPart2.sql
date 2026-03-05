---ONLY USE THIS IF YOU FUCKED UP THE TABLE
DROP TABLE borrowing;
DROP TABLE items;
DROP TABLE loan;
DROP TABLE members;
DROP TABLE room;
---USE THE ABOVE IF YOU FUCKED UP THE TABLE

CREATE TABLE members(
memberid nvarchar(50) NOT NULL,
firstname nvarchar(50),
lastname nvarchar(50),
gender nvarchar(50),
age integer,
contactnum nvarchar(50),
neighbourhood nvarchar(50),
PRIMARY KEY (memberid)
);

CREATE TABLE items(
itemid nvarchar(50) NOT NULL,
itemname nvarchar(50),
itemcreator nvarchar(50),
genre nvarchar(50),
descp nvarchar(200),
price decimal(10,2),
quantityinstock integer,
PRIMARY KEY (itemid)
);

CREATE TABLE borrowing(
borrowid nvarchar(50) NOT NULL,
itemid nvarchar(50) NOT NULL,
memberid nvarchar(50) NOT NULL,
timeofborrow date,
duedate date,
loandur nvarchar(20),
returndate date,
fine decimal(10,2),
PRIMARY KEY (borrowid),
FOREIGN KEY (itemid) REFERENCES items(itemid),
FOREIGN KEY (memberid) REFERENCES members(memberid)
);

CREATE TABLE room(
roomid nvarchar(50) PRIMARY KEY,
roomtype nvarchar(1),
reservationdate date,
memberid nvarchar(50) NOT NULL,
FOREIGN KEY (memberid) REFERENCES members(memberid)
);

CREATE TABLE loan(
loanid nvarchar(50),
borrowid nvarchar(50) NOT NULL ,
loandur nvarchar(20),
PRIMARY KEY (loanid),
FOREIGN KEY (borrowid) REFERENCES borrowing(borrowid)
);

insert into members
(MemberID,FirstName,LastName,Gender,Age,ContactNum,Neighbourhood)
values
('TP001','Ter','Stegen','Male','24','601224588','Bukit Bintang'),
('TP002','Alif','Satar','Male','26','601245897','Taman Tun Dr.Ismail (TTDI)'),
('TP003','Muhammad','Alif','Male','19','601354875','Mont Kiara'),
('TP004','Aleeya',NULL,'Female','18','601239781','Bangsar'),
('TP005','Muhammad','Afi','Male','20','601879365','Sri Hartamas'),
('TP006','Shafiq','Kyle','Male','32','601796324','Kepong'),
('TP007','Raif','Izudin','Male','22','604783544','Cheras'),
('TP008','Khai',NULL,'Male','19','601478935','Setapak'),
('TP009','Hannah','Delisha','Female','32','601978842','Wangsa Maju'),
('TP010','Hael','Hussaini','Male','26','601233449','Ampang'),
('TP011','Zhul','Arrifin','Male','40','601257833','Desa ParkCity'),
('TP012','Puteri','Agnes','Female','19','601544836','Sentul'),
('TP013','Lewis','Hamilton','Male','32','601699333','Segambut'),
('TP014','Ayrton','Senna','Female','24','601666872','Brickfields (Little India)'),
('TP015','Maeve','Wiley','Female','22','601999753','Old Klang Road'),
('TP016','Joe','Goldberg','Male','26','601234567','Taman Desa'),
('TP017','Hannah','Dayana','Female','18','601289436','Bukit Jalil'),
('TP018','Carlos','Sainz','Male','25','601233201','Pudu'),
('TP019','Sebastian','Vettel','Male','25','601233750','Salak South'),
('TP020','Zulhilmi',NULL,'Male','21','601118024','Taman Maluri'),
('TP021','Gan','Ching','Male','24','601135780','Sungai Besi'),
('TP022','Hoi','Mi','Male','18','601128945','Kampung Baru'),
('TP023','Chong','Xuan','Male','25','601189937','Seputeh'),
('TP024','Zhui','Hen','Male','40','601545454','Jalan Kuchai Lama'),
('TP025','Chloe','Chen','Female','24','601987005','KLCC (Kuala Lumpur City Centre)'),
('TP026','Damon','Salvatore','Male','25','601587335','Taman Connaught'),
('TP027','Elena','Gilbert','Female','18','601335204','OUG (Overseas Union Garden)'),
('TP028','Edwerd','Cullen','Male','28','601753126','Taman Melawati'),
('TP029','Alice','Cullen','Female','28','601893201','Gombak'),
('TP030','Bella','Swan','Female','26','602587419','Bandar Sri Permaisur');

insert into items
(ItemID,ItemName,ItemCreator,Genre,Price,Descp,QuantityinStock)
values
('101','It Ends With Us','Colleen Hoover','Romance',63.97,'A challenge occurred in between when Lily fell in love with Ryle.',5),
('102','It Starts With Us','Colleen Hoover','Romance',66.51,'When two people intertwined again at the street hoping they can rekindle things.',8),
('103','Monopoly','Hasbro','Strategy Game',24.55,'Multiplayer economics themed board game.',4),
('104','A Man Called Ove','Fredick BackMan','Contemporary Fiction',132.63,'Provides the reader a window into a particular human experience.',4),
('105','The Dark Tower','Stephen King','Dark Fantasy',137.36,'Features morally gray characters and includes a jist of elements of horror.',8),
('106','It','Stephen King','Horror',125.20,'Experiences of 7 children as they are terrorized by an evil entity.',7),
('107','Vogue''s''Magazine','Arthur Baldwin Turnure','Fashion and Lifestyle',135.87,'Monthly fashion and lifestyle magazine that covers style news.',3),
('108','Ella Enchanted','Gail Carson','Fairy Tales',76.29,'It is a tale about a fairy godmother, a glass slipper and a coach.',2),
('109','Babel','R.F Kuang','Historical Fantasy',49.87,'Grapples with students revolutions, colonial resistance and the use of language.',4),
('110','The Running Grave','J.K. Rowling','Crime Fiction',20.79,'Cormoran and Robin must rescue a man seized in the trap by a harmful group.',2),
('111','The Ink Black Heart','J.K. Rowling','Crime Fiction',44.01,'An investigation regarding how their friend was murdered mysteriously with no trace left.',9),
('112','Gone Girl','Gillian Carson','Thriller',136.64,'Sudden disappearance of his wife on their 5th weeding anniversary.',9),
('113','Lock Every Door','Riley Sager','Thriller',99.09,'A lady who thought she saw her long lost sister in the building just to go missing the very next day.',9),
('114','The Quiet Girl','S. F. Kosa','Thriller',25.84,'The sudden disappearance of a wife who has held many secrets and kept them away from his husband who is now in a mission to find out who she really is.',1),
('115','Spider-Man','Kurt Busiek','Action Comic',47.32,'Where Kraven the hunter will go around killing every animal known to man kind as he is known to be the best hunter.',8),
('116','The Husbands Secret','Liane Moriarty','Womens Fiction',100.92,'Where three womens will collide and they were the past lovers to one of the womes husband.',2),
('117','The Game of Life','Milton Bradley','Life Simulation',130.39,'Simulates a person''s'' travels through their life, from early adulthood to retirement.',4),
('118','Steve Jobs','Walter Isaacson','Biography',99.85,'A back story of how Steve Jobs became the person who he was and hardships he had to face.',6),
('119','The Notebook','Nick Cassavates','Romance',75.75,'A story of a man with unconditional love for his wife despite her memory being taken away by dementia.',3),
('120','Benjamin Franklin','Walter Isaacson','Biography',61.49,'Talks about the work details Benjamin Franklin did.',8),
('121','The Barefoot Contessa Cookbook','Ina Garten','Cookbook',52.70,'Receipes to many finger-licking dishes.',2),
('122','Life of Pi','Yann Martel','Adventure',53.19,'Survival tale.',5),
('123','The Silent Patient','Alex Michaelides','Thriller',29.91,'A psychological thriller about a woman''s'' act of violence against her husband and the therapist who becomes obsessed with uncovering her motive.',3),
('124','The Maidens','Alex Michaelides','Thriller',108.59,'A dark academia thriller that follows a therapist who becomes embroiled in a murder investigation involving a secret society at Cambridge University.',7),
('125','The Night Circus','Erin Morgenstern','Fantasy',101.54,'A magical competition between two young illusionists unfolds within a mysterious circus that appears only at night.',8),
('126','The Starless Sea','Erin Morgenstern','Fantasy',20.00,'A love letter to stories, this novel follows a young man who discovers a hidden underground library and embarks on a journey through a fantastical world.',4),
('127','The Alchemist','Paulo Coelho','Adventure',70.49,'A young shepherd named Santiago dreams of discovering treasure in Egypt, leading him on a journey of self-discovery and personal legend.',2),
('128','Brida','Paulo Coelho','Adventure',55.80,'A young woman embarks on a journey to find her true self, exploring love, magic, and the quest for knowledge.',6),
('129','The Giver','Lois Lowry','Dystopian',60.99,'In a seemingly perfect society, a young boy named Jonas discovers the dark secrets behind his community''s'' facade of sameness.',4),
('130','Titanic','James Cameron','Melodrama',49.99,'Epic romantic disaster film.',8);

insert into borrowing
(BorrowID,ItemID,MemberID,TimeOfBorrow,DueDate,LoanDur,ReturnDate,Fine)
values
('BOR1','101','TP001','2024-01-01','2024-02-01','1 Month','2024-02-01',NULL),
('BOR2','102','TP002','2024-01-03','2024-02-03','2 Month','2024-02-03',1.00),
('BOR3','103','TP003','2024-01-03','2024-02-04','3 Month','2024-02-04',NULL),
('BOR4','104','TP004','2024-01-03','2024-03-03','2 Month','2024-03-03',5.00),
('BOR5','105','TP005','2024-01-05','2024-05-05','4 Month','2024-05-05',NULL),
('BOR6','106','TP006','2024-01-14','2024-04-14','3 Month','2024-04-14',NULL),
('BOR7','107','TP007','2024-01-20','2024-02-20','1 Month','2024-02-20',NULL),
('BOR8','108','TP008','2024-01-28','2024-07-28','6 Month','2024-07-28',6.00),
('BOR9','109','TP009','2024-02-06','2024-05-06','3 Month','2024-05-06',NULL),
('BOR10','110','TP010','2024-02-06','2024-05-07','3 Month','2024-05-07',NULL),
('BOR11','111','TP011','2024-02-11','2024-09-11','7 Month','2024-09-11',4.00),
('BOR12','112','TP012','2024-02-19','2024-03-19','1 Month','2024-03-19',NULL),
('BOR13','113','TP013','2024-02-20','2024-03-28','8 Days','2024-03-28',NULL),
('BOR14','114','TP014','2024-02-29','2024-04-29','1 Month','2024-04-29',NULL),
('BOR15','115','TP015','2024-03-31','2025-12-31','9 Month','2024-12-31',NULL),
('BOR16','116','TP016','2024-04-07','2024-04-30','23 Days','2024-04-30',NULL),
('BOR17','117','TP017','2024-04-09','2025-04-09','1 Year','2025-04-09',10.00),
('BOR18','118','TP018','2024-04-13','2024-08-13','4 Month','2024-08-13',NULL),
('BOR19','119','TP019','2024-04-17','2024-04-28','11 Days','2024-04-28',9.00),
('BOR20','120','TP020','2024-05-23','2024-08-23','3 Month','2024-08-23',NULL),
('BOR21','121','TP021','2024-05-23','2025-06-23','1 Month','2025-06-23',NULL),
('BOR22','122','TP022','2024-06-14','2024-08-14','2 Month','2024-08-14',NULL),
('BOR23','123','TP023','2024-07-14','2025-07-14','1 Year','2025-07-14',10.00),
('BOR24','124','TP024','2024-08-06','2024-08-20','2 Days','2024-08-20',NULL),
('BOR25','125','TP025','2024-08-12','2024-08-20','8 Days','2024-08-20',NULL),
('BOR26','126','TP026','2024-09-19','2024-12-19','3 Month','2024-12-19',NULL),
('BOR27','127','TP027','2024-10-21','2024-11-21','1 Month','2024-11-21',4.00),
('BOR28','128','TP028','2024-10-13','2024-12-13','2 Month','2024-12-13',NULL),
('BOR29','129','TP029','2024-12-12','2025-02-12','1 Year','2025-02-12',NULL),
('BOR30','130','TP030','2024-12-25','2025-02-13','2 Month','2025-02-13',NULL);

insert into room
(RoomID,RoomType,ReservationDate,MemberID)
values
('R01','A','2024-01-14','TP001'),
('R02','B',NULL,'TP002'),
('R03','B',NULL,'TP003'),
('R04','A',NULL,'TP004'),
('R05','C',NULL,'TP005'),
('R06','C','2024-02-16','TP006'),
('R07','A','2024-01-30','TP007'),
('R08','B',NULL,'TP008'),
('R09','C','2024-03-25','TP009'),
('R10','B',NULL,'TP010'),
('R11','C','2024-05-15','TP011'),
('R12','B','2024-02-29','TP012'),
('R13','A',NULL,'TP013'),
('R14','B',NULL,'TP014'),
('R15','A',NULL,'TP015'),
('R16','C','2024-04-08','TP016'),
('R17','B',NULL,'TP017'),
('R18','C','2024-06-30','TP018'),
('R19','C',NULL,'TP019'),
('R20','B',NULL,'TP020'),
('R21','A','2024-05-30','TP021'),
('R22','B',NULL,'TP022'),
('R23','A',NULL,'TP023'),
('R24','C',NULL,'TP024'),
('R25','A',NULL,'TP025'),
('R26','A',NULL,'TP026'),
('R27','B','2024-10-22','TP027'),
('R28','B',NULL,'TP028'),
('R29','C','2025-01-28','TP029'),
('R30','B',NULL,'TP030');

insert into loan
(LoanID,BorrowID,LoanDur)
values
('L1','BOR1','1 Month'),
('l2','BOR2','2 Month'),
('L3','BOR3','3 Month'),
('L4','BOR4','2 Month'),
('L5','BOR5','4 Month'),
('L6','BOR6','3 Month'),
('L7','BOR7','1 Month'),
('L8','BOR8','6 Month'),
('L9','BOR9','3 Month'),
('L10','BOR10','3 Month'),
('L11','BOR11','7 Month'),
('L12','BOR12','1 Month'),
('L13','BOR13','8 Days'),
('L14','BOR14','1 Month'),
('L15','BOR15','9 Month'),
('L16','BOR16','23 Days'),
('L17','BOR17','1 Year'),
('L18','BOR18','4 Month'),
('L19','BOR19','11 Days'),
('L20','BOR20','3 Month'),
('L21','BOR21','1 Month'),
('L22','BOR22','2 Month'),
('L23','BOR23','1 Year'),
('L24','BOR24','2 Days'),
('L25','BOR25','8 Days'),
('L26','BOR26','3 Month'),
('L27','BOR27','1 Month'),
('L28','BOR28','2 Month'),
('L29','BOR29','1 Year'),
('L30','BOR30','2 Month');


select * FROM members
select * FROM items
Select * FROM borrowing
Select * FROM room
Select * FROM loan

--1






select*from members inner join room on members.memberID = room.memberID where members.gender = 'Male' and room.reservationdate is not null and members.age > (SELECT AVG(age) FROM members); 
