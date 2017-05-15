select * 
from CITY 
where (POPULATION > 100000) and (COUNTRYCODE = 'USA');

-- = is much faster than like, but you can use like for wildcards