CREATE TABLE student(
studentid nvarchar(50) Not Null,
name nvarchar(50),
gender nvarchar(50),
DOB date,
address nvarchar(50),
Primary Key (studentid)
);

insert into student
(StudentID,Name,Gender,DOB,Address)
values
('S01','Ali','Male','1996-02-02','Kuala Lumpur'),
('S02','Nancy','Female','1997-05-16','Bukit Jalil'),
('S03','Melvin','Male','1998-11-20',NULL),
('S04','Angeline','Female','1995-12-30','Sri Petaling');

Select * from student;