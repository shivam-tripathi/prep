select ROUND(SUM(LAT_N),2), ROUND(SUM(LONG_W), 2)
from STATION
where LAT_N is not null and LONG_W is not null;