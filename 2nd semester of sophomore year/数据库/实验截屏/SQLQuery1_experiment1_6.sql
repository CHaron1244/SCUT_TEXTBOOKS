--ʵ���:�����͹������ݿ�
CREATE DATABASE LMS
--ʵ����:���������ݲ���
--(һ):��ҵ��������ʹ��--->�ⲿ�����ֶ�����
--(��):��ѯ������ʹ��
USE LMS
CREATE TABLE student(
SNO VARCHAR(10) NOT NULL,
SNAME VARCHAR(20) NOT NULL,
SEX CHAR(2),
BIRTHDAY DATETIME)
insert into student
values('200512','Josephine','F','1980-12-20')
--ʵ���������ʵ��
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
VALUES('200512','����','�����ϵ',20,'��'),
('200518','����','�����ϵ',19,'Ů'),
('200018','����','��ѧϵ',18,'Ů'),
('200511','����','����ϵ',20,'��'),
('200510','����','��Ϣϵ',19,'��'),
('200513','����','����ϵ',19,'��'),
('200514','�����','��Ϣϵ',19,'Ů'),
('200012','ŷ����','��ѧϵ',20,'��'),
('200515','������','��ѧϵ',23,'Ů')
INSERT INTO C
VALUES('c01','���ݿ�ԭ��','c03',4),
('c02','��Ϣϵͳ','c01',4),
('c03','���ݽṹ',NULL,6),
('c04','DB_���','c01',3)
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
--ʵ����(�����ѯ)�������ʵ��
--1)��������ѯȫ������
USE LMS
select * from s
--2)�� SELECT �ؼ��ֺ�ָ��Ҫ����������
select sno,sname from s --��ѯS���ѧ��ѧ�ź�����
select dept from s --��ѯS���е�ϵ����
select distinct dept from s --��ѯS���в��ظ���ϵ����
--3)�ı��б���ļ���
select sno ѧ��,sname ���� from s
select sno as ѧ��,sname as ���� from s
--4)������ѡ��Ĳ�ѯ
select * from s where dept='��Ϣϵ' --��S���������Ϣϵ����ѧ����Ϣ
select * from s where sname like '��%' --��S���м����ա�������ѧ����Ϣ
select sno,cno from sc where cno='c01' and score is null --��SC�������C01��ѡ�޿γɼ�Ϊ�յ�ѡ�μ�¼
select sno,sname from s where age in (21,18,22) --��������Ϊ21��18��22��ѧ��ѧ�š�����
select sno,sname from s where age=18 or age=21 or age=22 --������һ��ȼ�
--5)ʹ�þۼ�����
select max(score), avg(score),min(score) from sc
select max(score), avg(score),min(score) from sc where cno='c01' --��ѯ��C01���γ̵���߷֡�ƽ���ֺ���С�ɼ�
--6)�Լ��������������
select * from sc
where score is null
order by sno,cno desc
--7)���з���ͳ��
select sno,count(*) from sc group by sno --��ѯ��ѧ����ѡ����
select sno,count(*) from sc group by sno having count(*) >=3  --ѡ�α��в�ѯѡ����3 �����Ͽγ̵�ѧ��ѧ��
select sno ѧ��,avg(score) ƽ���� from sc group by sno order by ƽ���� desc  --ѡ�α��а�ѧ�ŷ������ѧ����ƽ���֣�����ƽ���ֽ�������
select sno from sc
order by sno
go
select sno from sc
group by sno
--ʵ���ĵ������ʵ��!
select sno,sname from s where dept='�����ϵ' --1��ѯ�����ϵѧ����ѧ�ź�������
select distinct sno from sc --2��ѯѡ���˿γ̵�ѧ��ѧ��
--3��ѯѡ�� C01 �γ̵�ѧ��ѧ�źͳɼ�����Ҫ��Բ�ѯ������ɼ��Ľ�������
--����ɼ���ͬ��ѧ�ŵ���������
select sno,score from sc where cno='c01'order by score desc,sno asc 
select cno �Լ����ѯ�Ŀγ�,avg(score) from sc group by cno --4��ѯÿ�ſγ̵�ƽ����
select count(cno) from c --5��ѯѧУ����Ŀγ�����
select sno from sc group by sno having count(cno) >= 2 --6��ѯѡ�����ż��������Ͽγ̵�ѧ��ѧ��
select sno,sname,dept from s where age>=20 and age<=22 and sex='��' --7��ѯ������ 20-22 ֮���������ѧ�š�������ϵ��
select count(*) from sc where cno='c01' --8��ѯѡ�ޡ�C01���γ̵�ѧ������
--ʵ����(����ѯ)����֤��ʵ��
--1)�������Ӳ�ѯ
select * from c,sc
--2)��ĵ�ֵ���Ӳ�ѯ
select sno,cname,score from c,sc where c.cno=sc.cno --��ѯ��ѧ����ѡ����Ϣ������ѧ�š��γ������ɼ���
select s.sno,sname,cno,score from s,sc where s.sno=sc.sno --��ѯѧ����ѡ�μ�¼����ʾѧ����ѧ�š��������γ̺š��ɼ���
select s.sno,sname,sc.cno,cname,score from s,sc,c where s.sno=sc.sno and sc.cno=c.cno --��ѯѧ����ѡ�μ�¼����ʾѧ����ѧ�š��������γ̺š��γ������ɼ�
insert into s(sno,sname) values('20000','ZXX')--�������Ӳ�ѯ����ϣ�������һ�ű������м�¼ȫ����ʾ����ʱ����Ҫ���������Ӳ���
select s.sno,sname,cno,score from s left outer join sc on s.sno=sc.sno
--3)�����������
select s1.sno from s as s1,s as s2 where s1.dept=s2.dept and s2.sname='����' --��ѯ�롯���¡�ͬϵ��ѧ��ѧ��
select sno,cno,score from sc as sc1 where score < (select max(score) from sc as sc2 where sc2.sno=sc1.sno) --��ʾÿ��ѧ���ķ���߷ֳɼ�
--4)IN Ƕ���Ӳ�ѯ
--����ص�IN �Ӳ�ѯ���Ӳ�ѯ���Ե���ִ�У��뱻Ƕ�׵Ĳ�ѯ�޹ء�
--�磬��ѯ�롯���¡�ͬϵ��ѧ��ѧ��
select sno
from s
where dept in(select dept	
			  from s
			  where sname='����')
