--ʵ����(����������Լ��)��֤��ʵ��
--1)PRIMARY KEY ����Լ���Ľ���
CREATE TABLE ST( --������ʱ������Լ��
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

CREATE TABLE ST2 (  --�����еı������Լ��
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
--2)DEFAULT Լ��
CREATE TABLE CUST(
NO VARCHAR(5) PRIMARY KEY, 
WEIGHT INT DEFAULT(10))
GO
INSERT INTO CUST(NO) VALUES('ZY01')
INSERT INTO CUST(NO) VALUES('ZY03')
INSERT INTO CUST VALUES('ZY02',20) 
GO 
SELECT * FROM CUST
--3)CHECK Լ��
CREATE TABLE CUSTOMER(CUSTNO CHAR(4) NOT NULL CHECK (CUSTNO LIKE 
'[A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9]'), CUSTNAME VARCHAR(20))
GO
INSERT INTO CUSTOMER VALUES('BJ01','Beijing Grid Corp.')
GO
INSERT INTO CUSTOMER VALUES('BJ1','Beijing Grid Corp.')
GO
INSERT INTO CUSTOMER VALUES('BJ*1','Beijing Grid Corp.')
--4)UNIQUE Ψһ��Լ���Ľ���
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
--5)FOREIGN KEY ���Լ���Ľ���
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
--ʵ���������ʵ�� select * from s
--1)�� S �������������Լ����SNO ����Ϊ������SEX ��ȴʡֵΪ��Ů��,AGE ����ЧֵΪ 16-25
alter table s add constraint pk_sno primary key (sno)
ALTER TABLE S ADD CONSTRAINT SEX_DEFAULT DEFAULT 'Ů' FOR SEX --ALTER TABLE S ADD DEFAULT 'Ů' FOR SEX Ҳ��
alter table s add constraint check_age check (age>=16 and age<=25)
--2)���� 1 ���� S ��ͬ�ı� S1���ڴ�����ͬʱ�� SNO ����Ϊ������SEX ��ȴʡֵΪ��Ů��,AGE ����ЧֵΪ 16-25 ��
--���� S ���е����ݲ��뵽 S1 �У����벻ͬ�ļ�¼���������õ�������
CREATE TABLE S1(
SNO VARCHAR(10) PRIMARY KEY,
SNAME VARCHAR(20),
DEPT VARCHAR(20),
AGE INT CHECK (AGE >=16 AND AGE <=25),
SEX CHAR(4) DEFAULT 'Ů') 
insert into s1 select * from s
--3)���� 1 ���� SC ��ͬ�ı� SC1������SNO��CNO������Ϊ������SNO �� CNO����Ϊ�����
--���� SC ���е����ݸ��Ƶ� SC1 �У����벻ͬ�ļ�¼���������õ�������
CREATE TABLE SC1(
SNO VARCHAR(10) NOT NULL,
CNO VARCHAR(10) NOT NULL,
SCORE DECIMAL
PRIMARY KEY(SNO,CNO))
alter table sc1 add constraint fk_sno foreign key(sno) references sc(sno) --TODO
alter table sc1 add constraint fk_cno foreign key(cno) references sc(cno)
insert into sc1 select * from sc
--4)���� 1 ���� C ����ͬ�ı� C1���� C �����ݲ��뵽 C1 ���� C1 �����������Լ��
--����CNO������Ϊ������CPNO ���� CNO��CREDIT ֵΪ 1-6
CREATE TABLE C1(
CNO VARCHAR(10) NOT NULL,
CNAME VARCHAR(20),
CPNO VARCHAR(10),
CREDIT INT)
insert into c1 select * from c
alter table c1 add constraint pk_cno primary key (cno) --����CNO������Ϊ����
alter table c1 add constraint fk foreign key(cpno) references c1(cno)
alter table c1 add constraint check_credit check (credit>=1 and credit<=6)
--ʵ��8(SQL ��̼��洢����)����֤��ʵ��
--1) ���ʵ�ֲ�ѯ�롯���¡�ͬϵ��ѧ��ѧ��
USE LMS
GO 
DECLARE @DEPT VARCHAR(20)
SELECT @DEPT=DEPT FROM S WHERE SNAME='����'
SELECT SNO FROM S WHERE DEPT=@DEPT
--2) ��������ĳ��򣬹۲����н��
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
--3) CASE ������ʹ��
--CASE������ʽ
Select �Ա�=case sex  
	when '��' then 'M'
	when 'Ů' then 'F'
	else '�������'
	end
