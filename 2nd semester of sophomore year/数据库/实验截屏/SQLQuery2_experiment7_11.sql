--实验七(数据完整性约束)验证性实验
--1)PRIMARY KEY 主键约束的建立
CREATE TABLE ST( --建立表时加主键约束
SNO VARCHAR (10) PRIMARY KEY ,
SNAME VARCHAR(20) NOT NULL, 
DEPT VARCHAR(20), 
AGE INT, 
SEX CHAR(4))
GO
INSERT INTO ST (SNO,SNAME,DEPT) VALUES('1001','ZXX',NULL)
GO
INSERT INTO ST (SNO,SNAME) VALUES('1001','MID')
GO 
INSERT INTO ST (SNO,SNAME) VALUES(NULL,'ZXX')

CREATE TABLE ST2 (  --在已有的表上添加约束
SNO VARCHAR (10) NOT NULL,
SNAME VARCHAR(20) NOT NULL,
DEPT VARCHAR(20), 
AGE INT, 
SEX CHAR(4))
GO
INSERT INTO ST2 SELECT * FROM S
GO
ALTER TABLE ST2 ADD CONSTRAINT pk_Sno PRIMARY KEY (SNO)
INSERT INTO ST2 (SNO,SNAME,DEPT) VALUES('200512','Beibei',NULL)
--2)DEFAULT 约束
CREATE TABLE CUST(
NO VARCHAR(5) PRIMARY KEY, 
WEIGHT INT DEFAULT(10))
GO
INSERT INTO CUST(NO) VALUES('ZY01')
INSERT INTO CUST(NO) VALUES('ZY03')
INSERT INTO CUST VALUES('ZY02',20) 
GO 
SELECT * FROM CUST
--3)CHECK 约束
CREATE TABLE CUSTOMER(CUSTNO CHAR(4) NOT NULL CHECK (CUSTNO LIKE 
'[A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9]'), CUSTNAME VARCHAR(20))
GO
INSERT INTO CUSTOMER VALUES('BJ01','Beijing Grid Corp.')
GO
INSERT INTO CUSTOMER VALUES('BJ1','Beijing Grid Corp.')
GO
INSERT INTO CUSTOMER VALUES('BJ*1','Beijing Grid Corp.')
--4)UNIQUE 唯一性约束的建立
CREATE TABLE CUST1(
CUSTNO CHAR(4)PRIMARY KEY,
CUSTNAME VARCHAR(20) UNIQUE,
COUNTRY VARCHAR(10))
GO 
INSERT INTO CUST1(CUSTNO) VALUES('BJ01')
GO
INSERT INTO CUST1(CUSTNO) VALUES ('BJ02')
GO
INSERT INTO CUST1 VALUES ('BJ03','Beijing Grid Corp.')
GO
INSERT INTO CUST1 VALUES ('BJ04','Beijing Grid Corp.')
--5)FOREIGN KEY 外键约束的建立
Create table S (
SNO VARCHAR (10) NOT NULL,
SNAME VARCHAR(20),
DEPT VARCHAR(20),
AGE INT,
SEX CHAR(4))
Create table C (
CNO VARCHAR(10) NOT NULL,
CNAME VARCHAR(20),
cpno varchar(10),
credit int)
Create table SC(
SNO VARCHAR(10) NOT NULL, 
CNO VARCHAR(10) NOT NULL, 
SCORE DECIMAL)
ALTER TABLE C ADD CONSTRAINT CpriKEY PRIMARY KEY(CNO)
GO
ALTER TABLE SC ADD CONSTRAINT scpriKEY PRIMARY KEY(SNO,CNO)
ALTER TABLE SC ADD CONSTRAINT scforKEY1 FOREIGN KEY (SNO) REFERENCES ST2(SNO)
ALTER TABLE SC ADD CONSTRAINT scforKEY2 FOREIGN KEY (CNO) REFERENCES C(CNO)
GO
INSERT INTO SC (SNO,CNO) VALUES('0','C10')
INSERT INTO SC (SNO,CNO) VALUES('200518','C01')
INSERT INTO SC (SNO,CNO) VALUES('890',NULL)
INSERT INTO SC (SNO,CNO) VALUES(NULL,'C10')
--实验七设计性实验 select * from s
--1)在 S 表中添加完整性约束：SNO 设置为主键，SEX 的却省值为’女’,AGE 的有效值为 16-25
alter table s add constraint pk_sno primary key (sno)
ALTER TABLE S ADD CONSTRAINT SEX_DEFAULT DEFAULT '女' FOR SEX --ALTER TABLE S ADD DEFAULT '女' FOR SEX 也对
alter table s add constraint check_age check (age>=16 and age<=25)
--2)创建 1 张与 S 相同的表 S1，在创建的同时将 SNO 设置为主键，SEX 的却省值为’女’,AGE 的有效值为 16-25 ，
--并将 S 表中的数据插入到 S1 中，插入不同的记录来调整设置的完整性
CREATE TABLE S1(
SNO VARCHAR(10) PRIMARY KEY,
SNAME VARCHAR(20),
DEPT VARCHAR(20),
AGE INT CHECK (AGE >=16 AND AGE <=25),
SEX CHAR(4) DEFAULT '女') 
insert into s1 select * from s
--3)创建 1 张与 SC 相同的表 SC1，将（SNO，CNO）设置为主键，SNO 和 CNO设置为外键，
--并将 SC 表中的数据复制到 SC1 中，插入不同的记录来严整设置的完整性
CREATE TABLE SC1(
SNO VARCHAR(10) NOT NULL,
CNO VARCHAR(10) NOT NULL,
SCORE DECIMAL
PRIMARY KEY(SNO,CNO))
alter table sc1 add constraint fk_sno foreign key(sno) references sc(sno) --TODO
alter table sc1 add constraint fk_cno foreign key(cno) references sc(cno)
insert into sc1 select * from sc
--4)创建 1 张与 C 表相同的表 C1，将 C 中数据插入到 C1 后，在 C1 上添加完整性约束
--将（CNO）设置为主键，CPNO 引用 CNO，CREDIT 值为 1-6
CREATE TABLE C1(
CNO VARCHAR(10) NOT NULL,
CNAME VARCHAR(20),
CPNO VARCHAR(10),
CREDIT INT)
insert into c1 select * from c
alter table c1 add constraint pk_cno primary key (cno) --将（CNO）设置为主键
alter table c1 add constraint fk foreign key(cpno) references c1(cno)
alter table c1 add constraint check_credit check (credit>=1 and credit<=6)
--实验8(SQL 编程及存储过程)的验证性实验
--1) 编程实现查询与’李勇’同系的学生学号
USE LMS
GO 
DECLARE @DEPT VARCHAR(20)
SELECT @DEPT=DEPT FROM S WHERE SNAME='李勇'
SELECT SNO FROM S WHERE DEPT=@DEPT
--2) 运行下面的程序，观察运行结果
DECLARE @X INT, @Y INT
SET @X=0
SELECT @Y=1
WHILE @Y<20
 BEGIN
 SET @X=@X+@Y
 SELECT @Y=@Y+2
 PRINT STR(@Y)+'IN THE LOOP'
