CREATE TYPE contact AS OBJECT (
	email varchar2(30),
	zip varchar2(10),
	city VARCHAR2(10),
	address VARCHAR2(20),
	ph_number VARCHAR2(20))
NOT FINAL;

CREATE or replace type person_typ AS OBJECT (
  idno           NUMBER,
  name           VARCHAR2(30),
  person_contact        contact, --- complex object type contact
  MAP MEMBER FUNCTION get_idno RETURN NUMBER
  NOT FINAL;
/

CREATE TYPE BODY person_typ AS
  MAP MEMBER FUNCTION get_idno RETURN NUMBER IS
  BEGIN
    RETURN idno;
  END;
END;
/

CREATE TYPE course AS OBJECT (
	code VARCHAR2(10),
	credit number,
	name VARCHAR2(50))
NOT FINAL;
/

CREATE OR REPLACE TYPE course_type AS TABLE OF course;
/

CREATE TYPE student_typ UNDER person_typ ( 
    dept_id NUMBER, 
    major VARCHAR2(30), 
	course_list course_type) not final; 

CREATE TABLE student_obj_typ of student_typ 
NESTED TABLE course_list STORE AS course_list_nt;


INSERT INTO student_obj_typ VALUES (
 --invoking default constructor 
 student_typ(51, 'Anthony R. Almaguer',
 contact('AnthonyRAlmaguer@armyspy.com','63101', 'Las Vegas','2099 Hall Street',
 '702-501-1886'),12, 'HISTORY', 
 course_type ( 
    --collection of course list
    course('144010',3,'Four Years Old') 
 )))
 
INSERT INTO student_obj_typ VALUES (student_typ(10, 'Olive R. French',  
 contact('OliveRFrench@dayrep.com','35222', 'Birmingham','4939 Ritter Street',
 '256-282-1016'), 12, 'English', 
  course_type ( 
    --collection of course list
    course('200930',2,'K. Physical Education')
  )));
  
INSERT INTO student_obj_typ VALUES (student_typ(19, 'Robert B. Dupree',  
contact('OliveRFrench@dayrep.com','33169', 'Miami','3012 Tyler Avenue','305-357-2824') 
, 1, 'English',
--create multiple course list 
course_type ( 
    course('200930',2,'Physical Education'), 
    course('200820',2,'Health and Safety'), 
    course('200920',2,'Tools for Learning') 
) 
))

SELECT 
ot.get_idno() as Id,  ot.name as "Full Name", 
ot.person_contact.email as "Email", ot.person_contact.city as "City",
ot.person_contact.zip as "Zip", ot.person_contact.ph_number as "Phone Number",
course.name as "Course Name",  course.code as "Course Code",  course.credit as "Course Credit" 
FROM student_obj_typ ot, table(ot.course_list) course;