From s
--CASE�󲻴�����
SELECT �Ա�=CASE 
	WHEN SEX= '��' THEN 'M'
	WHEN SEX= 'Ů' THEN 'F' ELSE 'ERROR'
END
FROM S
--��CASE �����ж������޸�
update s set DEPT=case DEPT
when '�����ϵ' then 'CS'
when '��Ϣϵ' then 'IS'
when '��ѧϵ' then 'MA'
when '����ϵ' then 'PH'
end
--4) �洢����
--1.���������Ĵ洢����
CREATE PROC SCLIST
AS
SELECT SNO,CNO, SCORE FROM SC WHERE SNO IN 
(SELECT SNO FROM S WHERE DEPT='�����ϵ')
--ִ�д洢����,�۲�����
EXEC SCLIST
--2.�������Ĵ洢����(�磺����һ��ѧ����ѧ��������,��ʾ�����ѧ��ѡ�޵Ŀγ̺�,�ɼ�)
CREATE PROC SC_PROC @xh varchar(10) 
AS 
SELECT cno , SCORE
 From sc
 Where sc.sno=@xh
-- ִ�д洢���̣�
EXEC SC_PROC '200512'
--5)�洢���̵���ز���
--�� �鿴�洢����:
Sp_help SCLIST
--�� �������洢����
Sp_rename 'SCLIST','STUDENTSCORE' --Sp_rename 'STUDENTSCORE','SCLIST'
--Sp_help STUDENTSCORE
--ʵ��8�����ʵ��
--1)���ð���ϵͳ������ϵͳ�洢���̻�������ʾ SQL SERVER �İ汾�ż���ǰϵͳʱ��
--��ʾ���������и��ݹؼ��ֵȲ�ѯ����Ӧ�ĺ�����洢�������������
EXEC sp_MSgetversion --ʹ��ϵͳ�洢���� sp_MSgetversion,���ذ��� SQL Server �汾��Ϣ�Ľ����
SELECT SERVERPROPERTY('ProductVersion') AS '�汾��', 
       SERVERPROPERTY('ProductLevel') AS '�汾����', 
       SERVERPROPERTY('Edition') AS '�汾����'
