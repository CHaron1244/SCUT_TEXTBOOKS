--实验二:创建和管理数据库
CREATE DATABASE LMS
--实验三:表建立与数据插入
--(一):企业管理器的使用--->这部分是手动建表
--(二):查询分析器使用
USE LMS
CREATE TABLE student(
SNO VARCHAR(10) NOT NULL,
SNAME VARCHAR(20) NOT NULL,
SEX CHAR(2),
BIRTHDAY DATETIME)
insert into student
values('200512','Josephine','F','1980-12-20')
--实验三设计性实验
INSERT INTO STUDENT
VALUES('212512','ALICE','M','1980-12-20')
SELECT * FROM STUDENT
select * from student where sex = 'M'
CREATE TABLE S(
SNO VARCHAR(10) NOT NULL,
SNAME VARCHAR(20),
DEPT VARCHAR(20),
AGE INT,
SEX CHAR(4)) 
CREATE TABLE C(
CNO VARCHAR(10) NOT NULL,
CNAME VARCHAR(20),
CPNO VARCHAR(10),
CREDIT INT)
CREATE TABLE SC(
SNO VARCHAR(10) NOT NULL,
CNO VARCHAR(10) NOT NULL,
SCORE DECIMAL)
INSERT INTO S
VALUES('200512','李勇','计算机系',20,'男'),
('200518','刘晨','计算机系',19,'女'),
('200018','王敏','数学系',18,'女'),
('200511','杨扬','物理系',20,'男'),
('200510','张立','信息系',19,'男'),
('200513','张立','物理系',19,'男'),
('200514','王点点','信息系',19,'女'),
('200012','欧阳雨','数学系',20,'男'),
('200515','刘依依','数学系',23,'女')
INSERT INTO C
VALUES('c01','数据库原理','c03',4),
('c02','信息系统','c01',4),
('c03','数据结构',NULL,6),
('c04','DB_设计','c01',3)
INSERT INTO SC
VALUES('200512','c02',70),
('200512','c03',NULL),
('200512','c04',NULL),
('200515','c01',80),
('200518','c03',95),
('200018','c01',80),
('200518','c02',45),
('200511','c02',78),
('200511','c01',45),
('200511','c03',89),
('200514','c02',78),
('200514','c01',45),
('200514','c03',89),
('200514','c04',78)
--实验四(单表查询)的设计性实验
--1)无条件查询全部数据
USE LMS
select * from s
--2)在 SELECT 关键字后指明要检索的列名
select sno,sname from s --查询S表的学生学号和姓名
select dept from s --查询S表中的系部名
select distinct dept from s --查询S表中不重复的系部名
--3)改变列标题的检索
select sno 学号,sname 姓名 from s
select sno as 学号,sname as 姓名 from s
--4)有条件选择的查询
select * from s where dept='信息系' --在S表检索“信息系”的学生信息
select * from s where sname like '王%' --在S表中检索姓“王”的学生信息
select sno,cno from sc where cno='c01' and score is null --在SC表检索’C01’选修课成绩为空的选课记录
select sno,sname from s where age in (21,18,22) --检索年龄为21，18，22的学生学号、姓名
select sno,sname from s where age=18 or age=21 or age=22 --跟上面一句等价
--5)使用聚集函数
select max(score), avg(score),min(score) from sc
select max(score), avg(score),min(score) from sc where cno='c01' --查询“C01”课程的最高分、平均分和最小成绩
--6)对检索结果进行排序
select * from sc
where score is null
order by sno,cno desc
--7)进行分组统计
select sno,count(*) from sc group by sno --查询各学生的选课数
select sno,count(*) from sc group by sno having count(*) >=3  --选课表中查询选修了3 门以上课程的学生学号
select sno 学号,avg(score) 平均分 from sc group by sno order by 平均分 desc  --选课表中按学号分组汇总学生的平均分，并按平均分降序排列
select sno from sc
order by sno
go
select sno from sc
group by sno
--实验四的设计性实验!
select sno,sname from s where dept='计算机系' --1查询计算机系学生的学号和姓名。
select distinct sno from sc --2查询选修了课程的学生学号
--3查询选修 C01 课程的学生学号和成绩，并要求对查询结果按成绩的降序排列
--如果成绩相同则按学号的升序排列
select sno,score from sc where cno='c01'order by score desc,sno asc 
select cno 自己想查询的课程,avg(score) from sc group by cno --4查询每门课程的平均分
select count(cno) from c --5查询学校开设的课程总数
select sno from sc group by sno having count(cno) >= 2 --6查询选修两门及两门以上课程的学生学号
select sno,sname,dept from s where age>=20 and age<=22 and sex='男' --7查询年龄在 20-22 之间的男生的学号、姓名、系部
select count(*) from sc where cno='c01' --8查询选修’C01’课程的学生人数
--实验五(多表查询)的验证性实验
--1)多表的连接查询
select * from c,sc
--2)表的等值连接查询
select sno,cname,score from c,sc where c.cno=sc.cno --查询各学生的选课信息（包括学号、课程名、成绩）
select s.sno,sname,cno,score from s,sc where s.sno=sc.sno --查询学生的选课记录，显示学生的学号、姓名、课程号、成绩）
select s.sno,sname,sc.cno,cname,score from s,sc,c where s.sno=sc.sno and sc.cno=c.cno --查询学生的选课记录，显示学生的学号、姓名、课程号、课程名、成绩
insert into s(sno,sname) values('20000','ZXX')--左外连接查询：当希望左表（第一张表）中所有记录全部显示出来时，需要用左外连接操作
select s.sno,sname,cno,score from s left outer join sc on s.sno=sc.sno
--3)表自身的连接
select s1.sno from s as s1,s as s2 where s1.dept=s2.dept and s2.sname='李勇' --查询与’李勇’同系的学生学号
select sno,cno,score from sc as sc1 where score < (select max(score) from sc as sc2 where sc2.sno=sc1.sno) --显示每个学生的非最高分成绩
--4)IN 嵌套子查询
--不相关的IN 子查询：子查询可以单独执行，与被嵌套的查询无关。
--如，查询与’李勇’同系的学生学号
select sno
from s
where dept in(select dept	
			  from s
			  where sname='李勇')