IF @Y>14 
BREAK
 END
PRINT 'OUT OF THE LOOP'
--3) CASE 函数的使用
--CASE后带表达式
Select 性别=case sex  
	when '男' then 'M'
	when '女' then 'F'
	else '输入出错'
	end
From s
--CASE后不带参数
SELECT 性别=CASE 
	WHEN SEX= '男' THEN 'M'
	WHEN SEX= '女' THEN 'F' ELSE 'ERROR'
END
FROM S
--用CASE 语句进行多条件修改
update s set DEPT=case DEPT
when '计算机系' then 'CS'
when '信息系' then 'IS'
when '数学系' then 'MA'
when '物理系' then 'PH'
end
--4) 存储过程
--1.不带参数的存储过程
CREATE PROC SCLIST
AS
SELECT SNO,CNO, SCORE FROM SC WHERE SNO IN 
(SELECT SNO FROM S WHERE DEPT='计算机系')
--执行存储过程,观察结果：
EXEC SCLIST
--2.带参数的存储过程(如：传入一个学生的学号与姓名,显示出这个学生选修的课程号,成绩)
CREATE PROC SC_PROC @xh varchar(10) 
AS 
SELECT cno , SCORE
 From sc
 Where sc.sno=@xh
-- 执行存储过程：
EXEC SC_PROC '200512'
--5)存储过程的相关操作
--① 查看存储过程:
Sp_help SCLIST
--② 重命名存储过程
Sp_rename 'SCLIST','STUDENTSCORE' --Sp_rename 'STUDENTSCORE','SCLIST'
--Sp_help STUDENTSCORE
--实验8设计性实验
--1)调用帮助系统来查找系统存储过程或函数来显示 SQL SERVER 的版本号及当前系统时间
--提示：到帮助中根据关键字等查询到对应的函数或存储过程来完成任务
EXEC sp_MSgetversion --使用系统存储过程 sp_MSgetversion,返回包含 SQL Server 版本信息的结果集
SELECT SERVERPROPERTY('ProductVersion') AS '版本号', 
       SERVERPROPERTY('ProductLevel') AS '版本级别', 
       SERVERPROPERTY('Edition') AS '版本类型'