SELECT GETDATE() AS '��ǰϵͳʱ��'
--2)��д�洢���̣���� 1��+2��+��+n���ļ���
--��ʾ��������� n������ N ��ѭ�����������Ӧ��ֵ
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
select @res as '������'
--3)�� S ���е� DEPT �ֶ����ݸ�Ϊ���ģ�IS-��Ϣϵ��CS-�����ϵ��PH-����ϵ��MA-��ѧϵ
--��ʾ���� UPDATE ������޸� DEPT �ֶΣ�DEPT ��ֵ���ݲ�ͬӢ����дҪ�޸�Ϊ��ͬ������ϵ������ CASE ���������
update s set dept=case dept
when 'IS' then '��Ϣϵ'
when 'CS' then '�����ϵ'
when 'PH' then '����ϵ'
when 'MA' then '��ѧϵ'
end
--4)�� C ��������һ���ֶ� seleNUM������д�洢���̣�����ѧ�źͿγ̺ź�
--����� SC ���в�����Ӧ��ѡ�μ�¼������ C ���ж�Ӧ�γ̵� seleNUM �� 1��
alter table c add seleNUM int 
create proc update_course @student_id varchar(10),@course_id varchar(10)
as
insert into sc(sno,cno)
values(@student_id,@course_id)
update c
set seleNUM=seleNUM+1
where cno=@student_id
exec update_course '2005213','����'
--ʵ��9(������ʹ�����)��֤��ʵ��
--1���� ROLLBACK TRAN ʵ������Ļع�����
USE LMS
GO
BEGIN TRAN 
SELECT * FROM C
INSERT INTO C VALUES('C08','����֧��ϵͳ',NULL, 3)
SELECT * FROM C
ROLLBACK TRAN
SELECT * FROM C
--2������ع���ı���
USE LMS
GO 
BEGIN TRAN Mytran
SELECT * FROM C
INSERT INTO C VALUES('C09', '��Ϣ������Ԥ��', NULL,4)
SAVE TRAN POINT1
INSERT INTO C VALUES('C10', '�����ھ�', NULL, 3)
SELECT * FROM C
ROLLBACK TRAN POINT1
SELECT * FROM C
--�۲�����C���е����ݽ����ǰ��C����ʾ����Ĳ�ͬ��
--3)�������Ľ���
--��S�����������´�����
CREATE TRIGGER TRIGONS
ON S FOR UPDATE
AS
SELECT * FROM DELETED
SELECT * FROM INSERTED
--ѡ������������������䲢ִ�У�Ȼ������������䣺
UPDATE S 
SET DEPT ='�����ϵ' WHERE DEPT='CP'
--��S���Ͻ������津����
CREATE TRIGGER TEMPTABLE
ON S FOR INSERT
AS
SELECT * FROM INSERTED
ROLLBACK TRAN
--ִ����������������S���в������ݣ�
INSERT INTO S(SNO,SNAME) VALUES('10012','ZXX')
--ִ�в��������S�۲���
--��C���м���һ��selectNum��ʾѡ����������SC���ϲ���һ��ѡ�μ�¼�󣬽�C���ж�Ӧ�Ŀγ̵�selectNumֵ��1��
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
--4)���������޸ġ�ɾ��
--�޸Ĵ�����
--ALTER TRIGGER �������� ON ����
--AFTER INSERT/UPDATE/DELETE
--AS 
--T-SQL�����
--�ڵ��Դ�����ʱ�������޸Ĵ���������������С��磺
CREATE TRIGGER DELS --����汾
ON S FOR DELETE 
AS
DECLARE @DEPT VARCHAR(20)
SELECT @DEPT=DEPT FROM INSERTED
IF @DEPT='CS'
BEGIN
	PRINT 'YOU CAN NOT DELETE THE STUDENT FROM CS'
	ROLLBACK
END
--ִ������Ĵ����������ִ������޸Ĵ�������
ALTER TRIGGER DELS --��ȷ�汾
ON S FOR DELETE 
AS
DECLARE @DEPT VARCHAR(20)
SELECT @DEPT=DEPT FROM DELETED
IF @DEPT='CS'
BEGIN
	PRINT 'YOU CAN NOT DELETE THE STUDENT FROM CS'
	ROLLBACK
END
--ɾ��������(DROP TRIGGER ����.��������)
DROP TRIGGER S.DELS
--ʵ��9�����ʵ��
--1)�� S ��� PRIMARY KEY ������Լ��ɾ������дһ�� S ���ϵĴ������������S
--���ϲ����¼ʱʵ������Ŀ�꣺SNO ����Ϊ�գ��� SNO �����ظ�
alter table s drop constraint pk_s --TODO:pk_s�ĳ�s��������Լ����ʵ������
create trigger s_insert_action
on s for insert 
as 
begin 
	if exists(select * from s inserted where sno is null) --��� SNO �Ƿ�Ϊ��
	begin 
		print 'ѧ�Ų���Ϊ��!'
		rollback tran
		return 
	end
	if exists(select * from s inner join inserted on s.sno=inserted.sno)--���SNO�Ƿ��ظ�
	begin 
		print 'ѧ�Ų����ظ�!'
		rollback tran
		return 
	end
end
--2)��C���޸ļ�¼ʱ�����޸ĵ��� CREDIT �ֶ�,���޸�ֵ����6ʱ��ʾ������Ϣ���������д�����ݱ�
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
--ʵ��10(���ݿⰲȫ�����ݿ�ָ�)��֤��ʵ��(ȫ���ֶ�����)

--ʵ��11--���ݿ����(��E-Rͼ����,�����ڴ˲���)
