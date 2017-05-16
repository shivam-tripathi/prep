-- http://www.sqlexamples.info/PHP/mysql_rlike.htm
-- https://www.experts-exchange.com/questions/26290493/Mysql-LIKE-vs-RLIKE.html

select distinct CITY 
from STATION 
where 
CITY rlike "^[aeiou].*$";

-- Can use like 

select distinct CITY 
from STATION 
where 
CITY like "a%" || CITY like "e%" || CITY like "i%" || CITY like "o%" || CITY like "u%";

-- Can use left

select distinct CITY 
from STATION 
where 
left(CITY, 1) = 'a' or left(CITY, 1) = 'e' or left(CITY, 1) = 'i' or left(CITY, 1) = 'o' or left(CITY, 1) = 'u';