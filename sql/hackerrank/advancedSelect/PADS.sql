-- http://www.w3resource.com/sql/aggregate-functions/count-with-group-by.php
-- http://www.w3resource.com/sql/aggregate-functions/count-having.php
-- http://www.w3resource.com/sql/aggregate-functions/count-with-distinct.php

select concat (Name, "(", left(Occupation, 1), ")") 
from OCCUPATIONS 
order by Name;

SELECT concat('There are total ', count(*), ' ', LOWER(occupation), 's.')
FROM occupations
GROUP BY occupation
ORDER BY COUNT(*), occupation;

-- In the second query, even after using group by we have to order by occupation again, as order by count is messing up the ordering
