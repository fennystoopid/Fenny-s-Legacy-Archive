CREATE TABLE course(
courseid nvarchar(50) NOT NULL PRIMARY KEY,
name nvarchar(50),
entryqualification nvarchar(50),
);

CREATE TABLE student(
studentid nvarchar(50) NOT NULL PRIMARY KEY,
name nvarchar(50),
gender nvarchar(50),
DOB date,
courseid nvarchar(50) FOREIGN KEY references course(courseid),
);

CREATE TABLE subject(
subjectid nvarchar(50) NOT NULL PRIMARY KEY,
name nvarchar(50),
courseid nvarchar(50) FOREIGN KEY references course(courseid),
);

insert into course
(CourseID,Name,EntryQualification)
values
('C01','Diploma','3 credits in O Level'),
('C02','Degree','3 credits in A Level'),
('C03','Master','Degree in any computing field'),
('C04','Foundation','5 credits in O Level');

insert into student
(StudentID,Name,Gender,DOB,CourseID)
values
('ST01','Helen','Female','1999-02-02','C01'),
('ST02','Karen','Female','2000-09-15','C02'),
('ST03','Peter','Male','1997-04-28','C02'),
('ST04','Shaun','Male','2001-06-30','C03');

insert into subject
(SubjectID,Name,CourseID)
values
('SU01','SAD','C01'),
('SU02','IDB','C01'),
('SU03','ISWE','C02'),
('SU04','CPP','C02'),
('SU05','Java','C03'),
('SU06','NNT','C04'),
('SU07','DAS','C04');

Select * from course;
Select * from student;
Select * from subject;

--5
SELECT StudentID, name, datediff(YEAR,DOB,GETDATE()) 
AS Age FROM student;

--6
SELECT StudentID, name, DATEDIFF(YEAR,DOB,GETDATE()) AS
Age FROM student
WHERE DATEDIFF(YEAR,DOB,GETDATE()) > 18;

--7
SELECT * FROM course
INNER JOIN student ON student.courseid = course.courseid
INNER JOIN subject ON subject.courseid = course.courseid;

--8
SELECT * 
FROM course, student
WHERE course.courseid = student.courseid;

--9
SELECT * 
FROM course, student, subject
WHERE course.courseid = student.courseid AND course.courseid = subject.courseid;

--10
SELECT *
FROM course
LEFT JOIN student
ON course.courseid = student.courseid
ORDER BY course.name ASC;

--11
SELECT *
FROM course
RIGHT JOIN student
ON course.courseid = student.courseid
ORDER BY student.name ASC;

--12
SELECT *
FROM course
LEFT JOIN student
ON course.courseid = student.courseid
WHERE student.studentid IS NULL
ORDER BY course.name ASC;

SELECT *
FROM course
WHERE CourseID NOT IN (SELECT CourseID FROM student);







