select CITY 
from STATION 
where ID % 2 = 0 
group by CITY;

-- You have to put the attribute in the group by clause in the select command directly or inside an aggregate function 