SELECT GETDATE() AS '当前系统时间'
--2)编写存储过程：完成 1！+2！+…+n！的计算
--提示：传入参数 n，根据 N 用循环控制来求对应的值
create proc factorial_sum @n bigint,@result bigint output
as
begin
	set nocount on
	declare @i bigint = 1
	declare @factorial bigint = 1
	SET @result = 0
	while @i<=@n
		begin
			declare @j bigint = 1
			set @factorial=1
			while @j<=@i
			begin
				set @factorial=@factorial*@j
				set @j=@j+1
			end
			set @result=@result+@factorial
			select @i=@i+1
	end
end
declare @nn bigint = 5
declare @res bigint
exec factorial_sum @nn,@res output
select @res as '计算结果'
--3)将 S 表中的 DEPT 字段内容改为中文：IS-信息系，CS-计算机系，PH-物理系，MA-数学系
--提示：用 UPDATE 语句来修改 DEPT 字段，DEPT 的值根据不同英文缩写要修改为不同的中文系名，用 CASE 函数来完成
update s set dept=case dept
when 'IS' then '信息系'
when 'CS' then '计算机系'
when 'PH' then '物理系'
when 'MA' then '数学系'
end
--4)将 C 表上增加一个字段 seleNUM，并编写存储过程：传入学号和课程号后
--完成在 SC 表中插入相应的选课记录，并在 C 表中对应课程的 seleNUM 加 1。
alter table c add seleNUM int 
create proc update_course @student_id varchar(10),@course_id varchar(10)
as
insert into sc(sno,cno)
values(@student_id,@course_id)
update c
set seleNUM=seleNUM+1
where cno=@student_id
exec update_course '2005213','工数'
--实验9(事务处理和触发器)验证性实验
--1）用 ROLLBACK TRAN 实现事务的回滚操作
USE LMS
GO
BEGIN TRAN 
SELECT * FROM C
INSERT INTO C VALUES('C08','决策支持系统',NULL, 3)
SELECT * FROM C
ROLLBACK TRAN
SELECT * FROM C
--2）事务回滚点的保存
USE LMS
GO 
BEGIN TRAN Mytran
SELECT * FROM C
INSERT INTO C VALUES('C09', '信息分析与预测', NULL,4)
SAVE TRAN POINT1
INSERT INTO C VALUES('C10', '数据挖掘', NULL, 3)
SELECT * FROM C
ROLLBACK TRAN POINT1
SELECT * FROM C
--观察最后的C表中的数据结果与前面C表显示结果的不同。
--3)触发器的建立
--在S表建立建立如下触发器
CREATE TRIGGER TRIGONS
ON S FOR UPDATE
AS
SELECT * FROM DELETED
SELECT * FROM INSERTED
--选中上述触发器创建语句并执行，然后输入下面语句：
UPDATE S 
SET DEPT ='计算机系' WHERE DEPT='CP'
--在S表上建立下面触发器
CREATE TRIGGER TEMPTABLE
ON S FOR INSERT
AS
SELECT * FROM INSERTED
ROLLBACK TRAN
--执行上述触发器后在S表中插入数据，
INSERT INTO S(SNO,SNAME) VALUES('10012','ZXX')
--执行插入语句后打开S观察结果
--在C表中加入一列selectNum表示选课数量，在SC表上插入一条选课记录后，将C表中对应的课程的selectNum值加1。
CREATE TRIGGER SELECTCOURSE
ON SC FOR INSERT
AS
IF (SELECT COUNT(*) FROM INSERTED)>1 
BEGIN
	PRINT 'YOU CAN INSERT ONE RECORD ONCE.SO THE RECORDS ARE NOT INSERTED INTO THE TABLE'
	ROLLBACK TRAN
