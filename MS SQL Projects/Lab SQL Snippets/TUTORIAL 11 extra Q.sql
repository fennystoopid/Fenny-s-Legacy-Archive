CREATE TABLE department(
deptid nvarchar(50) NOT NULL,
name nvarchar(50),
phone_ext integer,
PRIMARY KEY (deptid)
);

CREATE TABLE staff(
staffid nvarchar(50) NOT NULL,
name nvarchar(50),
gender nvarchar(1),
address nvarchar(50),
state nvarchar(50),
monthlysalary decimal(10,2), --integer,
deptid nvarchar(50) NOT NULL,
DOB date,
PRIMARY KEY (staffid),
FOREIGN KEY (deptid) references department(deptid),
);

insert into department
(DeptID,Name,Phone_Ext)
values
('D_001','Engineering',343),
('D_002','Marketing',333);

insert into staff
(StaffID,Name,Gender,Address,State,MonthlySalary,DeptID,DOB)
values
('S_001','Kevin','M','Puchong','Selangor',3500,'D_002','1981-06-24'),
('S_002','Issac','M','Klang','Selangor',3490,'D_002','1982-06-24'),
('S_003','Olivia','F','Kuantan','Pahang',5300,'D_001','1983-06-24'),
('S_004','Tommy','M','Kinrara','Selangor',2454,'D_002','1984-06-24'),
('S_005','Tarvina','F','Gombak','Wilayah',3500,'D_001','1985-06-24'),
('S_006','Marcella','F','Hulu Langat','Selangor',6580,'D_002','1986-06-24'),
('S_007','Melvin','M','Subang Jaya','Selangor',3903,'D_002','1987-06-24'),
('S_008','Phang','M','Cyberjaya','Selangor',2450,'D_002','1988-06-24'),
('S_009','Ricky','M','Johor Bharu','Johor',3488,'D_001','1989-06-24'),
('S_010','Eugene','M','Nilai','Seremban',5600,'D_001','1990-06-24');

Select * from department
Select * from staff

--a)
SELECT Name, Gender, MonthlySalary, DeptID
FROM staff
where monthlysalary < 4000 AND gender = 'M' AND deptid = 'D_002';

SELECT * 
FROM staff
INNER JOIN department ON staff.deptid = department.deptid
WHERE staff.monthlysalary < 4000 AND staff.gender = 'M' AND department.name = 'Marketing'

--b) 
SELECT department.deptid, department.name, COUNT(staff.staffid) AS NumofStaff
FROM Staff
INNER JOIN department ON staff.deptid = department.deptid
GROUP BY department.deptid, department.name;

--c)
SELECT AVG(monthlysalary * 12) as AvgAnnualSalary
FROM staff;

--d)
Insert into department
(deptid,name,phone_ext)
values
('D_004', 'Sales', 5014);

Select * from department

--e)
UPDATE staff
SET state = 'Kuala Lumpur', address = 'Sri Petaling'
WHERE name = 'Ricky';

Select * from staff

--f)
DELETE
FROM staff
WHERE name = 'Eugene';

Select * from staff

--g)
select department.name, SUM(monthlysalary) as TotalPaid
FROM staff
INNER JOIN department ON department.deptid = staff.deptid
GROUP BY department.name;

--h)
UPDATE staff



--i)
select state, COUNT(name) as TotalEmployees
FROM staff
GROUP BY state;

--j)


--o)
select * 
FROM staff
WHERE gender = 'F' and deptid = (select * from department where phone_ext = "%2_")