select count(*) from sc --查询’数据库原理’课程的选课人数
where cno in(select cno 
			 from c
			 where cname='数据库原理')
--相关的子查询：子查询中要用到父查询表的信息，子查询不能独立执行。
--如，查询选修课程号为“C01”课程且成绩至少高于选修课程号为“C02”的同学的Cno、Sno和SCORE
select cno,sno,score 
from sc as sc1
where cno='c01' and score>(select score
							from sc as sc2
							where sc2.sno=sc1.sno and sc2.cno='c02')
--5)EXISTS 嵌套子查询
select sno,sname from s where exists(select * from sc where cno='c03') 
go 
select sno,sname from s  
insert into c values('c06','数据库安全',NULL,3)
select sno,sname from s where exists(select * from sc where cno='c03')
select count(*) from sc where exists(select * from c where c.cno=sc.cno and cname='数据库原理')  --查询’数据库原理’课程的选课人数
--实验五设计性实验
select score from sc,s where sc.sno=s.sno and s.dept='计算机系' --1查询“计算机系“学生所教课程的成绩表
select sc1.sno 名字,score from sc as sc1 where score < (select avg(score) from sc as sc2) --2查询成绩比该课程平均成绩低的同学的成绩表
select sno,cno,score from sc where cno='c01' order by cno desc,score asc --3查询选修 C01 课程的学生学号、课程名、成绩，并要求对查询结果按学号的降序排列，如果学号相同则按成绩的升序排列
select sc.sno 学号,sname 姓名 from s,sc where s.sno=sc.sno group by sc.sno,sname having count(sc.cno)>=2 --4查询选修两门及两门以上课程的学生学号及姓名
select c.cno from s,sc,c where s.age>=20 and s.age<=22 and s.sex='男' and sc.sno=s.sno and sc.cno=c.cno --5查询年龄在 20-22 之间的男生的选修的课程号
select count(*) from sc,c where sc.cno=c.cno and c.cname='数据结构' --6查询选修’数据结构’课程的学生人数
select s.sno,s.sname from s where exists(select * from sc sc1 where s.sno=sc1.sno and sc1.score>=80) and not exists(select * from sc sc2 where s.sno=sc2.sno and sc2.score<80) --7查询每门选课成绩在 80 分以上的学生学号、姓名
--实验六(数据操作与索引)的验证性实验
--1)数据的插入
use lms  -- 单记录的插入
go
select * from s 
insert into s(sno,sname) values('200300','Paulwen')
select * from s
create table sbak(  --多记录的插入
sno varchar(10) not null,
sname varchar(20),
dept varchar(20),
age int,
sex char(4))
go 
select * from sbak
insert into sbak (select * from s) 
select * from sbak
--2)数据的删除
create table cbak(
cno varchar(10) not null,
csname varchar(20),
cpno varchar(10),
credit int)
go
insert into cbak select * from c 
delete from cbak where credit<4 
select * from cbak
--3)数据的修改
select * from s
update s set dept='cs' where dept='计算机系'
go
select * from s
--4)索引的建立
--建立非聚族索引
select * from c  
go 
create index icname on c(cname)
go 
select * from c  --看数据表
select * from c(index=icname) --按索引次序看数据表
--建立聚族索引
select * from c 
go 
create clustered index cicno on c(cno)
go
select * from c
--建立唯一索引
create unique index uisno on sc(sno)
--create unique index uisno on sc(sno,cno desc)
--建立复合索引
select * from s
go
create index iagesno on s(age desc,sno)
go
select * from s
select * from s(index=iagesno)
--查看表中的索引
sp_helpindex 's'
--删除表中的索引
drop index s.iagesno
go
sp_helpindex 's'
--5)视图及其操作
--view creation
create view showsno
as 
select s.sno,sname,avg(score) as 平均成绩
from s,sc
where s.sno=sc.sno
group bu s.sno,sname
go
select * from showsno
CREATE VIEW VISDEPT ---创建信息系学生的视图
AS 
SELECT * FROM S WHERE DEPT='信息系'
--在视图上修改数据
update visdept
set dept='IS'
go
select * from visdept
create view s_sum
as
select sno,sum(score) as totalscore from sc
group by sno
go
update s_sum set totalscore=60
--在视图上删除数据
select * from visdept
delete from  visdept where sex='女'
select * from visdept 
select * from s
--实验6设计性实验 
--1) 将 S 表系部为“计算机系”学生对应的系部改为’CS’
update s set dept='CS' where dept='计算机系'
--2) 创建一个与 SC 表相同新数据表 SCNEW，查询 SC 表中成绩为空的记录并将其复制到 SCNEW 表中。 
CREATE TABLE SCNEW(
SNO VARCHAR(10) NOT NULL,
CNO VARCHAR(10) NOT NULL,
SCORE DECIMAL)
insert into scnew select * from sc where score=NULL
select * from scnew
--3) 删除 SC 表中成绩为空的选课记录
delete from sc where score=null
--4) 根据 S 表中姓名字段建立唯一性索引
create unique index sname_index on s(sname)
--5) 建立 S 表上 SNO 的聚族索引
create clustered index sno_index on s(sno)
--6) 建立 SC 表上根据 SNO 升序，CNO 降序的复合索引
create index sno_cno_index on  sc(sno asc,cno desc)
--7) 建立每门课程的课程号、课程名、选课人数、平均分的视图(报错也没问题)
create view course_view 
as 
select sc.cno 课程号,cname 课程名, count(*) 选择人数,avg(score) 平均分
from c,sc
where c.cno=sc.cno
group by sc.cno,cname