END
ELSE
BEGIN
	DECLARE @CNO VARCHAR(10)
	SELECT @CNO=CNO FROM INSERTED
	UPDATE C
	SET selectNum=selectNum+1 WHERE CNO=@CNO
	PRINT 'THE NUMBER OF STUDENTS WHO SELECTED'+@CNO +'HAS BEEN ADDED'
END
--4)触发器的修改、删除
--修改触发器
--ALTER TRIGGER 触发器名 ON 表名
--AFTER INSERT/UPDATE/DELETE
--AS 
--T-SQL语句组
--在调试触发器时可以用修改触发器的语句来进行。如：
CREATE TRIGGER DELS --错误版本
ON S FOR DELETE 
AS
DECLARE @DEPT VARCHAR(20)
SELECT @DEPT=DEPT FROM INSERTED
IF @DEPT='CS'
BEGIN
	PRINT 'YOU CAN NOT DELETE THE STUDENT FROM CS'
	ROLLBACK
END
--执行上面的触发器，发现错误，则修改触发器。
ALTER TRIGGER DELS --正确版本
ON S FOR DELETE 
AS
DECLARE @DEPT VARCHAR(20)
SELECT @DEPT=DEPT FROM DELETED
IF @DEPT='CS'
BEGIN
	PRINT 'YOU CAN NOT DELETE THE STUDENT FROM CS'
	ROLLBACK
END
--删除触发器(DROP TRIGGER 表名.触发器名)
DROP TRIGGER S.DELS
--实验9设计性实验
--1)将 S 表的 PRIMARY KEY 完整性约束删除，编写一个 S 表上的触发器来完成在S
--表上插入记录时实现如下目标：SNO 不能为空，且 SNO 不能重复
alter table s drop constraint pk_s --TODO:pk_s改成s的完整性约束的实际名字
create trigger s_insert_action
on s for insert 
as 
begin 
	if exists(select * from s inserted where sno is null) --检查 SNO 是否为空
	begin 
		print '学号不能为空!'
		rollback tran
		return 
	end
	if exists(select * from s inner join inserted on s.sno=inserted.sno)--检查SNO是否重复
	begin 
		print '学号不能重复!'
		rollback tran
		return 
	end
end
--2)在C表修改记录时，若修改的是 CREDIT 字段,则修改值超过6时提示出错信息并不将结果写出数据表
create trigger c_update_credit
on c inserted of update
as 
begin
	if update(credit)
	begin
		if exists(select * from inserted where credit >6)
		begin
			print 'oops!you cannot update credit more than 6!'
			rollback tran
			return
		end
	end
	update c set c.credit=I.credit from c inner join inserted I on c.cno=I.cno
end
--实验10(数据库安全与数据库恢复)验证性实验(全是手动操作)

--实验11--数据库设计(画E-R图化简,不用在此操作)