select count(*) from sc --��ѯ�����ݿ�ԭ���γ̵�ѡ������
where cno in(select cno 
			 from c
			 where cname='���ݿ�ԭ��')
--��ص��Ӳ�ѯ���Ӳ�ѯ��Ҫ�õ�����ѯ�����Ϣ���Ӳ�ѯ���ܶ���ִ�С�
--�磬��ѯѡ�޿γ̺�Ϊ��C01���γ��ҳɼ����ٸ���ѡ�޿γ̺�Ϊ��C02����ͬѧ��Cno��Sno��SCORE
select cno,sno,score 
from sc as sc1
where cno='c01' and score>(select score
							from sc as sc2
							where sc2.sno=sc1.sno and sc2.cno='c02')
--5)EXISTS Ƕ���Ӳ�ѯ
select sno,sname from s where exists(select * from sc where cno='c03') 
go 
select sno,sname from s  
insert into c values('c06','���ݿⰲȫ',NULL,3)
select sno,sname from s where exists(select * from sc where cno='c03')
select count(*) from sc where exists(select * from c where c.cno=sc.cno and cname='���ݿ�ԭ��')  --��ѯ�����ݿ�ԭ���γ̵�ѡ������
--ʵ���������ʵ��
select score from sc,s where sc.sno=s.sno and s.dept='�����ϵ' --1��ѯ�������ϵ��ѧ�����̿γ̵ĳɼ���
select sc1.sno ����,score from sc as sc1 where score < (select avg(score) from sc as sc2) --2��ѯ�ɼ��ȸÿγ�ƽ���ɼ��͵�ͬѧ�ĳɼ���
select sno,cno,score from sc where cno='c01' order by cno desc,score asc --3��ѯѡ�� C01 �γ̵�ѧ��ѧ�š��γ������ɼ�����Ҫ��Բ�ѯ�����ѧ�ŵĽ������У����ѧ����ͬ�򰴳ɼ�����������
select sc.sno ѧ��,sname ���� from s,sc where s.sno=sc.sno group by sc.sno,sname having count(sc.cno)>=2 --4��ѯѡ�����ż��������Ͽγ̵�ѧ��ѧ�ż�����
select c.cno from s,sc,c where s.age>=20 and s.age<=22 and s.sex='��' and sc.sno=s.sno and sc.cno=c.cno --5��ѯ������ 20-22 ֮���������ѡ�޵Ŀγ̺�
select count(*) from sc,c where sc.cno=c.cno and c.cname='���ݽṹ' --6��ѯѡ�ޡ����ݽṹ���γ̵�ѧ������
select s.sno,s.sname from s where exists(select * from sc sc1 where s.sno=sc1.sno and sc1.score>=80) and not exists(select * from sc sc2 where s.sno=sc2.sno and sc2.score<80) --7��ѯÿ��ѡ�γɼ��� 80 �����ϵ�ѧ��ѧ�š�����
--ʵ����(���ݲ���������)����֤��ʵ��
--1)���ݵĲ���
use lms  -- ����¼�Ĳ���
go
select * from s 
insert into s(sno,sname) values('200300','Paulwen')
select * from s
create table sbak(  --���¼�Ĳ���
sno varchar(10) not null,
sname varchar(20),
dept varchar(20),
age int,
sex char(4))
go 
select * from sbak
insert into sbak (select * from s) 
select * from sbak
--2)���ݵ�ɾ��
create table cbak(
cno varchar(10) not null,
csname varchar(20),
cpno varchar(10),
credit int)
go
insert into cbak select * from c 
delete from cbak where credit<4 
select * from cbak
--3)���ݵ��޸�
select * from s
update s set dept='cs' where dept='�����ϵ'
go
select * from s
--4)�����Ľ���
--�����Ǿ�������
select * from c  
go 
create index icname on c(cname)
go 
select * from c  --�����ݱ�
select * from c(index=icname) --�������������ݱ�
--������������
select * from c 
go 
create clustered index cicno on c(cno)
go
select * from c
--����Ψһ����
create unique index uisno on sc(sno)
--create unique index uisno on sc(sno,cno desc)
--������������
select * from s
go
create index iagesno on s(age desc,sno)
go
select * from s
select * from s(index=iagesno)
--�鿴���е�����
sp_helpindex 's'
--ɾ�����е�����
drop index s.iagesno
go
sp_helpindex 's'
--5)��ͼ�������
--view creation
create view showsno
as 
select s.sno,sname,avg(score) as ƽ���ɼ�
from s,sc
where s.sno=sc.sno
group bu s.sno,sname
go
select * from showsno
CREATE VIEW VISDEPT ---������Ϣϵѧ������ͼ
AS 
SELECT * FROM S WHERE DEPT='��Ϣϵ'
--����ͼ���޸�����
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
--����ͼ��ɾ������
select * from visdept
delete from  visdept where sex='Ů'
select * from visdept 
select * from s
--ʵ��6�����ʵ�� 
--1) �� S ��ϵ��Ϊ�������ϵ��ѧ����Ӧ��ϵ����Ϊ��CS��
update s set dept='CS' where dept='�����ϵ'
--2) ����һ���� SC ����ͬ�����ݱ� SCNEW����ѯ SC ���гɼ�Ϊ�յļ�¼�����临�Ƶ� SCNEW ���С� 
CREATE TABLE SCNEW(
SNO VARCHAR(10) NOT NULL,
CNO VARCHAR(10) NOT NULL,
SCORE DECIMAL)
insert into scnew select * from sc where score=NULL
select * from scnew
--3) ɾ�� SC ���гɼ�Ϊ�յ�ѡ�μ�¼
delete from sc where score=null
--4) ���� S ���������ֶν���Ψһ������
create unique index sname_index on s(sname)
--5) ���� S ���� SNO �ľ�������
create clustered index sno_index on s(sno)
--6) ���� SC ���ϸ��� SNO ����CNO ����ĸ�������
create index sno_cno_index on  sc(sno asc,cno desc)
--7) ����ÿ�ſγ̵Ŀγ̺š��γ�����ѡ��������ƽ���ֵ���ͼ(����Ҳû����)
create view course_view 
as 
select sc.cno �γ̺�,cname �γ���, count(*) ѡ������,avg(score) ƽ����
from c,sc
where c.cno=sc.cno
group by sc.cno,cname