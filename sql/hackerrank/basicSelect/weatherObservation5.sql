select CITY, length(CITY) 
from STATION
order by length(CITY) ASC, CITY ASC
LIMIT 1;
select CITY, length(CITY) 
from STATION
order by length(CITY) DESC, CITY ASC
LIMIT 1;